#include "../include/tokenType.h"

std::ostream& operator<<(std::ostream& os, TokenType tokenType)
{
    switch (tokenType) {
    case TokenType::NUMBER:
        os << "number";
        break;
    case TokenType::OPERATOR_ADD:
        os << "operator_add";
        break;
    default:
        os << "unknown";
        break;
    }
    
    return os;
}
