#ifndef CPP_TASK_2_DIR_H
#define CPP_TASK_2_DIR_H

#include "SystemElement.h"
#include "corecrt.h"
#include "vector"

using namespace std;

class Dir : public SystemElement {
public:
    explicit Dir(string &name);

    Dir(string &name, bool nonDeletable);

    void edit();

    void addElement(SystemElement *systemElement);

    bool isElementContained(SystemElement *systemElement);

    void deleteElement(SystemElement *systemElement);

    void deleteDir();

    void getPrintedInfo(int step) override;

    void rename(string &newName) override;

private:
    ~Dir();

    time_t _creationTime;
    time_t _editTime;
    vector<SystemElement *> _content;
    bool _nonDeletable;
};


#endif //CPP_TASK_2_DIR_H
