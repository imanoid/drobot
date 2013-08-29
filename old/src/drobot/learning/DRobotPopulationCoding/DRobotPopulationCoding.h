
#ifndef _DROBOT_DROBOTPOPULATIONCODING_H_
#define _DROBOT_DROBOTPOPULATIONCODING_H_

#include <string>
#include <vector>

#include <eigen3/Eigen/Core>

//#include <boost/numeric/ublas/vector.hpp>
//#include <boost/numeric/ublas/matrix.hpp>

namespace drobot {

class DRobotPopulationCoding
{

public:

	static double
	decodePopulationActivity1D(double* population, int size, double min, double max );


};

}


#endif
