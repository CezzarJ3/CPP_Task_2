#ifndef CPP_TASK_2_FILESYSTEMMODELING_H
#define CPP_TASK_2_FILESYSTEMMODELING_H

#include "FileSystem.h"

class FileSystemModeling {
public:
    FileSystemModeling();

    ~FileSystemModeling();

    void start();

private:
    FileSystem *_fileSystem;

    static void printMenu();

    void createFile();

    void createDir();

    void createSymbolicLink();

    void createHardLink();

    void deleteElement();

    void moveElement();

    void renameElement();
};


#endif //CPP_TASK_2_FILESYSTEMMODELING_H
