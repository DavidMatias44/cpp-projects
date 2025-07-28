#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>
#include "task.h"

void showMenu();
Task readTask();
std::string readString(const std::string& = "");
int readInteger(const std::string& = "");
bool tryReadInteger(int&);
Priority readPriority(const std::string& = "");
bool isValidPriority(const int);
std::string priorityToString(const Priority&);
std::string stateToString(const State&);

#endif // UTILS_H