# Math expression analyzer.

A work in progress mathematical expression analyzer written in C++.

This project currently includes a **lexer** capable of recognizing basic arithmetic operators and integer numbers. 

Upcoming features include floating-point support, a parser, an evaluato, and math functions such as `sqrt`, `sin`, `cos`, `tan`, `pow`.

## Current features
- **Lexer** that recognizes:
    - Integers.
    - Operators: `+`, `-`, `*`, `/`, `^`.
    - Parenthesis: `(`, `)`.

## Build instructions
```bash
    git clone https://github.com/DavidMatias44/cpp-projects
    cd cpp-projects/math-expr-analyzer
    make
    ./output
```
Optional:
```bash
    make clean
```

## Requirements
- A C++17-compliant compiler.
- Standard C++ libraries only (no external dependencies).
- GNU Make (no need for CMake or external build systems).

## Roadmap
- Basic lexer for integers and operators (done).
- Add floating-point number support.
- Implement parser.
- Implement evaluator.
- Support math functions (`sqrt`, `sin`, `cos`, `tan`, `pow`, etc).
