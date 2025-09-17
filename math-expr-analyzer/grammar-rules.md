# Mathematical expression analyzer
This document describes the grammar used by the mathematical expression analyzer implemented in this project.

## Grammar

### Backus–Naur 
Backus-Naur form (BNF), is a notation system for defining the syntax of programming languages and other formal languages.

#### Structure
BNF specifications outline how symbols are combined to form syntactically valid sequences. Each BNF consists of three core components: 
1. A set of **non-terminal symbols**. Represent variables that can be replaced. They are written within angle brackets.
2. A set of **terminal symbols**. These symbols are fixed. They are written within quotes.
3. A series of **derivation rules**. Provide the instructions for replacing **non-terminal symbols**.

Source: https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form

### Lexer
This project has a lexer implemented from scratch. The current tokens the lexer manage are:
```cpp
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
```
#### Lexer output examples:
```bash
2 * (3.4 - 12.)
[number('.2'), operator_mul('*'), paren_open('('), number('3.4'), operator_sub('-'), number('12.'), paren_close(')')]
```
```bash
2.2.3 + 2^
[number('2.2'), number('.3'), operator_add('+'), number('2'), operator_pow('^')]
```

As you can see the numbers are validated by the lexer implementation, so, there is no number related rules on the grammar especification.

### Rules
```
<Expression> ::= <Term> { ("OPERATOR_ADD" | "OPERATOR_SUB") <Term> }

<Term>       ::= <Factor> { ("OPERATOR_MUL" | "OPERATOR_DIV") <Factor> }

<Factor>     ::= <Unary> [ "OPERATOR_POW" <Factor> ]

<Unary>      ::= [ "OPERATOR_ADD" | "OPERATOR_SUB" ] <Primary>

<Primary>    ::= "number" | "PAREN_OPEN" <Expression> "PAREN_CLOSE"
```

#### Explanation
|Rule           |  Description |
|:-------------:|:---------------------------------------------------:|
|`<Expression>` | handles addition and subtraction.                  |
|`<Term>`       | handles multiplication and division.                |
|`<Factor>`     | handles exponentiation.                             |
|`<Unary>`      | handles unary plus or minus signs.                  |
|`<Primary>`    | can be a number or an expression within parentheses.|
