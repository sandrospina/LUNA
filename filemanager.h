#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h>

#define DIR_SEPARATOR "/"

class FileManager {
public:
    static bool SetContents(std::string Filename, std::string Content, bool Relative = true);

    static std::string GetContents(std::string Filename, bool Relative = true);

    static std::vector<std::string> GetFilesInFolder(std::string Folder);

    static std::string GetCWD();

    static std::string GetFilenameWithoutExt(std::string Filename);

    static std::string GetFilenameExt(std::string Filename);
};