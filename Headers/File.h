#ifndef CPP_TASK_2_FILE_H
#define CPP_TASK_2_FILE_H

#include "SystemElement.h"

class File : public SystemElement {
public:
    explicit File(string &name, string &extension, int size);

    void getPrintedInfo(int step) override;

    void edit();

    void rename(string &newName) override;

    string getName() override;

private:
    string const _extension;
    int const _size;
    time_t _creationTime;
    time_t _editTime;
};


#endif //CPP_TASK_2_FILE_H
