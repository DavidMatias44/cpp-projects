#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {54, 12, 623, 72, 61, 72, 833};

    std::cout << "Vector original: " << std::endl;
    for (auto& a : v) {
        std::cout << a << " ";
    }
    std::cout << std::endl << std::endl;

    std::sort(v.begin(), v.end());
    std::cout << "Vector ordenado (asc): " << std::endl;
    for (auto& a : v) {
        std::cout << a << " ";
    }
    std::cout << std::endl << std::endl;
   
    std::sort(v.begin(), v.end(), [](int a, int b) { return (a > b); });
    std::cout << "Vector ordenado (desc): " << std::endl;
    for (auto& a : v) {
        std::cout << a << " ";
    }
    std::cout << std::endl << std::endl;

    return 0;
}
