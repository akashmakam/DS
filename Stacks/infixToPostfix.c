// Conversion and Evaluation of Infix Expression to Postfix Expression

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

char *infixToPostfix(char infixExpression[]) {
    stack stack;
    stack.top = -1;
    static char result[100];
    int resultIndex = 0, length = strlen(infixExpression);
    for (int i = 0; i <= length; i++) {
        char c = infixExpression[i];
        if (c == '(') {
            stack.data[++(stack.top)] = c;
        } else if (c == ')') {
            while (stack.top >= 0 && stack.data[stack.top] != '(') {
                result[(resultIndex)++] = stack.data[(stack.top)--];
            }
            (stack.top)--;
        } else if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result[(resultIndex)++] = c;
        } else {
            while (stack.top >= 0 && precedence(stack.data[stack.top]) >= precedence(c)) {
                result[(resultIndex)++] = stack.data[(stack.top)--];
            }
            stack.data[++(stack.top)] = c;
        }
    }
    result[length] = '\0';
    return result;
}

int evaluatePostfix(char postfixExpression[]) {
    stack stack;
    stack.top = -1;
    int length = strlen(postfixExpression);
    for (int i = 0; i < length; i++) {
        char c = postfixExpression[i];
        if (c >= '0' && c <= '9') {
            stack.data[++(stack.top)] = c - '0';
        } else {
            int operand1 = stack.data[(stack.top)--];
            int operand2 = stack.data[(stack.top)--];
            switch(c) {
                case '^':
                    stack.data[++(stack.top)] = pow(operand2, operand1);
                    break;
                case '*':
                    stack.data[++(stack.top)] = operand2 * operand1;
                    break;
                case '/':
                    stack.data[++(stack.top)] = operand2 / operand1;
                    break;
                case '+':
                    stack.data[++(stack.top)] = operand2 + operand1;
                    break;
                case '-':
                    stack.data[++(stack.top)] = operand2 - operand1;
                    break;
                case '%':
                    stack.data[++(stack.top)] = operand2 % operand1;;
                    break;
            }
        }
    }
    return stack.data[stack.top];
}

int main() {
    char infixExpression[100];
    printf("\nEnter the infix expression: ");
    scanf("%s", infixExpression);
    printf("Postfix Expression: %s\n", infixToPostfix(infixExpression));
    printf("Evaluated result of Postfix Expression: %d\n", evaluatePostfix(infixToPostfix(infixExpression)));
    return 0;
}