#include <sys/time.h>
#include <stdarg.h>

#include <boost/filesystem.hpp>

#include "DRobotDataLogger.h"

namespace drobot {

DRobotDataLogger::DRobotDataLogger(const char *dir, const char *file)
{
	boost::filesystem::path p(dir);

	if (!boost::filesystem::exists(p)) {
		if (!boost::filesystem::create_directory(p)) {
			std::cerr << "Error: couldn't create log file directory" << std::endl;
			throw "";
		}
	}

	if (!boost::filesystem::is_directory(p)) {
		std::cerr << "Error: log file directory is not a file" << std::endl;
		throw "";
	}

	p /= file;

	_file.open(p.c_str());

	if (!_file.is_open()) {
		std::cerr << "Error: failed to open file " << p.c_str() << ": " << strerror(errno) << std::endl;
		throw "";
	}

	_file.precision(10);
}

void DRobotDataLogger::header(const size_t size, const char *names[])
{
	_file << "time";

	for (size_t i = 0; i < size; i++) {
		_file << "," << names[i];
	}

	_file << std::endl;
}

void DRobotDataLogger::header(const size_t size, const char *name, ...)
{
	va_list ap;

	_file << "time," << name;

	va_start(ap, name);
	for (size_t i = 1; i < size; i++) {
		char *val = va_arg(ap, char *);
		_file << "," << val;
	}
	va_end(ap);

	_file << std::endl;
}

void DRobotDataLogger::log_time(const struct timeval *t)
{
	char buf[256];

	snprintf(buf, sizeof(buf), "%ld.%06lu", t->tv_sec, t->tv_usec);

	_file << buf;
}

void DRobotDataLogger::log(const struct timeval *t, const size_t size, const double *values)
{
	log_time(t);

	for (size_t i = 0; i < size; i++) {
		_file << "," << values[i];
	}

	_file << std::endl;
}

void DRobotDataLogger::log(const struct timeval *t, const size_t size, const double value, ...)
{
	va_list ap;

	log_time(t);

	_file << "," << value;

	va_start(ap, value);
	for (size_t i = 1; i < size; i++) {
		double val = va_arg(ap, double);
		_file << "," << val;
	}
	va_end(ap);

	_file << std::endl;
}

void DRobotDataLogger::log(const struct timeval *t, const double value)
{
	log_time(t);

	_file << "," << value << std::endl;
}

void DRobotDataLogger::log(const struct timeval *t, const size_t size, const int *values)
{
	log_time(t);

	for (size_t i = 0; i < size; i++) {
		_file << "," << values[i];
	}

	_file << std::endl;
}

void DRobotDataLogger::log(const struct timeval *t, const size_t size, const int value, ...)
{
	va_list ap;

	log_time(t);

	_file << "," << value;

	va_start(ap, value);
	for (size_t i = 1; i < size; i++) {
		int val = va_arg(ap, int);
		_file << "," << val;
	}
	va_end(ap);

	_file << std::endl;
}

void DRobotDataLogger::log(const struct timeval *t, const int value)
{
	log_time(t);
	_file << "," << value << std::endl;
}

}
