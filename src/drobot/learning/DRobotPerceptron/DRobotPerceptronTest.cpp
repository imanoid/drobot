

#include <iostream>

#include <boost/assign/list_of.hpp>

#include <eigen3/Eigen/Core>

#include "DRobotPerceptron.h"

double OUTPUT_MIN = 0;
double OUTPUT_MAX = 20;

int nInputs = 2;
int nOutputs = 3;
double learningRate = 0.1;


void printArray(double* array, int size);



int main(int argc, char *argv[])
{

	double** w = new double*[nOutputs];
	for (int i=0; i<nOutputs; i++)
	{
		w[i] = new double[nInputs];
	}

	for (int i=0; i<nOutputs; i++)
	{
		for (int j=0; j<nInputs; j++)
		{
			w[i][j] = 1;
		}
	}

	w[0][0] = 2;

	double* in = new double[nInputs];
	in[0] = 1;
	in[1] = 2;

	drobot::DRobotPerceptron* perceptron = new drobot::DRobotPerceptron(nInputs, nOutputs);
	perceptron->initWeights(w);
	double* out = perceptron->calculateOutput(in);

	std::cout << "Inputs: " << std::endl;
	printArray(in, nInputs);
	perceptron->printWeights();
	std::cout << "Outputs: " << std::endl;
	printArray(out, nOutputs);
	std::cout << std::endl;

}




void
printArray(double* array, int size)
{
	for(int i=0; i<size; i++)
	{
		std::cout << array[i] << ", ";
	}
	std::cout << std::endl;

}


