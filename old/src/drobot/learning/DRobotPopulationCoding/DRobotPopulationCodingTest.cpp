

#include <iostream>

#include <boost/assign/list_of.hpp>

#include "DRobotPopulationCoding.h"


int main(int argc, char *argv[])
{

	double min = 10;
	double max = 20;

	double input[] = {0,0,0,2,2};

	double response = drobot::DRobotPopulationCoding::decodePopulationActivity1D(input, 5, min, max);

	std::cout << "Population coding: " << response << std::endl;

}


