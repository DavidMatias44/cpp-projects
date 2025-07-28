#ifndef TASKLIST_H
#define TASKLIST_H

#include <vector>
#include "task.h"

class TaskList {
public:
    TaskList() = default;
    void show();
    void add(Task);
    int setTaskStateById(int, State);
    int searchTaskById(int);
    void removeTaskById(int);
    void remove(int);
    Task& operator[](int);
private:
    std::vector<Task> tasks;
};

#endif // TASKLIST_H