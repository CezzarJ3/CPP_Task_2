#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include "../Headers/Dir.h"

Dir::Dir(string &name) : SystemElement(name) {
    this->_creationTime = time(nullptr);
    this->_editTime = time(nullptr);
    this->_nonDeletable = false;
}

Dir::Dir(string &name, bool nonDeletable) : SystemElement(name), _nonDeletable(nonDeletable) {
    this->_creationTime = time(nullptr);
    this->_editTime = time(nullptr);
}

Dir::~Dir() {
    for (SystemElement *e: this->_content) {
        if (Dir *d = dynamic_cast<Dir *>(e)) {
            d->deleteDir();
            continue;
        }
        delete e;
    }
}

void Dir::edit() {
    this->_editTime = time(nullptr);
}

void Dir::addElement(SystemElement *systemElement) {
    this->_content.push_back(systemElement);
    this->edit();
}

bool Dir::isElementContained(SystemElement *systemElement) {
    auto it = std::find(this->_content.begin(), this->_content.end(), systemElement);
    if (it != this->_content.end()) {
        return true;
    } else {
        return false;
    }
}

void Dir::deleteElement(SystemElement *systemElement) {
    auto it = std::find(this->_content.begin(), this->_content.end(), systemElement);
    this->_content.erase(it);
    this->edit();
}

void Dir::deleteDir() {
    if (this->_nonDeletable) {
        cout << "Warning: Directory is non deletable!\n";
        return;
    } else {
        delete this;
    }
}

void Dir::getPrintedInfo(int step) {
    int cur_step = step;
    while (cur_step > 0) {
        cout << "\t";
        cur_step--;
    }

    cout << "/" << this->_name << "; ";
    cout << "created at:" << strtok(ctime(&this->_creationTime), "\n") << "; ";
    cout << "edited at:" << strtok(ctime(&this->_editTime), "\n") << "." << endl;

    for (SystemElement *e: this->_content) {
        e->getPrintedInfo(step + 1);
    }
}

void Dir::rename(string &newName) {
    SystemElement::rename(newName);
    this->edit();
}