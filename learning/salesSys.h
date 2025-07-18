#include <unordered_map>
#include <string>

void insertProduct(std::unordered_map<std::string, double>&, std::string, double);
void registerSale(std::unordered_map<std::string, int>&, std::string, int);
double getTotal(const std::unordered_map<std::string, double>&, const std::unordered_map<std::string, int>&);
