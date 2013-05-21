
#ifndef DROBOT_DROBOTFILESYSTEM_H
#define DROBOT_DROBOTFILESYSTEM_H

#include <vector>
#include <string>

namespace drobot
{
  class DRobotFileSystem
  {
    public:
    
      static int
      getSubdirectoryFileList(std::string root, std::vector<std::string>& fileList);

      static int
      getDirectory(std::string path, std::string& directory);

      static int
      getFilename(std::string path, std::string& filename);

      static bool
      fileExists(std::string path);
      
      static bool
      directoryExists(std::string path);
      
      static void
      createDirectory( std::string path );

      static void
      removeDirectory( std::string path );

      static std::vector<std::string>
      getFileList( std::string path );

      static int
      getFileCount( std::string path );

      static std::vector<std::string>
      getDirectoryList( std::string path );

      static int
      getDirectoryCount( std::string path );
      
      static std::string
      getDirectoryName( std::string path );

      static std::string
      getFileName( std::string path );

      
  };   
}
#endif
