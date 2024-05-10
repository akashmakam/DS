// Dynamic Circular Queue

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct q {
    int size;
    struct node *front;
    struct node *rear;
} q;

int isEmpty(q *q) {
    return (q -> size == 0);
}

q *createQ() {
    q *newQ = (q *) malloc(sizeof(q));
    if (newQ == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue.\n");
        return 0;
    }
    newQ -> size = 0;
    newQ -> front = newQ -> rear = NULL;
    return newQ;
}

node *createNode() {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("\nMemory could not be dynamically allocated for the new node.\n");
        return 0;
    }
    printf("\nEnter the data to be enqueued: ");
    scanf("%d", &(newNode -> data));
    newNode -> next = NULL;
    return newNode;
}

void displayQ(q *q) {
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot display! (Queue Underflow)\n");
        return;
    }
    node *current = q -> front;
    printf("\nThe updated queue elements are:\n");
    do {
        printf("%d\t", current -> data);
        current = current -> next;
    } while (current != q -> front);
    printf("\n");
}

void enqueue(q *q) {
    node *newNode = createNode();
    if (isEmpty(q)) {
        q -> front = q -> rear = newNode;
    } else {
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }
    newNode -> next = q -> front;
    (q -> size)++;
    printf("\n%d has been successfully enqueued!\n", newNode -> data);
    displayQ(q);
}

void dequeue(q *q) {
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    node *temp = q -> front;
    q -> front = q -> front -> next;
    printf("\n%d has been successfully dequeued!\n", temp -> data);
    free(temp);
    (q -> size)--;
    if (q -> size == 0)
        q -> front = q -> rear = NULL;
    else
        q -> rear -> next = q -> front;
    displayQ(q);
}

void peek(q *q) {
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot peek! (Queue Underflow)\n");
        return;
    }
    printf("\n%d is at the front of the queue.\n", q -> front -> data);
}

void freeQ(q *q) {
    if (!isEmpty(q)) {
        node *current = q -> front, *nextNode;
        do {
            nextNode = current -> next;
            free(current);
            current = nextNode;
        } while (current != q -> front);
    }
    free(q);
    printf("\nThe queue has been freed successfully!\n");
}

int main() {
    int option;
    q *q = createQ();
    do {
        printf("\nChoose any one of the following options:\n"
        "1. Enqueue\n"
        "2. Dequeue\n"
        "3. Peek\n"
        "4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1: enqueue(q); break;
            case 2: dequeue(q); break;
            case 3: peek(q); break;
            case 4: freeQ(q); break;
            default: printf("\nInvalid option, Try again!\n");
        }
    } while (option != 4);
    return 0;
}