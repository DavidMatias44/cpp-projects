#ifndef TASK_H
#define TASK_H

#include <iostream>
#include "state.h"
#include "priority.h"

class Task {
public:
    Task(std::string, std::string, Priority);
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    Priority getPriority() const ;
    State getState() const;
    void setState(State state);
    friend std::ostream& operator<<(std::ostream&, const Task&);
private:
    static int serial;
    int id;
    std::string name;
    std::string description;
    Priority priority;
    State state;
};

#endif // TASK_H
