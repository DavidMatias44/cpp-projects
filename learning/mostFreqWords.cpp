#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

/*
    Se introduce un texto por terminal, se debe contar cuántas veces ocurre cada palabra, 
    y mostrarlo en orden alfabético en terminal.
*/

int main()
{
    std::map<std::string, int> mp; 

    std::string text;
    std::cout << "Introduzca el texto a procesar: " << std::endl;
    std::getline(std::cin, text);

    std::istringstream iss(text);
    do {
        std::string word;
        iss >> word;

        if (word == "") continue;
        if (!mp.count(word)) {
            mp.insert({word, 1});
        } else {
            ++mp[word];
        }
    } while (iss);

    int map_size = mp.size();
    std::vector<std::pair<std::string, int>> v;
    for (auto& a : mp) {
        // std::cout << a.first << ": " << a.second << std::endl;
        v.push_back(a);
    }

    std::sort(v.begin(), v.end(), [](std::pair<std::string, int> pair1, std::pair<std::string, int> pair2) { 
        return pair1.second > pair2.second;
    });

    for (int i = 0; i < v.size() && i < 3; ++i) {
        std::cout << v[i].first << " : " << v[i].second << std::endl;
    }
    return 0;
}