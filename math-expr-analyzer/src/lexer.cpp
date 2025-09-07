#include "../include/lexer.h"
#include <cctype>

Lexer::Lexer(std::string content) : content(content)
{
    currentPos = 0;
    currentChar = content.empty() ? '\0' : content[currentPos];
    nextPos = currentPos + 1;
}

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;

    while (currentChar != '\0') {
        Token token;
        
        consumeSpaces();

        if (std::isdigit(currentChar)) {
            token.setValue(consumeNumber());
            token.setType(TokenType::NUMBER);
        } else {
            switch (currentChar) {
                case '+': {
                    token.setValue(std::string{currentChar});
                    token.setType(TokenType::OPERATOR_ADD);
                    consumeChar();
                } break;
                default : {
                    token.setValue(std::string{currentChar});
                    token.setType(TokenType::UNKNOWN);
                    consumeChar();
                }
            }
        }

        tokens.push_back(token);
    }

    return tokens;
}

void Lexer::consumeSpaces()
{
    while (std::isspace(currentChar)) {
        consumeChar();
    }
}

std::string Lexer::consumeNumber()
{
    std::string number = "";

    while (std::isdigit(currentChar)) {
        number += currentChar;
        consumeChar();
    }

    return number;
}

void Lexer::consumeChar()
{
    if (nextPos < content.size()) {
        currentPos = nextPos;
        currentChar = content[nextPos++];
        return;
    }

    currentChar = '\0';
}
