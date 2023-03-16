#ifndef CPP_TASK_2_SYMBOLICLINK_H
#define CPP_TASK_2_SYMBOLICLINK_H

#include "Link.h"

class SymbolicLink : public Link {
public:
    SymbolicLink(string &name, SystemElement *systemElement);

    void getPrintedInfo(int step) override;
};


#endif //CPP_TASK_2_SYMBOLICLINK_H
