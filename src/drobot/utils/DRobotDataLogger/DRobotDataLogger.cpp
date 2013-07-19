#include <sys/time.h>
#include <stdarg.h>

#include "DRobotDataLogger.h"

namespace drobot {

DRobotDataLogger::DRobotDataLogger(const char *prefix)
{
	char filename[FILENAME_MAX];
	struct timeval ts;
	char tbuf[128];

	gettimeofday(&ts, NULL);
	strftime(tbuf, sizeof(tbuf), "%Y-%m-%d-%H-%M-%S", localtime(&ts.tv_sec));

	snprintf(filename, sizeof(filename), "%s_%s.log", prefix, tbuf);
	_file.open(filename);

	if (!_file.is_open())
		throw "Error: Failed to open file";

	_file.precision(10);
}

void DRobotDataLogger::log(const int step, const size_t size, const double *values)
{
	_file << step << ",";
	for (size_t i = 0; i < size; i++) {
		_file << values[i];
		if (i != size - 1)
			_file << ",";
	}

	_file << std::endl;
}

void DRobotDataLogger::log(const int step, const size_t size, const double value, ...)
{
	va_list ap;

	_file << step << "," << value;

	va_start(ap, value);
	for (size_t i = 1; i < size; i++) {
		double val = va_arg(ap, double);
		_file << "," << val;
	}
	va_end(ap);

	_file << std::endl;
}

void DRobotDataLogger::log(const int step, const double value)
{
	_file << step << "," << value << std::endl;
}

void DRobotDataLogger::log(const int step, const size_t size, const int *values)
{
	_file << step << ",";
	for (size_t i = 0; i < size; i++) {
		_file << values[i];
		if (i != size - 1)
			_file << ",";
	}

	_file << std::endl;
}

void DRobotDataLogger::log(const int step, const size_t size, const int value, ...)
{
	va_list ap;

	_file << step << "," << value;

	va_start(ap, value);
	for (size_t i = 1; i < size; i++) {
		int val = va_arg(ap, int);
		_file << "," << val;
	}
	va_end(ap);

	_file << std::endl;
}

void DRobotDataLogger::log(const int step, const int value)
{
	_file << step << "," << value << std::endl;
}

}
