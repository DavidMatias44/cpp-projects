#include <iostream>
#include "../include/lexer.h"

int main(void)
{   
    Lexer lexer("2+2");
    std::vector<Token> tokens = lexer.tokenize();

    std::cout << "[";
    for (auto& t : tokens) {
        std::cout << t << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
