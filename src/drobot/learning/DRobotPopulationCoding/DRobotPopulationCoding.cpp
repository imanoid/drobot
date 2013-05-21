
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "DRobotPopulationCoding.h"

namespace drobot
{


double
DRobotPopulationCoding::decodePopulationActivity1D (double* population, int size, double min, double max )
{

		double oInterval = ((double) (max - min)) / (double) (size-1);

		double out = 0;
		double sum = 0;

		for (int i=0; i<size; i++)
		{
			sum += population[i];
			out += (min + i * oInterval) * population[i];
		}

		return out / sum;
}



}
