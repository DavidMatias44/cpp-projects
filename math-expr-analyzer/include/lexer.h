#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include "token.h"
#include "tokenType.h"

class Lexer
{
private:
    std::string content;
    char currentChar;
    int currentPos;
    char nextChar;
    int nextPos;

public:
    Lexer(std::string);
    std::vector<Token> tokenize();
    std::string consumeNumber(bool&);
    void consumeSpaces();
    void consumeChar();
};

#endif // LEXER_H
