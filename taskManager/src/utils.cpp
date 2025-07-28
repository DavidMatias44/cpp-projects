#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <cctype>
#include "../include/utils.h"

void showMenu() 
{
    std::cout << "============ MENU ============" << std::endl;
    std::cout << "[1]: show all tasks." << std::endl;
    std::cout << "[2]: add a new task." << std::endl;
    std::cout << "[3]: mark a task as completed." << std::endl;
    std::cout << "[4]: mark a task as in progress." << std::endl;
    std::cout << "[5]: delete a task." << std::endl;
    std::cout << "[6]: exit this program." << std::endl;
}

Task readTask()
{
    std::string taskName = readString("\n Type the name of the task: ");
    std::string taskDescription = readString(" Type the description of the task: ");

    std::string prompt = " Select the priority of the task\n (0)->HIGH  (1)->MEDIUM  (2)->LOW: ";
    Priority priority = readPriority(prompt);

    Task newTask(taskName, taskDescription, priority);
    return newTask;
}

/*
 * Show the optional string on stdout. Receive a string from stdin. Do basis validation.
*/
std::string readString(const std::string& str)
{
    std::string prompt = (str.empty()) ? "Type a string: " : str;
    std::string res;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, res);

        if (!res.empty()) {
            break;
        }
    }
    return res;
}

/*
 * Show the optional string on stdout. Receive an integer from stdin. Do basic validation.
*/
int readInteger(const std::string& str)
{
    std::string prompt = (str.empty()) ? "Type a number: " : str ;
    int value;

    while (true) {
        std::cout << prompt;
        if (tryReadInteger(value))
            return value;
        std::cout << "Type a valid number, please" << std::endl;
    }
}

/*
 * Try to read an integer from stdin, return true if the value is an integer, false otherwise.
*/
bool tryReadInteger(int& value) 
{
    while (true) {
        std::cin >> value;
        if (std::cin.good()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
    }
}

Priority readPriority(const std::string& str)
{
    std::string prompt = (str.empty()) ? "Type a number: " : str;
    int priority;
    while (true) {
        priority = readInteger(prompt);
        if (isValidPriority(priority)) 
            break;
    }

    return static_cast<Priority>(priority);
}

bool isValidPriority(int priority) 
{
    return static_cast<Priority>(priority) == Priority::HIGH 
        || static_cast<Priority>(priority) == Priority::MEDIUM 
        || static_cast<Priority>(priority) == Priority::LOW;
}

std::string stateToString(const State& state)
{
    switch (state) {
    case State::TODO:
        return "To Do";
        break;
    case State::IN_PROGRESS:
        return "In Progress";
        break;
    case State::COMPLETED:
        return "Completed";
        break;
    default:
        return "";
        break;
    }
}

std::string priorityToString(const Priority& priority)
{
    switch (priority) {
    case Priority::HIGH:
        return "High";
        break;
    case Priority::MEDIUM:
        return "Medium";
        break;
    case Priority::LOW:
        return "Low";
        break;
    default:
        return "";
        break;
    }
}
