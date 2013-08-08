#ifndef _DROBOT_DATA_LOGGER_H_
#define _DROBOT_DATA_LOGGER_H_

#include <iostream>
#include <fstream>

#include <stdio.h>
#include <stdarg.h>

#include <boost/shared_ptr.hpp>

namespace drobot {

class DRobotDataLogger {
public:
	/* to log to stdout/stderr */
	DRobotDataLogger(const char *dir, const char *file);

	~DRobotDataLogger() { _file.close(); }

	void header(const size_t size, const char *names[]);
	void header(const size_t size, const char *name, ...);

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

typedef boost::shared_ptr<DRobotDataLogger> DRobotDataLoggerPtr;

}

#endif /* _DROBOT_DATA_LOGGER_H_ */
