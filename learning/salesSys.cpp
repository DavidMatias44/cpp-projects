#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include "salesSys.h"

void insertProduct(std::unordered_map<std::string, double>& p, std::string name, double cost) {
    p.insert({name, cost});
}

void registerSale(std::unordered_map<std::string, int>& s, std::string name, int n) {
    s.insert({name, n});
}

double getTotal(const std::unordered_map<std::string, double>& products, const std::unordered_map<std::string, int>& sales) {
    double total = 0;
    for (auto& product : products) {
        for (auto& sale : sales) {
            if (product.first == sale.first) {
                total += product.second * sale.second;
            }
        }
    }

    return total;
}

int main() {
    std::unordered_map<std::string, double> products;
    std::unordered_map<std::string, int> sales;
    std::map<std::string, std::vector<std::pair<std::string, int>>> customers;

    insertProduct(products, "salsa", 15.50);
    insertProduct(products, "jabon", 14.00);

    std::vector<std::pair<std::string, int>> products_c1 = {{"salsa", 1}};
    customers.insert({"Juan", products_c1});

    registerSale(sales, "salsa", 1);
    registerSale(sales, "jabon", 5);

    std::cout << "Productos registrados: " << std::endl;
    for (auto& a : products) {
        std::cout << a.first << ", " << a.second << std::endl;
    }

    std::cout << std::endl << "Ventas registradas: " << std::endl;
    for (auto& a : sales) {
        std::cout << a.first << ", " << a.second << std::endl;
    }

    std::cout << std::endl << "Total vendido: " << getTotal(products, sales) << std::endl;

    return 0;
}