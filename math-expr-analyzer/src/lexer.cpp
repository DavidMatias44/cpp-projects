#include "../include/lexer.h"
#include <cctype>

Lexer::Lexer(std::string content) : content(content)
{
    currentPos = 0;
    currentChar = content.empty() ? '\0' : content[currentPos];
    nextPos = currentPos + 1;
    nextChar = nextPos >= content.size() ? '\0' : content[nextPos];
}

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;

    while (currentChar != '\0') {
        Token token;
        
        consumeSpaces();

        if (std::isdigit(currentChar) || currentChar == '.') {
            bool isValid = true;
            token.setValue(consumeNumber(isValid));
            if (isValid)
                token.setType(TokenType::NUMBER);
            else
                token.setType(TokenType::UNKNOWN);
        } else {
            switch (currentChar) {
                case '+': { token.setType(TokenType::OPERATOR_ADD); } break;
                case '-': { token.setType(TokenType::OPERATOR_SUB); } break;
                case '*': { token.setType(TokenType::OPERATOR_MUL); } break;
                case '/': { token.setType(TokenType::OPERATOR_DIV); } break;
                case '^': { token.setType(TokenType::OPERATOR_POW); } break;
                case '(': { token.setType(TokenType::PAREN_OPEN);   } break;
                case ')': { token.setType(TokenType::PAREN_CLOSE);  } break;
                default : { token.setType(TokenType::UNKNOWN);      }
            }
            
            token.setValue(std::string{currentChar});
            consumeChar();
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

std::string Lexer::consumeNumber(bool& isValid)
{
    std::string number = "";
    bool hasDot = false;

    while (std::isdigit(currentChar) || currentChar == '.') {
        if (currentChar == '.') {
            if (! std::isdigit(nextChar)) {
                number += currentChar;
                consumeChar();
                
                if (number.size() == 1) isValid = false;
                break;
            }

            hasDot = true;
        }

        if (nextChar == '.') {
            if (hasDot) {
                number += currentChar;
                consumeChar();
                break;
            }
        }

        number += currentChar;
        consumeChar();
    }

    return number;
}

void Lexer::consumeChar()
{
    currentPos++;
    currentChar = (currentPos >= content.size()) ? '\0' : content[currentPos];

    nextPos = currentPos + 1;
    nextChar = (nextPos >= content.size()) ? '\0' : content[nextPos];
}
