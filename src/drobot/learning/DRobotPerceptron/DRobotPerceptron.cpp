#include <iostream>
#include <ctime>
#include <cstdlib>

#include "DRobotPerceptron.h"

namespace drobot {

DRobotPerceptron::DRobotPerceptron(int nInputs, int nOutputs) {

	this->nInputs = nInputs;
	this->nOutputs = nOutputs;

	weights = Eigen::MatrixXd(nOutputs, nInputs);
	outputs = Eigen::VectorXd(nOutputs);
	inputs = Eigen::VectorXd(nInputs);

}

DRobotPerceptron::DRobotPerceptron(std::vector<std::string> inputNodes,
		std::vector<std::string> outputNodes) {
	this->inputNodes = inputNodes;
	this->outputNodes = outputNodes;

	int nInputs = inputNodes.size();
	int nOutputs = outputNodes.size();

	this->nInputs = nInputs;
	this->nOutputs = nOutputs;

	weights = Eigen::MatrixXd(nOutputs, nInputs);
	outputs = Eigen::VectorXd(nOutputs);
	inputs = Eigen::VectorXd(nInputs);
}

DRobotPerceptron::~DRobotPerceptron() {

}

void DRobotPerceptron::updateWeights(double reward, double lRate) {

	// Oja rule

	for (int i = 0; i < nInputs; i++) {
		for (int j = 0; j < nOutputs; j++) {
			weights(i, j) = weights(i, j)
					+ lRate * outputs(j)
							* (inputs(i) - outputs(j) * weights(i, j) * reward);
		}
	}

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

double*
DRobotPerceptron::calculateOutput(double* input) {
	inputs = Eigen::Map < Eigen::VectorXd > (input, nInputs);
	outputs = weights * inputs;

	return outputs.data();
}

void DRobotPerceptron::initWeights(double** weights) {

	for (int i = 0; i < nOutputs; i++) {
		for (int j = 0; j < nInputs; j++) {
			this->weights(i, j) = weights[i][j];
		}
	}
}

void DRobotPerceptron::initWeights(double min, double max) {
	srand((unsigned) time(0));

	for (int i = 0; i < nOutputs; i++) {
		for (int j = 0; j < nInputs; j++) {
			weights(i, j) = min + ((double) rand() / RAND_MAX) * (max - min);
		}
	}

}

double**
DRobotPerceptron::getWeights() {

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

}
