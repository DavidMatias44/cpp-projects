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
    case TokenType::OPERATOR_SUB:
        os << "operator_sub";
        break;
    case TokenType::OPERATOR_MUL:
        os << "operator_mul";
        break;
    case TokenType::OPERATOR_DIV:
        os << "operator_div";
        break;
    case TokenType::OPERATOR_POW:
        os << "operator_pow";
        break;
    case TokenType::PAREN_OPEN:
        os << "paren_open";
        break;
    case TokenType::PAREN_CLOSE:
        os << "paren_close";
        break;
    default:
        os << "unknown";
        break;
    }
    
    return os;
}
