#ifndef CPP_TASK_2_LINK_H
#define CPP_TASK_2_LINK_H

#include "../Headers/SystemElement.h"

class Link : public SystemElement {
public:
    ~Link() override;

    SystemElement *getLink();

    void deleteLinkedElement();

protected:
    Link(string &name, SystemElement *linkedElement);

protected:
    SystemElement *_linkedElement;
};

#endif //CPP_TASK_2_LINK_H
