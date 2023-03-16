#ifndef CPP_TASK_2_HARDLINK_H
#define CPP_TASK_2_HARDLINK_H

#include "Link.h"

class HardLink : public Link {
public:
    HardLink(string &name, SystemElement *systemElement);

    ~HardLink() override;

    void getPrintedInfo(int step) override;
};


#endif //CPP_TASK_2_HARDLINK_H
