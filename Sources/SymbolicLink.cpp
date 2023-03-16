#include <iostream>
#include "../Headers/SymbolicLink.h"


SymbolicLink::SymbolicLink(string &name, SystemElement *systemElement) : Link(name, systemElement) {

}

void SymbolicLink::getPrintedInfo(int step) {
    while (step > 0) {
        cout << "\t";
        step--;
    }

    cout << this->_name << "; ";
    cout << "soft linked to: " << this->getLink()->getName() << "." << endl;
}
