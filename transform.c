#include "transform.h"

#include <assert.h>
#include <math.h>

#include "lexer.h"

void simplify_expression(Expression* const expression)
{
    assert(expression != NULL);
}

void expand_expression(Expression* const expression)
{
    assert(expression != NULL);
}

double evaluate_expression(const Expression* const expression)
{
    assert(expression != NULL);

    switch (expression->type) {
    case ExpressionType_Literal: {
        Literal* const literal = (Literal*)expression;

        if (literal->tag == LiteralTag_Number)
            return literal->number;
    } break;

    case ExpressionType_Unary: {
        UnaryExpression* const unary = (UnaryExpression*)expression;
        return -evaluate_expression(unary->subexpression);
    } break;

    case ExpressionType_Binary: {
        BinaryExpression* const binary = (BinaryExpression*)expression;

        switch (binary->operator.type) {
        case TokenType_add:
            return evaluate_expression(binary->left) +
                   evaluate_expression(binary->right);

        case TokenType_subtract:
            return evaluate_expression(binary->left) -
                   evaluate_expression(binary->right);

        case TokenType_multiply:
            return evaluate_expression(binary->left) *
                   evaluate_expression(binary->right);

        case TokenType_divide:
            return evaluate_expression(binary->left) /
                   evaluate_expression(binary->right);

        case TokenType_power:
            return pow(evaluate_expression(binary->left),
                       evaluate_expression(binary->right));
        }
    } break;
    }

    // @NOTE: ExpressionType_Empty and LiteralTag_Symbol case
    return 0;
}