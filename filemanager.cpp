#include "FileManager.h"
#include "Stringify.h"

#include <sys/param.h>
#include <dirent.h>
#include <stdio.h>

bool FileManager::SetContents(std::string Filename, std::string Content, bool Relative) {
    if(Filename == "") return false;

    if(Relative) Filename = GetCWD() + DIR_SEPARATOR + Filename;

    std::ofstream FileHandle;

    FileHandle.open(Filename.c_str());
    if(!FileHandle.is_open()) return false;

    FileHandle << Content;
    FileHandle.close();

    return true;
}

std::string FileManager::GetContents(std::string Filename, bool Relative) {
    if(Filename == "") return "";

    if(Relative) Filename = GetCWD() + DIR_SEPARATOR + Filename;

    std::string Content;
    std::ifstream FileHandle;

    FileHandle.open(Filename.c_str());

    if(FileHandle.is_open()) {
        while(FileHandle.good()) {
            std::string Buffer;
            getline(FileHandle, Buffer);
            if(Buffer == "") continue;

            Content += Buffer + "\n";
        }

        FileHandle.close();
    }

    return Content;
}

std::vector<std::string> FileManager::GetFilesInFolder(std::string Folder) {
    std::vector<std::string> List;

    std::string CWD  = GetCWD();
    std::string Path = CWD;

    if(Folder != "") Path += DIR_SEPARATOR + Folder;

    DIR* DirHandle = NULL;
    dirent* FileHandle = NULL;

    // Needs improved
    if((DirHandle = opendir(Folder.c_str())) != NULL)
    {
        while((FileHandle = readdir(DirHandle)) != NULL)
        {
            if(std::string(FileHandle->d_name) == ".")  continue;
            if(std::string(FileHandle->d_name) == "..") continue;

            std::string Filename = Path + DIR_SEPARATOR + FileHandle->d_name;

            List.push_back(Filename);
        }

        closedir(DirHandle);

    }
    else
    {
        std::cout << "Unable to open directory : " << Path.c_str() << std::endl;
    }

    return List;
}

std::string FileManager::GetCWD() {
    std::string CWD;

    char Buffer[MAXPATHLEN];
    CWD = (getcwd(Buffer, MAXPATHLEN) ? std::string(Buffer) : std::string(""));

    return CWD;
}

std::string FileManager::GetFilenameWithoutExt(std::string Filename) {
    std::vector<std::string> Parts = Stringify::Tokenise(Filename, DIR_SEPARATOR);
    std::string NewFilename = Parts[Parts.size() - 1];

    // To Do: Filename could potentially have one or more dots
    Parts		= Stringify::Tokenise(NewFilename, ".");
    NewFilename	= Parts[0];

    return NewFilename;
}

std::string FileManager::GetFilenameExt(std::string Filename) {
    std::vector<std::string> Parts = Stringify::Tokenise(Filename, ".");

    return (Parts.size() <= 1 ? "" : Parts[Parts.size() - 1]);
}