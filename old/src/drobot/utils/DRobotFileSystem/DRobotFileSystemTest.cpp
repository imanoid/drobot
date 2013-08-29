
#include <boost/thread.hpp>

#include <QApplication>
#include <QDialog>
#include <QWidget>
#include <math.h>
#include "DRobotFileSystem.h"



int main(int argc, char *argv[])
{

	std::vector<std::string> files = drobot::DRobotFileSystem::getDirectoryList("/");

	for(int i=0; i<files.size(); i++)
	{
		std::cout << files[i] << std::endl;
	}

	return 0;

}
