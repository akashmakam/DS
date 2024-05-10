// Stack using Linked List Representation

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    int size;
    struct node *top;
} stack;

int isEmpty(stack *s) {
    return (s -> size == 0);
}

stack *createStack() {
    stack *newStack = (stack *) malloc(sizeof(stack));
    if (newStack == NULL) {
        printf("\nMemory could not be dynamically allocated for the new stack.\n");
        return 0;
    }
    newStack -> size = 0;
    newStack -> top = NULL;
    return newStack;
}

node *createNode() {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("\nMemory could not be dynamically allocated for the new node.\n");
        return 0;
    }
    printf("\nEnter the data to be pushed into the stack: ");
    scanf("%d", &(newNode -> data));
    newNode -> next = NULL;
    return newNode;
}

void display(stack *s) {
    if (isEmpty(s)) {
        printf("\nThe stack is empty, cannot display! (Stack Underflow)\n");
        return;
    }
    node *current = s -> top -> next;
    printf("\nThe updated stack elements are:\n%d -> top\n", s -> top -> data);
    while (current != NULL) {
        printf("%d\n", current -> data);
        current = current -> next;
    }
}

void freeStack(stack *s) {
    if (!isEmpty(s)) {
        node *current = s -> top, *nextNode = NULL;
        while (current != NULL) {
            nextNode = current -> next;
            free(current);
            current = nextNode;
        }
    }
    free(s);
    printf("\nThe stack has been successfully freed!\n");
}

void push(stack *s) {
    node *newNode = createNode();
    newNode -> next = s -> top;
    s -> top = newNode;
    printf("\n%d has been successfully pushed into the stack!\n", newNode -> data);
    (s -> size)++;
    display(s);
}

void pop(stack *s) {
    if (isEmpty(s)) {
        printf("\nThe stack is empty, cannot pop! (Stack Underflow)\n");
        return;
    }
    int poppedElement;
    node *temp = s -> top;
    s -> top = temp -> next;
    printf("\n%d has been succesfully popped from the stack!\n", temp -> data);
    free(temp);
    (s -> size)--;
    display(s);
}

void topStack(stack *s) {
    if (s -> top == NULL) {
        printf("\nThe stack is empty, no current top element! (Stack Underflow)\n");
        return;
    }
    printf("\nThe element at the top of the stack is %d.\n", s -> top -> data);
}

int main() {
    stack *s = createStack();
    int option;
    do {
        printf("\nChoose any one of the following:\n"
               "1. Push.\n"
               "2. Pop.\n"
               "3. Top stack.\n"
               "4. Exit.\n");
        scanf("%d", &option);
        switch (option) {
            case 1: push(s); break;
            case 2: pop(s); break;
            case 3: topStack(s); break;
            case 4: freeStack(s); printf("\nExiting Program\n"); break;
            default: printf("Choose a valid option!\n");
        }
    } while (option != 4);
    return 0;
}