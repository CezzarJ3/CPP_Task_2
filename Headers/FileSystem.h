#ifndef CPP_TASK_2_FILESYSTEM_H
#define CPP_TASK_2_FILESYSTEM_H

#include "Link.h"
#include "SystemElement.h"
#include "File.h"
#include "Dir.h"
#include "SymbolicLink.h"
#include "HardLink.h"

#include <map>
#include <iostream>
#include <string>

using namespace std;

class FileSystem {
public:
    FileSystem();

    ~FileSystem();

    void createFile(string &name, string &ext, int size, Dir *targetDir);

    void createDir(string &name, Dir *targetDir);

    void createSymbolicLink(string &name, SystemElement *linkedElement, Dir *targetDir);

    void createHardLink(string &name, SystemElement *linkedElement, Dir *targetDir);

    void showFileTree();

    void deleteFile(File *file);

    void deleteDir(Dir *dir);

    void deleteSymbolicLink(SymbolicLink *symbolicLink);

    void deleteHardLink(HardLink *hardLink);

    static void moveElement(SystemElement *elementToMove, Dir *moveFrom, Dir *moveTo);

    static void renameElement(SystemElement *systemElement, string &newName);

    vector<Dir *> getDirectories();

    void printDirectories();

    vector<SystemElement *> getElements();

    void printElements();

    SystemElement *getElementById(int id);

private:
    map<Link *, SystemElement *> _listOfLinkedElements;
    vector<SystemElement *> _listOfElements;

    template<typename K>
    void deleteElementFromElementList(K *element);

    template<typename K>
    void deleteElementFromLinkedElementList(K *element);
};


#endif //CPP_TASK_2_FILESYSTEM_H
