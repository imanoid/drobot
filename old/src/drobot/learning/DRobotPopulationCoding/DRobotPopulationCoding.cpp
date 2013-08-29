
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "DRobotPopulationCoding.h"

namespace drobot
{

double DRobotPopulationCoding::decodePopulationActivity1D(double *population, int size, double min, double max)
{
	double out = 0;
	double sum = 0;
	double oInterval = ((double) (max - min)) / (double) (size - 1);

	for (int i = 0; i < size; i++) {
		double p = population[i];
		sum += p;
		out += (min + i * oInterval) * p;
	}

	if (sum != 0)
		return out / sum;
	else
		return 0.0;
}

}
