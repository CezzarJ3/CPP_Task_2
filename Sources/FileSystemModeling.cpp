#include <iostream>
#include "../Headers/FileSystemModeling.h"
#include "../Headers/FileSystem.h"

FileSystemModeling::FileSystemModeling() {
    this->_fileSystem = new FileSystem;
};

FileSystemModeling::~FileSystemModeling() {
    delete this->_fileSystem;
};

void FileSystemModeling::start() {

    int command = -1;
    while (command != 9) {
        printMenu();
        cout << "Your command: ";
        cin >> command;

        switch (command) {
            case 1:
                this->_fileSystem->showFileTree();
                break;
            case 2:
                createFile();
                break;
            case 3:
                createDir();
                break;
            case 4:
                createSymbolicLink();
                break;
            case 5:
                createHardLink();
                break;
            case 6:
                deleteElement();
                break;
            case 7:
                moveElement();
                break;
            case 8:
                renameElement();
                break;
            case 9:
                return;
            default:
                cout << "Wrong command, try again." << endl;
                break;
        }
    }
}

void FileSystemModeling::printMenu() {
    cout << "\nChoose menu item (type number without dot):" << endl;
    cout << "\t1. Show file tree" << endl;
    cout << "\t2. Create new file" << endl;
    cout << "\t3. Create new directory" << endl;
    cout << "\t4. Create new symbolic link" << endl;
    cout << "\t5. Create new hard link" << endl;
    cout << "\t6. Delete element" << endl;
    cout << "\t7. Move element to another directory" << endl;
    cout << "\t8. Rename element" << endl;
    cout << "\t9. End up working" << endl;
}

void FileSystemModeling::createFile() {
    cout << "Choose directory to create file" << endl;
    this->_fileSystem->printDirectories();
    cout << "Your choice: ";
    int dirId;
    cin >> dirId;
    Dir *dir = this->_fileSystem->getDirectories()[dirId - 1];

    cout << "\nEnter name, extension and size of file with space between them: ";
    string name, ext;
    int size;
    cin >> name >> ext >> size;

    this->_fileSystem->createFile(name, ext, size, dir);
}

void FileSystemModeling::createDir() {
    cout << "Choose directory to create dir" << endl;
    this->_fileSystem->printDirectories();
    cout << "Your choice: ";
    int dirId;
    cin >> dirId;
    Dir *dir = this->_fileSystem->getDirectories()[dirId - 1];

    cout << "\nEnter name: ";
    string name;
    cin >> name;

    this->_fileSystem->createDir(name, dir);
}

void FileSystemModeling::createSymbolicLink() {
    cout << "Choose directory to create symbolic link" << endl;
    this->_fileSystem->printDirectories();
    cout << "Your choice: ";
    int dirId;
    cin >> dirId;
    Dir *dir = this->_fileSystem->getDirectories()[dirId - 1];

    cout << "Choose element to link" << endl;
    this->_fileSystem->printElements();
    cout << "Your choice: ";
    int sId;
    cin >> sId;
    SystemElement *s = this->_fileSystem->getElementById(sId - 1);

    cout << "\nEnter name: ";
    string name;
    cin >> name;

    this->_fileSystem->createSymbolicLink(name, s, dir);
}

void FileSystemModeling::createHardLink() {
    cout << "Choose directory to create hard link" << endl;
    this->_fileSystem->printDirectories();
    cout << "Your choice: ";
    int dirId;
    cin >> dirId;
    Dir *dir = this->_fileSystem->getDirectories()[dirId - 1];

    cout << "Choose element to link" << endl;
    this->_fileSystem->printElements();
    cout << "Your choice: ";
    int sId;
    cin >> sId;
    SystemElement *s = this->_fileSystem->getElementById(sId - 1);

    cout << "\nEnter name: ";
    string name;
    cin >> name;

    this->_fileSystem->createHardLink(name, s, dir);
}

void FileSystemModeling::deleteElement() {
    cout << "Choose element to delete" << endl;
    this->_fileSystem->printElements();
    cout << "Your choice: ";
    int sId;
    cin >> sId;
    SystemElement *s = this->_fileSystem->getElementById(sId - 1);

    if (File *f = dynamic_cast<File *>(s)) {
        this->_fileSystem->deleteFile(f);
    } else if (Dir *d = dynamic_cast<Dir *>(s)) {
        this->_fileSystem->deleteDir(d);
    } else if (auto *sl = dynamic_cast<SymbolicLink *>(s)) {
        this->_fileSystem->deleteSymbolicLink(sl);
    } else if (auto *hl = dynamic_cast<HardLink *>(s)) {
        this->_fileSystem->deleteHardLink(hl);
    }
}

void FileSystemModeling::moveElement() {
    cout << "Choose element to move" << endl;
    this->_fileSystem->printElements();
    cout << "Your choice: ";
    int sId;
    cin >> sId;
    SystemElement *s = this->_fileSystem->getElementById(sId - 1);

    cout << "Choose directory to move into" << endl;
    this->_fileSystem->printDirectories();
    cout << "Your choice: ";
    int dirId;
    cin >> dirId;
    Dir *dirTo = this->_fileSystem->getDirectories()[dirId - 1];

    Dir *dirFrom;
    for (Dir *d: this->_fileSystem->getDirectories()) {
        if (d->isElementContained(s)) {
            dirFrom = d;
            break;
        }
    }

    FileSystem::moveElement(s, dirFrom, dirTo);
}

void FileSystemModeling::renameElement() {
    cout << "Choose element to rename" << endl;
    this->_fileSystem->printElements();
    cout << "Your choice: ";
    int sId;
    cin >> sId;
    SystemElement *s = this->_fileSystem->getElementById(sId - 1);

    string newName;
    cout << "New name: ";
    cin >> newName;
    FileSystem::renameElement(s, newName);
}
