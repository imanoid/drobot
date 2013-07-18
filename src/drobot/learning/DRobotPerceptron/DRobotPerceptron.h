
#ifndef _DROBOT_DROBOTPERCEPTRON_H_
#define _DROBOT_DROBOTPERCEPTRON_H_

#include <string>
#include <vector>
#include <map>

#include <eigen3/Eigen/Core>

namespace drobot {

class DRobotPerceptron
{

public:

	DRobotPerceptron(int nInputs, int nOutputs );

	DRobotPerceptron(std::vector<std::string> inputNodes, std::vector<std::string> outputNodes);

	virtual ~DRobotPerceptron( );

	void
	updateWeights(double reward, double lRate);

	std::map<std::string, double>
	mappedOutput(std::map<std::string, double> input);


	double *calculateOutput(double *input);
	double *calculateOutputSigmoid(double *input, double beta = 0.3);


	void initWeights(double** matrix);
	void initWeights(double min, double max);

	double* getWeights();

	void printWeights();
	void printWeightStats();

private:

	Eigen::MatrixXd weights;
	Eigen::VectorXd inputs;
	Eigen::VectorXd outputs;

	int nInputs;
	int nOutputs;

	std::vector<std::string> inputNodes;
	std::vector<std::string> outputNodes;

	Eigen::VectorXd sigmoid(Eigen::VectorXd h, double beta);
};

}

#endif
