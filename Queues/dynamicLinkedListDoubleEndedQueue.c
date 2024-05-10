// Dynamic Double Ended Queue

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
    while (current != NULL) {
        printf("%d\t", current -> data);
        current = current -> next;
    }
    printf("\n");
}

void enqueueAtFront(q *q) {
    node *newNode = createNode();
    if (isEmpty(q)) {
        q -> front = q -> rear = newNode;
    } else {
        newNode -> next = q -> front;
        q -> front = newNode;
    }
    printf("\n%d has been successfully enqueued into the queue!\n", newNode -> data);
    (q -> size)++;
    displayQ(q);
}

void enqueueAtRear(q *q) {
    node *newNode = createNode();
    if (isEmpty(q)) {
        q -> front = q -> rear = newNode;
    } else {
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }
    printf("\n%d has been successfully enqueued into the queue!\n", newNode -> data);
    (q -> size)++;
    displayQ(q);
}

void dequeueAtFront(q *q) {
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    node *temp = q -> front;
    q -> front = q -> front -> next;
    if (q -> front == NULL) {
        q -> rear = NULL;
    }
    printf("\n%d has been successfully dequeued from the queue!\n", temp -> data);
    free(temp);
    (q -> size)--;
    displayQ(q);
}

void dequeueAtRear(q *q) {
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    node *current = q -> front;
    while (current -> next != q -> rear) {
        current = current -> next;
    }
    printf("\n%d has been successfully dequeued from the queue!\n", current -> next -> data);
    free(current -> next);
    q -> rear = current;
    q -> rear -> next = NULL;
    (q -> size)--;
    displayQ(q);
}

void peekAtFront(q *q) {
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot peek! (Queue Underflow)\n");
        return;
    }
    printf("\n%d is at the front of the queue.\n", q -> front -> data);
}

void peekAtRear(q *q) {
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot peek! (Queue Underflow)\n");
        return;
    }
    printf("\n%d is at the rear of the queue.\n", q -> rear -> data);
}

void freeQ(q *q) {
    if (!isEmpty(q)) {
        node *current = q -> front, *nextNode;
        while (current != NULL) {
            nextNode = current -> next;
            free(current);
            current = nextNode;
        }
    }
    free(q);
    printf("\nThe queue has been freed successfully!\n");
}

int main() {
    int option;
    q *q = createQ();
    do {
        printf("\nChoose any one of the following options:\n"
               "1. Enqueue at front\n"
               "2. Enqueue at rear\n"
               "3. Dequeue at front\n"
               "4. Dequeue at rear\n"
               "5. Peek at front\n"
               "6. Peek at rear\n"
               "7. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1: enqueueAtFront(q); break;
            case 2: enqueueAtRear(q); break;
            case 3: dequeueAtFront(q); break;
            case 4: dequeueAtRear(q); break;
            case 5: peekAtFront(q); break;
            case 6: peekAtRear(q); break;
            case 7: freeQ(q); break;
            default: printf("\nInvalid option, Try again!\n");
        }
    } while (option != 7);
    return 0;
}