
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
	static const unsigned int AVG_HISTORY = 20;

	enum learn_rule_t {
		/* Oja's rule with reward factor */
		LEARN_OJA,
		/* Hebbian Covariance */
		LEARN_HEBBIAN_COVARIANCE,
		/* McMillen et al. 2011, formula (11) */
		LEARN_MCMILLEN,
	};

	DRobotPerceptron(learn_rule_t lrule, int nInputs, int nOutputs);
	DRobotPerceptron(learn_rule_t lrule, std::vector<std::string> inputNodes, std::vector<std::string> outputNodes);

	virtual ~DRobotPerceptron();

	void updateWeights(double reward, double lRate, int start, int end);
	void updateWeights(double reward, double lRate);
	void updateWeightsWTA(double reward, double lRate, int neighbors);

	std::map<std::string, double>
	mappedOutput(std::map<std::string, double> input);

	double *calculateOutput(double *input);
	double *calculateOutputSigmoid(double *input, double beta = 0.3);
	double *calculateOutputThreshold(double *input, double thresh = 0.5);

	void initWeights(double** matrix);
	void initWeights(double min, double max);

	double* getWeights();
	double* getWeightsIn(int i);
	double* getWeightsOut(int i);

	void printWeights();
	void printWeightStats();
private:
	Eigen::MatrixXd weights;
	Eigen::VectorXd inputs;
	Eigen::MatrixXd inputsAvg;
	Eigen::VectorXd outputs;
	Eigen::MatrixXd outputsAvg;

	int nInputs;
	int nOutputs;

	unsigned int i_avg;

	learn_rule_t _lrule;

	std::vector<std::string> inputNodes;
	std::vector<std::string> outputNodes;

	Eigen::VectorXd sigmoid(Eigen::VectorXd h, double beta);
	Eigen::VectorXd threshold(Eigen::VectorXd h, double thresh);
};

}

#endif
