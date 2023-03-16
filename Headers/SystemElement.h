#ifndef CPP_TASK_2_SYSTEMELEMENT_H
#define CPP_TASK_2_SYSTEMELEMENT_H

#include "string"

using namespace std;

class SystemElement {
public:
    explicit SystemElement(string &name);

    virtual ~SystemElement() = default;

    virtual string getName();

    virtual void rename(string &newName);

    virtual void getPrintedInfo(int step);

protected:
    string _name;
};

#endif //CPP_TASK_2_SYSTEMELEMENT_H
