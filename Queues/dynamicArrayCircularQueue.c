// Circular Queue

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *data;
    int size, front, rear;
} q;

q *createQueue(int size) {
    q *newQ = (q *) malloc(sizeof(q));
    if (newQ == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue!\n");
        exit(1);
    }
    newQ -> data = (int *) malloc(size * sizeof(int));
    if (newQ -> data == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue!\n");
        exit(1);
    }
    newQ -> size = size;
    newQ -> front = newQ -> rear = -1;
    return newQ;
}

int isEmpty(q *q) {
    return(q -> front == -1);
}

int isFull(q *q) {
    return(((q -> rear + 1) % q -> size) == q -> front);
}

void display(q *q) {
    if(isEmpty(q)) {
        printf("\nThe queue is empty, cannot display!\n");
        return;
    }
    printf("\nThe updated queue elements are:\n");
    int i = q -> front;
    do {
        printf("%d\t", q -> data[i]);
        i = (i + 1) % q -> size;
    } while (i != (q -> rear + 1) % q -> size);
    printf("\n");
}

void enqueue(q *q, int data) {
    if(isFull(q)) {
        printf("\nThe queue is full, cannot enqueue!\n");
        return;
    }
    if(isEmpty(q)) {
        q -> front = 0;
    }
    q -> rear = (q -> rear + 1) % q -> size;
    q -> data[(q -> rear)] = data;
    printf("\n%d has been successfully enqueued!\n", data);
    display(q);
}

void dequeue(q *q) {
    if(isEmpty(q)) {
        printf("\nThe queue is empty, cannot dequeue!\n");
        return;
    }
    int dequeuedData;
    dequeuedData = q -> data[q -> front];
    q -> front = (q -> front + 1) % q -> size;
    if (q -> front == q -> rear) {
        q -> front = q -> rear = -1;
    }
    printf("\n%d has been dequeued from the list successfully!\n", dequeuedData);
    display(q);
}

void peek(q *q) {
    if(isEmpty(q)) {
        printf("\nThe queue is empty, cannot peek!\n");
        return;
    }
    printf("%d is at the front of the queue!\n", q -> front);
}

int main() {
    int option, data, size;
    printf("\nEnter the size of the queue: ");
    scanf("%d", &(size));
    q *q = createQueue(size);
    do {
        printf("\nChoose any one of the following options:\n"
        "1. Enqueue\n"
        "2. Dequeue\n"
        "3. Peek\n"
        "4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                free(q);
                printf("\nThe queue has been freed sucessfully!\n");
                break;
            default:
                printf("\nChoose a valid option!\n");
        }
    } while(option != 4);
    return 0;
}