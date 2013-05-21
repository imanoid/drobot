
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <libgen.h>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#include "DRobotFileSystem.h"


namespace drobot
{

// TODO: we should probably change this method to use the boost library instead;

int
DRobotFileSystem::getSubdirectoryFileList(std::string root, std::vector<std::string>& fileList)
{

	std::ifstream fin;
	std::string filepath, filepath2;

	int num;
	DIR *dp, *dp2;
	struct dirent *dirp, *dirp2;
	struct stat filestat, filestat2;

	// open root directory
	dp = opendir( root.c_str() );

	if (dp == NULL)
	{
		std::cerr << "Error opening " << root << std::endl;
		return -1;
	}

	while ((dirp = readdir( dp )))
	{

		filepath = root + "/" + dirp->d_name;

		stat( filepath.c_str(), &filestat );

		if (S_ISDIR( filestat.st_mode ))
		{

			if (!std::strcmp(dirp->d_name, ".") || !std::strcmp(dirp->d_name, "..")) continue;

			// open subdirectory
			dp2 = opendir( filepath.c_str() );
			while ((dirp2 = readdir( dp2 )))
			{
				filepath2 = filepath + "/" + dirp2->d_name;
				stat( filepath2.c_str(), &filestat2 );

				// neglect directories
				if (S_ISDIR( filestat2.st_mode ) 
						|| !std::strcmp(dirp2->d_name, ".") || !std::strcmp(dirp2->d_name, "..")) continue;

				fileList.push_back(filepath2);
			}

			closedir( dp2 );

		}else std::cerr << "Error... unexpected file found in the directory containing names. The file will be neglected." << std::endl;

	}

	closedir( dp );

	return 0;
}



// TODO: we should probably change this method to use the boost library instead;
int
DRobotFileSystem::getDirectory(std::string path, std::string& directory)
{
	char str[1024];
	path.copy(str, path.length());  
	str[path.length()] = 0;
	char* dir = dirname( str );
	directory.assign(dir);
	return 0;
}


// TODO: we should probably change this method to use the boost library instead;
int
DRobotFileSystem::getFilename(std::string path, std::string& filename)
{
	char str[1024];
	path.copy(str, path.length());  
	str[path.length()] = 0;  
	char* dir = basename( str );
	filename.assign(dir);
	return 0;
}


bool
DRobotFileSystem::fileExists(std::string path)
{

//	if(!boost::filesystem::exists(path))
//		return false;

	return boost::filesystem::exists(path) && boost::filesystem::is_regular_file(path);

	//    std::ifstream file(path.c_str());
	//    return file.good();
}


bool 
DRobotFileSystem::directoryExists( std::string path )
{

//	if(!boost::filesystem::exists(path))
//		return false;

	return boost::filesystem::exists(path) && boost::filesystem::is_directory(path);

}


void
DRobotFileSystem::createDirectory( std::string path )
{
	mkdir(path.c_str(), 0777);
}

void
DRobotFileSystem::removeDirectory(std::string path)
{
	std::string command = "rm -rf " + path;
	system(command.c_str());
}

std::vector<std::string>
DRobotFileSystem::getFileList( std::string path )
{
	std::vector<std::string> files;

	boost::filesystem::path directory(path);
	boost::filesystem::directory_iterator endIterator;

//	typedef std::multimap<std::time_t, fs::path> result_set_t;
//	result_set_t result_set;

	if ( directoryExists(path) )
	{
		for( boost::filesystem::directory_iterator iterator(directory) ; iterator != endIterator ; ++iterator)
		{
			if (boost::filesystem::is_regular_file(iterator->status()) )
			{
				files.push_back(iterator->path().string());
			}
		}
	}
	
	return files;
}



int
DRobotFileSystem::getFileCount( std::string path )
{
	return getFileList(path).size();
}



std::vector<std::string>
DRobotFileSystem::getDirectoryList( std::string path )
{
	std::vector<std::string> dirs;

	boost::filesystem::path directory(path);
	boost::filesystem::directory_iterator endIterator;

//	typedef std::multimap<std::time_t, fs::path> result_set_t;
//	result_set_t result_set;

	if ( directoryExists(path) )
	{
		for( boost::filesystem::directory_iterator iterator(directory) ; iterator != endIterator ; ++iterator)
		{
			if (boost::filesystem::is_directory(iterator->status()) )
			{
				dirs.push_back(iterator->path().string());
			}
		}
	}
	
	return dirs;
}



int
DRobotFileSystem::getDirectoryCount( std::string path )
{
	return getDirectoryList(path).size();
}


std::string
DRobotFileSystem::getDirectoryName( std::string path )
{
	
//	for (boost::filesystem::path::iterator it = path.begin(); it != path.end(); ++it)
//	  cout << " " << *it << '\n';

	boost::filesystem::path directory(path);		
	return directory.stem().c_str();
}


std::string
DRobotFileSystem::getFileName( std::string path )
{
	boost::filesystem::path file(path);	
	return file.filename().c_str() ;
}

}


