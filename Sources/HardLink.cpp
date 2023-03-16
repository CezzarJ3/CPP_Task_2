#include <iostream>
#include "../Headers/HardLink.h"
#include "../Headers/Dir.h"

using namespace std;

HardLink::HardLink(string &name, SystemElement *systemElement) : Link(name, systemElement) {

}

HardLink::~HardLink() {
    if (Dir *d = dynamic_cast<Dir *>(this->_linkedElement)) {
        d->deleteDir();
        return;
    }
    delete this->_linkedElement;
}

void HardLink::getPrintedInfo(int step) {
    while (step > 0) {
        cout << "\t";
        step--;
    }

    cout << this->_name << "; ";
    cout << "hard linked to: " << this->getLink()->getName() << "." << endl;
}
