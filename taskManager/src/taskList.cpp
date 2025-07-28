#include "../include/taskList.h"
#include "../include/task.h"

void TaskList::show() 
{
    std::cout << std::endl;
    if (tasks.empty()) {
        std::cout << " Task list is empty!" << std::endl;
        std::cout << std::endl;
        return;
    }

    for (auto& task : tasks) {
        std::cout << task;
    }
    std::cout << std::endl;
}

void TaskList::add(Task newTask)
{
    tasks.push_back(newTask);
    std::cout << "\n New task added: " << std::endl;
    std::cout << newTask << std::endl;
}

int TaskList::searchTaskById(int id)
{
    if (tasks.empty()) {
        show();
        return -1;
    }

    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void TaskList::remove(int index)
{
    tasks.erase(tasks.begin() + index);
}

Task& TaskList::operator[](int index)
{
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range{"TaskList::operator[]"};
    }
    return tasks[index];
}
