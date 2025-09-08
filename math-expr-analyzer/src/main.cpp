#include <iostream>
#include "../include/lexer.h"

int main(void)
{   
    std::string expr = "(2 * (3 - 4)) / 2^3";

    Lexer lexer(expr);
    std::vector<Token> tokens = lexer.tokenize();

    std::cout << expr << std::endl;
    std::cout << "[";
    for (int i = 0; i < tokens.size(); i++) {
        if (i + 1 == tokens.size()) {
            std::cout << tokens[i];
            continue;
        }

        std::cout << tokens[i] << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
