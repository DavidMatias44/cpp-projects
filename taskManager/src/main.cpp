#include <iostream>
#include "../include/taskList.h"
#include "../include/utils.h"

int main(void) {
    bool isTerminated = false;
    TaskList tasks;

    while (!isTerminated) {
        showMenu();
        int userOption = readInteger("Type an option: ");

        switch (userOption) {
        case 1: {
            tasks.show();
            break;
        } 
        case 2: {
            Task newTask = readTask();
            tasks.add(newTask);
            break;
        } 
        case 3: {
            int id = readInteger("Type the tasks' id: ");
            int index = tasks.searchTaskById(id);
            if (index < 0) {
                std::cout << "Task with id: " << id << " not found." << std::endl << std::endl;;
            } else {
                tasks[index].setState(State::COMPLETED);
                std::cout << "Change the state of task: " << std::endl;
                std::cout << tasks[index] << std::endl;
                std::cout << std::endl;
            }

            break;
        }
        case 4: {
            int id = readInteger("Type the tasks' id: ");
            int index = tasks.searchTaskById(id);
            if (index < 0) {
                std::cout << "Task with id: " << id << " not found." << std::endl << std::endl;
            } else {
                tasks[index].setState(State::IN_PROGRESS);
                std::cout << "Change the state of task: " << std::endl;
                std::cout << tasks[index] << std::endl;
                std::cout << std::endl;
            }

            break;
        }
        case 5: {
            int id = readInteger("Type the tasks' id: ");
            int index = tasks.searchTaskById(id);
            if (index < 0) {
                std::cout << "Task with id: " << id << " not found." << std::endl << std::endl;
            } else {
                tasks.remove(index);
                std::cout << std::endl;
            }
            break;
        }
        case 6: {
            isTerminated = true;
            break;
        }
        default:
            std::cout << " [Not valid option: " << userOption << "]" << std::endl;
            std::cin.clear();
            break;
        }
    }
    return 0;
}