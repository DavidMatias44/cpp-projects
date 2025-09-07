#ifndef TOKEN_H
#define TOKEN_H

#include "tokenType.h"
#include <iostream>

class Token
{
private:
    TokenType type;
    std::string value;

public:
    void setType(TokenType);
    TokenType getType() const;
    void setValue(std::string);
    std::string getValue() const;
    friend std::ostream& operator<<(std::ostream&, const Token&);
};

#endif // TOKEN_H
