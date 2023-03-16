#include <iostream>
#include <cstring>
#include "../Headers/File.h"
#include "ctime"

File::File(string &name, string &extension, int size) : SystemElement(name), _extension(extension), _size(size) {
    this->_creationTime = time(nullptr);
    this->_editTime = time(nullptr);
}

void File::getPrintedInfo(int step) {
    while (step > 0) {
        cout << "\t";
        step--;
    }
    cout << this->_name << "." << this->_extension << "; ";
    cout << this->_size << "; ";
    cout << "created at:" << strtok(ctime(&_creationTime), "\n") << "; ";
    cout << "edited at:" << strtok(ctime(&_editTime), "\n") << "." << endl;
}

void File::edit() {
    this->_editTime = time(nullptr);
}

void File::rename(string &newName) {
    SystemElement::rename(newName);
    this->edit();
}

string File::getName() {
    string fullName;
    fullName.append(this->_name).append(".").append(this->_extension);
    return fullName;
}
