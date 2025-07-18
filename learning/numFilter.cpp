#include <iostream>
#include <vector>
#include <algorithm>

// Se eliminan los número pares presentes en el vector.

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto res = std::remove_if(v.begin(), v.end(), [](int n){ return n % 2 == 0; });
    v.erase(res, v.end());
    for (auto& a : v) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    return 0;
}