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
            tasks.setTaskStateById(id, State::COMPLETED);

            break;
        }
        case 4: {
            int id = readInteger("Type the tasks' id: ");
            tasks.setTaskStateById(id, State::IN_PROGRESS);

            break;
        }
        case 5: {
            int id = readInteger("Type the tasks' id: ");
            tasks.removeTaskById(id);
            
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