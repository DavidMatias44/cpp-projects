#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

int main()
{
    std::vector<double> numbers;

    std::cout << "Introduzca los numeros (separados por espacio): ";
    std::string ss;
    getline(std::cin, ss);

    std::istringstream is(ss);
    std::string str;
    while (is >> str) {
        try {
            numbers.push_back(std::stoi(str));
        } catch (std::invalid_argument e) {
            std::cout << "Una de las entradas no es un numero :(" << std::endl;
            throw e;
        }
    }

    std::cout << "[ ";
    for (auto& a : numbers) {
        std::cout << a << " ";
    }
    std::cout << "]" << std::endl;

    double sum = 0;
    std::for_each(numbers.begin(), numbers.end(), [&](int n) { return sum += n; });
    std::cout << "Suma: " << sum << std::endl;

    double val = 15;
    int counter = 0;
    std::for_each(numbers.begin(), numbers.end(), [&](int n) { if (n > val) counter++; });
    std::cout << "Mayores a 15: " << counter << std::endl;

    std::cout << "Promedio: " << sum / numbers.size() << std::endl;
    
    return 0;
}