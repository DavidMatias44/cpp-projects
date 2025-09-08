#include "../include/token.h"

void Token::setType(TokenType t)
{
    type = t;
}

TokenType Token::getType() const
{
    return type;
}
    
void Token::setValue(std::string v)
{
    value = v;
}

std::string Token::getValue() const
{
    return value;
}

std::ostream& operator<<(std::ostream& os, const Token& token)
{
    os << token.getType() << "('" << token.getValue() << "')";
    return os;
}
