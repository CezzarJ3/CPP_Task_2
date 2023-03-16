#include <iostream>
#include "../Headers/SystemElement.h"

using namespace std;

SystemElement::SystemElement(string &name) : _name(name) {

}

string SystemElement::getName() {
    return this->_name;
}

void SystemElement::rename(string &newName) {
    this->_name = newName;
}

void SystemElement::getPrintedInfo(int step) {
    cout << "Element name:" << this->_name << endl;
}
