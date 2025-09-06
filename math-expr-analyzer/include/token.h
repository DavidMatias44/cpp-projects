#ifndef TOKEN_H
#define TOKEN_H

#include "tokenType.h"
#include <iostream>

struct token
{
    TokenType type;
    std::string value;
};

typedef struct token Token;

#endif // TOKEN_H