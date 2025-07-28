#include "../include/task.h"
#include "../include/utils.h"

int Task::serial = 1;

Task::Task(std::string name, std::string description, Priority priority): 
    id(serial++),
    name(name),
    description(description),
    priority(priority),
    state(State::TODO)
{}

int Task::getId() const 
{
    return id;
}

std::string Task::getName() const 
{
    return name;
}

std::string Task::getDescription() const 
{
    return description;
}

Priority Task::getPriority() const 
{
    return priority;
}

void Task::setPriority(Priority priority) 
{
    this->priority = priority;
}

State Task::getState() const 
{
    return state;
}

void Task::setState(State state)
{
    this->state = state;
}

std::ostream& operator<<(std::ostream& os, const Task& task) 
{
    os << "{\n"
       << "  \"id\": " << "\"" << task.getId() << "\"" << std::endl
       << "  \"description\": " << "\"" << task.getDescription() << "\"" << std::endl
       << "  \"state\": " << "\"" << stateToString(task.getState()) << "\"" << std::endl
       << "  \"priority\": " << "\"" << priorityToString(task.getPriority()) << "\"" << std::endl
       << "}\n";
   return os;
}
