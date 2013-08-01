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

	void log(const struct timeval *t, const size_t size, const double *values);
	void log(const struct timeval *t, const size_t size, const double value, ...);
	void log(const struct timeval *t, const double value);

	void log(const struct timeval *t, const size_t size, const int *values);
	void log(const struct timeval *t, const size_t size, const int value, ...);
	void log(const struct timeval *t, const int value);

private:
	char _separator;
	std::ofstream _file;

	void init(const char *prefix, char separator);
	void log_time(const struct timeval *t);
};

}

#endif /* _DROBOT_DATA_LOGGER_H_ */
