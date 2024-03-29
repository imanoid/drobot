#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

#include "DRobotPerceptron.h"

namespace drobot {

DRobotPerceptron::DRobotPerceptron(learn_rule_t lrule, int nInputs, int nOutputs)
{
	this->nInputs = nInputs;
	this->nOutputs = nOutputs;
	this->_lrule = lrule;

	weights = Eigen::MatrixXd(nOutputs, nInputs);
	inputs = Eigen::VectorXd(nInputs);
	outputs = Eigen::VectorXd(nOutputs);

	inputsAvg = Eigen::MatrixXd::Zero(AVG_HISTORY, nInputs);
	outputsAvg = Eigen::MatrixXd::Zero(AVG_HISTORY, nOutputs);
	i_avg = 0;
}

DRobotPerceptron::DRobotPerceptron(learn_rule_t lrule, std::vector<std::string> inputNodes,
		std::vector<std::string> outputNodes)
{
	this->inputNodes = inputNodes;
	this->outputNodes = outputNodes;
	this->_lrule = lrule;

	int nInputs = inputNodes.size();
	int nOutputs = outputNodes.size();

	this->nInputs = nInputs;
	this->nOutputs = nOutputs;

	weights = Eigen::MatrixXd(nOutputs, nInputs);
	inputs = Eigen::VectorXd(nInputs);
	outputs = Eigen::VectorXd(nOutputs);

	inputsAvg = Eigen::MatrixXd::Zero(AVG_HISTORY, nInputs);
	outputsAvg = Eigen::MatrixXd::Zero(AVG_HISTORY, nOutputs);
	i_avg = 0;
}

DRobotPerceptron::~DRobotPerceptron() {

}

void DRobotPerceptron::updateWeights(double reward, double lRate, int start, int end)
{
	double avg_in, avg_out;
	double dw;

	for (int i = start; i <= end; i++) {
		for (int j = 0; j < nInputs; j++) {
			switch (_lrule) {
			case LEARN_OJA:
				dw = lRate * outputs(i)
						* (inputs(j) * reward - outputs(i) * weights(i, j));
				weights(i, j) += dw;
				break;
			case LEARN_HEBBIAN_COVARIANCE:
				avg_in = inputsAvg.col(j).sum() / AVG_HISTORY;
				avg_out = outputsAvg.col(i).sum() / AVG_HISTORY;
				dw = lRate * reward * (outputs(i) - avg_out) * (inputs(j) - avg_in);
				// only learn if there is presynaptic activity
//				dw = lRate * reward * (outputs(i) - avg_out) * inputs(j);
				weights(i, j) += dw;
				break;
			case LEARN_MCMILLEN:
				dw = reward * outputs(i) * inputs(j);
				weights(i, j) = (1.0 - lRate) * weights(i, j) + lRate * dw;
				break;
			case LEARN_MISTAKES:
				dw = reward * lRate;
				weights(i, j) += dw;
				if (weights(i, j) < 0.0)
					weights(i, j) = 0.0;
				else if (weights(i, j) > 1.0)
					weights(i, j) = 1.0;
				break;
			default:
				break;
			}
		}

		if (_lrule == LEARN_MCMILLEN) {
			// normalize weights
			weights.row(i) = weights.row(i) / weights.row(i).norm();
		} else if (_lrule == LEARN_HEBBIAN_COVARIANCE) {
			inputsAvg.row(i_avg) = inputs;
			outputsAvg.row(i_avg) = outputs;
			i_avg = (i_avg + 1) % AVG_HISTORY;
		}
	}
}

void DRobotPerceptron::updateWeights(double reward, double lRate)
{
	updateWeights(reward, lRate, 0, nOutputs - 1);
}

/*
 * Winner take all. Only learn weights to output with max. firing rate + opt.
 * neighbors.
 */
void DRobotPerceptron::updateWeightsWTA(double reward, double lRate, int neighbors)
{
	double max_out = 0.0;
	int i_max_out = -1;

	for (int i = 0; i < nOutputs; i++) {
		if (outputs[i] > max_out) {
			max_out = outputs[i];
			i_max_out = i;
		}
	}

	int start = std::max(0, i_max_out - neighbors);
	int end = std::min(nOutputs - 1, i_max_out + neighbors);
	updateWeights(reward, lRate, start, end);
}

std::map<std::string, double> DRobotPerceptron::mappedOutput(std::map<std::string, double> input) {
	double* arrayInput = new double[this->nInputs];

	int iInputIndex = 0;
	for (std::vector<std::string>::iterator iInputNode = this->inputNodes.begin();
			iInputNode != this->inputNodes.end(); iInputNode++) {
		arrayInput[iInputIndex] = input[*iInputNode];
	}

	double* arrayOutput = this->calculateOutput(arrayInput);
}

Eigen::VectorXd DRobotPerceptron::sigmoid(Eigen::VectorXd h, double beta)
{
	for (unsigned int i = 0; i < nOutputs; i++) {
		h(i) = 1.0 / (1.0 + exp(-2 * beta * h(i)));;
	}

	return h;
}

Eigen::VectorXd DRobotPerceptron::threshold(Eigen::VectorXd h, double thresh)
{
	for (unsigned int i = 0; i < nOutputs; i++) {
		h(i) = (h(i) >= thresh) ? 1.0 : 0.0;
	}

	return h;
}

double *DRobotPerceptron::calculateOutput(double* input)
{
	inputs = Eigen::Map < Eigen::VectorXd > (input, nInputs);
	outputs = weights * inputs;

	return outputs.data();
}

double *DRobotPerceptron::calculateOutputSigmoid(double *input, double beta)
{
	calculateOutput(input);
	outputs = sigmoid(outputs, beta);

	return outputs.data();
}

double *DRobotPerceptron::calculateOutputThreshold(double *input, double thresh)
{
	calculateOutput(input);
	outputs = threshold(outputs, thresh);

	return outputs.data();
}

void DRobotPerceptron::initWeights(double** weights) {

	for (int i = 0; i < nOutputs; i++) {
		for (int j = 0; j < nInputs; j++) {
			this->weights(i, j) = weights[i][j];
		}
		if (_lrule == LEARN_MCMILLEN) {
			// normalize weights
			this->weights.row(i) = this->weights.row(i) / this->weights.row(i).norm();
		}
	}
}

void DRobotPerceptron::initWeights(double min, double max)
{
	for (int i = 0; i < nOutputs; i++) {
		for (int j = 0; j < nInputs; j++) {
			this->weights(i, j) = min + ((double) rand() / RAND_MAX) * (max - min);
		}
		if (_lrule == LEARN_MCMILLEN) {
			// normalize weights
			this->weights.row(i) = this->weights.row(i) / this->weights.row(i).norm();
		}
	}
}

double* DRobotPerceptron::getWeights()
{
	return weights.data();
}

double* DRobotPerceptron::getWeightsIn(int i)
{
	return weights.col(i).data();
}

double* DRobotPerceptron::getWeightsOut(int i)
{
	return weights.row(i).data();
}

void DRobotPerceptron::printWeights() {
	std::cout << "Perceptron Weights: " << std::endl;

	for (int i = 0; i < nOutputs; i++) {
		std::cout << weights(i, 0);

		for (int j = 1; j < nInputs; j++) {
			std::cout << ", " << weights(i, j);
		}
		std::cout << std::endl;
	}
}

void DRobotPerceptron::printWeightStats()
{
	double min = std::numeric_limits<double>::max();
	double max = std::numeric_limits<double>::min();
	double sum = 0.0, sum_sq = 0.0;
	double avg = 0.0;
	double median = 0.0;

	for (int i = 0; i < nOutputs; i++) {
		for (int j = 0; j < nInputs; j++) {
			double w = weights(i, j);
			if (w < min)
				min = w;
			if (w > max)
				max = w;
			sum += w;
			sum_sq += w * w;
		}
	}

	avg = sum / (nOutputs * nInputs);

	std::cout << "weight stats: min " << min << ", max " << max << ", avg " << avg
		<< ", sum(w_i) " << sum << ", sum(w_i^2) " << sum_sq << std::endl;
}

}
