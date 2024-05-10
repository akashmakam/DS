// Stack using Array Representation

#include <stdio.h>
#define MAX 5

struct stack {
    int top;
    int data[MAX];
} s;

int isEmpty() {
    return (s.top == -1);
}

int isFull() {
    return (s.top == MAX - 1);
}

void display() {
    if (isEmpty()) {
        printf("\nThe stack is empty, cannot display! (Stack Underflow)\n");
        return;
    }
    printf("\nThe updated stack elements are:\n%d -> top\n", s.data[s.top]);
    for (int i = s.top - 1; i >= 0; i--) {
        printf("%d\n", s.data[i]);
    }
}

void push() {
    if (isFull()) {
        printf("\nThe stack is full, cannot push! (Stack Overflow)\n");
        return;
    }
    printf("\nEnter the data to be pushed into the stack: ");
    scanf("%d", &(s.data[++(s.top)]));
    printf("\n%d has been successfully pushed into stack!\n", s.data[(s.top)]);
    display();
}

void pop() {
    if (isEmpty()) {
        printf("\nThe stack is empty, cannot pop! (Stack Underflow)\n");
        return;
    }
    int dequeuedElement = s.data[(s.top)];
    s.top--;
    printf("\n%d has been succesfully popped from the stack!\n", dequeuedElement);
    display();
}

void topStack() {
    if (isEmpty()) {
        printf("\nThe stack is empty, no current top element! (Stack Underflow)\n");
        return;
    }
    printf("\nThe element at the top of the stack is %d.\n", s.data[(s.top)]);
}

int main() {
    s.top = -1;
    int option;
    do {
        printf("\nChoose any one of the following:\n"
               "1. Push.\n"
               "2. Pop.\n"
               "3. Top stack.\n"
               "4. Exit.\n");
        scanf("%d", &option);
        switch (option) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: topStack(); break;
            case 4: printf("\nExiting Program\n"); return 0;
            default: printf("Choose a valid option!\n");
        }
    } while (option != 4);
}