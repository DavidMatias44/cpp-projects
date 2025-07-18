#include <iostream>
#include <map>
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

    for (auto& a : mp) {
        std::cout << a.first << ": " << a.second << std::endl;
    }
    
    return 0;
}