#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <iostream>

enum class TokenType
{
    NUMBER,
    OPERATOR_ADD,
    UNKNOWN,
};

std::ostream& operator<<(std::ostream&, TokenType);

#endif // TOKENTYPE_H
