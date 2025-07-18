#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<std::vector<std::string>> content;
    
    std::ifstream file("datos.csv");

    std::string line;
    while (getline(file, line)) {
        std::replace(line.begin(), line.end(), ',', ' ');

        std::vector<std::string> temp;
        std::istringstream iss(line);
        std::string value;
        while (iss >> value) {
            temp.push_back(value);
        }
        std::cout << std::endl;
        content.push_back(temp);
    }

    for (auto& a : content) {
        for (auto& b : a) {
            std::cout << "\t" << b << " ";
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}
