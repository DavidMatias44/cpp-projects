#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <iostream>

enum class TokenType
{
    NUMBER,
    OPERATOR_ADD,
    OPERATOR_SUB,
    OPERATOR_MUL,
    OPERATOR_DIV,
    OPERATOR_POW,
    PAREN_OPEN,
    PAREN_CLOSE,
    UNKNOWN,
};

std::ostream& operator<<(std::ostream&, TokenType);

#endif // TOKENTYPE_H
