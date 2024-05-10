// Conversion and Evaluation of Infix Expression to Prefix Expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct stack {
    int data[100];
    int top;
} stack;

int precedence(char symbol) {
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return -1;
}

char associativity(char symbol) {
    if (symbol == '^')
        return 'R';
    return 'L';
}

char *infixToPrefix(char infixExpression[]) {
    stack stack;
    stack.top = -1;
    static char result[100];
    int resultIndex = 0, length = strlen(infixExpression);
    for (int i = length; i >= 0; i--) {
        char c = infixExpression[i];
        if (c == ')') {
            stack.data[++(stack.top)] = c;
        } else if (c == '(') {
            while (stack.top >= 0 && stack.data[stack.top] != ')') {
                result[(resultIndex)++] = stack.data[(stack.top)--];
            }
            (stack.top)--;
        } else if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result[(resultIndex)++] = c;
        } else {
            while (stack.top >= 0 && precedence(c) < precedence(stack.data[stack.top])) {
                result[resultIndex++] = stack.data[(stack.top)--];
            }
            stack.data[++(stack.top)] = c;
        }
    }
    result[length] = '\0';
    return result;
}

int evaluatePrefix(char prefixExpression[]) {
    stack stack;
    stack.top = -1;
    int length = strlen(prefixExpression);
    for (int i = 0; i < length; i++) {
        char c = prefixExpression[i];
        if (c >= '0' && c <= '9') {
            stack.data[++(stack.top)] = c - '0';
        } else {
            int operand1 = stack.data[(stack.top)--];
            int operand2 = stack.data[(stack.top)--];
            switch (c) {
                case '+':
                    stack.data[++(stack.top)] = operand1 + operand2;
                    break;
                case '-':
                    stack.data[++(stack.top)] = operand1 - operand2;
                    break;
                case '*':
                    stack.data[++(stack.top)] = operand1 * operand2;
                    break;
                case '/':
                    stack.data[++(stack.top)] = operand1 / operand2;
                    break;
                case '%':
                    stack.data[++(stack.top)] = operand1 % operand2;
                    break;
                case '^':
                    stack.data[++(stack.top)] = pow(operand1, operand2);
                    break;
                default:
                    printf("Invalid operation!\n");
                    exit(0);
            }
        }
    }
    return stack.data[stack.top];
}

int main() {
    char infixExpression[100];
    printf("\nEnter the infix expression: ");
    scanf("%s", infixExpression);
    printf("Prefix Expression: %s\n", infixToPrefix(infixExpression));
    printf("Evaluated result of Prefix Expression: %d\n", evaluatePrefix(infixToPostfix(infixExpression)));
    return 0;
}