#include "../Headers/FileSystem.h"
#include <bits/stdc++.h>

FileSystem::FileSystem() {
    string name = "/";
    Dir *rootDir = new Dir(name, true);
    this->_listOfElements.push_back(rootDir);
}

FileSystem::~FileSystem() {
    for (auto &x: this->_listOfLinkedElements) {
        delete x.first;
        delete x.second;
    }

    for (SystemElement *e: this->_listOfElements) {
        if (Dir *d = dynamic_cast<Dir *>(e)) {
            d->deleteDir();
            continue;
        }
        delete e;
    }
}

void FileSystem::createFile(string &name, string &ext, int size, Dir *targetDir) {
    File *file = new File(name, ext, size);
    if (targetDir != nullptr) {
        targetDir->addElement(file); //adding new element to the specified directory
    } else {
        dynamic_cast<Dir *>(this->_listOfElements[0])->addElement(file); //adding new element to the root directory
    }
    this->_listOfElements.push_back(file); //adding to the common element list
}

void FileSystem::createDir(string &name, Dir *targetDir) {
    Dir *dir = new Dir(name);
    if (targetDir != nullptr) {
        targetDir->addElement(dir);
    } else {
        dynamic_cast<Dir *>(this->_listOfElements[0])->addElement(dir); //adding new element to the root directory
    }
    this->_listOfElements.push_back(dir);
}

void FileSystem::createSymbolicLink(string &name, SystemElement *linkedElement, Dir *targetDir) {
    auto *symbolicLink = new SymbolicLink(name, linkedElement);
    if (targetDir != nullptr) {
        targetDir->addElement(symbolicLink);
    } else {
        dynamic_cast<Dir *>(this->_listOfElements[0])->addElement(
                symbolicLink); //adding new element to the root directory
    }
    this->_listOfLinkedElements.insert_or_assign(symbolicLink, linkedElement);
    this->_listOfElements.push_back(symbolicLink);
}

void FileSystem::createHardLink(string &name, SystemElement *linkedElement, Dir *targetDir) {
    auto *hardLink = new HardLink(name, linkedElement);
    if (targetDir != nullptr) {
        targetDir->addElement(hardLink);
    } else {
        dynamic_cast<Dir *>(this->_listOfElements[0])->addElement(
                hardLink); //adding new element to the root directory
    }
    this->_listOfLinkedElements.insert_or_assign(hardLink, linkedElement);
    this->_listOfElements.push_back(hardLink);
}

void FileSystem::showFileTree() {
    Dir *rootDir = dynamic_cast<Dir *>(this->_listOfElements[0]);
    rootDir->getPrintedInfo(0);
}

void FileSystem::deleteFile(File *file) {
    deleteElementFromElementList(file);
    deleteElementFromLinkedElementList(file);

    for (Dir *d: this->getDirectories()) {
        if (d->isElementContained(file)) {
            d->deleteElement(file);
        }
    }
    delete file;
}

void FileSystem::deleteDir(Dir *dir) {
    deleteElementFromElementList(dir);
    deleteElementFromLinkedElementList(dir);

    for (Dir *d: this->getDirectories()) {
        if (d->isElementContained(dir)) {
            d->deleteElement(dir);
        }
    }
    dir->deleteDir();
}

void FileSystem::deleteSymbolicLink(SymbolicLink *symbolicLink) {
    deleteElementFromElementList(symbolicLink);
    deleteElementFromLinkedElementList(symbolicLink);

    for (Dir *d: this->getDirectories()) {
        if (d->isElementContained(symbolicLink)) {
            d->deleteElement(symbolicLink);
        }
    }
    this->_listOfLinkedElements.erase(symbolicLink);
    delete symbolicLink;
}

void FileSystem::deleteHardLink(HardLink *hardLink) {
    deleteElementFromElementList(hardLink);

    auto it = this->_listOfLinkedElements.find(hardLink);
    SystemElement *toDelete = it->second;

    if (File *f = dynamic_cast<File *>(toDelete)) {
        deleteFile(f);
    } else if (Dir *d = dynamic_cast<Dir *>(toDelete)) {
        deleteDir(d);
    } else if (auto *sl = dynamic_cast<SymbolicLink *>(toDelete)) {
        deleteSymbolicLink(sl);
    }

    deleteElementFromLinkedElementList(hardLink);

    for (Dir *d: this->getDirectories()) {
        if (d->isElementContained(hardLink)) {
            d->deleteElement(hardLink);
        }
    }

    delete hardLink;
}

void FileSystem::moveElement(SystemElement *elementToMove, Dir *moveFrom, Dir *moveTo) {
    moveFrom->deleteElement(elementToMove);
    moveTo->addElement(elementToMove);
}

void FileSystem::renameElement(SystemElement *systemElement, string &newName) {
    systemElement->rename(newName);
}

vector<Dir *> FileSystem::getDirectories() {
    vector<Dir *> result;
    size_t size = this->_listOfElements.size();
    for (int i = 0; i < size; ++i) {
        if (Dir *d = dynamic_cast<Dir *>(this->_listOfElements[i])) {
            result.push_back(d);
        }
    }

    return result;
}

void FileSystem::printDirectories() {
    int id = 1;
    for (Dir *d: this->getDirectories()) {
        cout << "\t" << id << ".  " << d->getName() << endl;
        id++;
    }
}

vector<SystemElement *> FileSystem::getElements() {
    return this->_listOfElements;
}

void FileSystem::printElements() {
    int id = 1;
    for (SystemElement *s: this->_listOfElements) {
        cout << "\t" << id << ".  " << s->getName() << endl;
        id++;
    }
}

SystemElement *FileSystem::getElementById(int id) {
    return this->_listOfElements[id];
}

template<typename K>
void FileSystem::deleteElementFromElementList(K *element) {
    auto it = std::find(this->_listOfElements.begin(), this->_listOfElements.end(), element);
    if (it != this->_listOfElements.end()) {
        this->_listOfElements.erase(it);
    }
}

template<typename K>
void FileSystem::deleteElementFromLinkedElementList(K *element) {
    auto iter = this->_listOfLinkedElements.begin();
    while (iter != this->_listOfLinkedElements.end()) {
        if (iter->second == element) {
            iter->first->deleteLinkedElement();
            iter = this->_listOfLinkedElements.erase(iter);
        } else {
            iter++;
        }
    }
}
