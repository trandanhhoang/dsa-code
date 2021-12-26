#if !defined(EXPRESSION_H)
#define EXPRESSION_H

#include <cmath>
#include <iostream>
#include <stack>
using namespace std;

struct op_and_exp{
    char op;
    string exp;

    op_and_exp(char op,string exp): op(op),exp(exp) {}
    op_and_exp(char operand): op('\0'), exp(string({operand})) {}
};

enum TokenKind {
    OPERAND,
    OPERATOR,
    PARENTHESES, // ()
    SPACE,
    INVALID
};

TokenKind getTokenKind(char token) {
    if (token >= '0' && token <= '9')
        return OPERAND;
    if (std::string("+-*/^").find(token) != std::string::npos)
        return OPERATOR;
    if (std::string("()").find(token) != std::string::npos)
        return PARENTHESES;
    if (std::string(" \t\n\r").find(token) != std::string::npos)
        return SPACE;
    return INVALID;
}

int getOperand(char token) {
    return token - '0';
}

int getPrecendence(char op) {
    if (op == '^')
        return 2;
    if (op == '*' || op == '/')
        return 1;
    if (op == '+' || op == '-')
        return 0;
    throw std::string("Invalid operator ") + std::string({op});
}

int leftAssociative(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    if (op == '^')
        return false;
    throw std::string("Invalid operator ") + std::string({op});
}

float calculate(char op, float left, float right) {
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '^':
            return pow(left, right);
        default:
            throw std::string("Invalid operator ") + std::string({op});
    }
}

#endif  // EXPRESSION_H
