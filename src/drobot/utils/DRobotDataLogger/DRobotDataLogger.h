#ifndef _DROBOT_DATA_LOGGER_H_
#define _DROBOT_DATA_LOGGER_H_

#include <iostream>
#include <fstream>

#include <stdio.h>
#include <stdarg.h>

namespace drobot {

class DRobotDataLogger {
public:
	/* to log to stdout/stderr */
	DRobotDataLogger(const char *filename);

	~DRobotDataLogger() { _file.close(); }

	void log(const int step, const size_t size, const double *values);
	void log(const int step, const size_t size, const double value, ...);
	void log(const int step, const double value);

	void log(const int step, const size_t size, const int *values);
	void log(const int step, const size_t size, const int value, ...);
	void log(const int step, const int value);

private:
	std::ofstream _file;
};

}

#endif /* _DROBOT_DATA_LOGGER_H_ */
