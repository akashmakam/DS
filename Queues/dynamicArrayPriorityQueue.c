// Priority Queue (Insertion is ordered, deletion is normal)

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *data;
    int size, front, rear;
} q;

q *createQueue(int size) {
    q *newQ = (q *)malloc(sizeof(q));
    if (newQ == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue!\n");
        exit(1);
    }
    newQ -> data = (int *) malloc(size * sizeof(int));
    if (newQ -> data == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue!\n");
        free(newQ);
        exit(1);
    }
    newQ -> size = size;
    newQ -> front = newQ -> rear = -1;
    return newQ;
}

int isEmpty(q *q) {
    return (q -> front == -1 || q -> front > q -> rear);
}

int isFull(q *q) {
    return (q -> rear == q -> size - 1);
}

void display(q *q) {
    if(isEmpty(q)) {
        printf("\nQueue is empty, cannot display!\n");
        return;
    }
    printf("\nThe updated queue elements are:\n");
    for (int i = q -> front; i <= q -> rear; i++) {
        printf("%d\t", q -> data[i]);
    }
    printf("\n");
}

void enqueue(q *q, int data) {
    if(isFull(q)) {
        printf("\nQueue is full, cannot enqueue!\n");
        return;
    }
    if (isEmpty(q)) {
        q -> front = 0;
        q -> data[++(q -> rear)] = data;
    } else {
        int count = 0;
        for (int i = q -> front; i <= q -> rear; i++) {
            if (data <= q -> data[i]) {
                break;
            }
            count++;
        }
        for (int i = q -> size; i >= count; i--) {
            q -> data[i] = q -> data[i - 1];
        }
        q -> data[count] = data;
        (q -> rear)++;
    }
    display(q);
}

void dequeue(q *q) {
    if(isEmpty(q)) {
        printf("\nQueue is empty, cannot dequeue!\n");
        return;
    }
    int dequeuedData = (q -> front)++;
    if (isEmpty(q)) {
        q -> front = q -> rear = -1;
    }
    printf("\n%d has been dequeued from the queue!\n", dequeuedData);
    display(q);
}

void peek(q *q) {
    if(isEmpty(q)) {
        printf("\nQueue is empty, cannot peek!\n");
        return;
    }
    printf("\n%d is at the front of the queue!\n", q -> data[q -> front]);
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