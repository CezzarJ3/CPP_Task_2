#include <iostream>
#include "../Headers/Link.h"

Link::Link(string &name, SystemElement *linkedElement) : SystemElement(name), _linkedElement(linkedElement) {

}

Link::~Link() = default;

SystemElement *Link::getLink() {
    if (this->_linkedElement == nullptr) {
        string msg = "(Warning) No linked element found.";
        auto *msgElement = new SystemElement(msg);
        return msgElement;
    }
    return this->_linkedElement;
}

void Link::deleteLinkedElement() {
//    delete this->_linkedElement;
    this->_linkedElement = nullptr;
}
