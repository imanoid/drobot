
#ifndef _DROBOT_DROBOTPERCEPTRON_H_
#define _DROBOT_DROBOTPERCEPTRON_H_

#include <string>
#include <vector>
#include <map>

//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>

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

	double*
	calculateOutput(double* input);

	void
	initWeights(double** matrix);

	void
	initWeights(double min, double max);

	double**
	getWeights();

	void
	printWeights();

private:

	Eigen::MatrixXd weights;
	Eigen::VectorXd inputs;
	Eigen::VectorXd outputs;

	int nInputs;
	int nOutputs;

	std::vector<std::string> inputNodes;
	std::vector<std::string> outputNodes;
};

}


#endif
