// Double Ended Queue

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
    return (q -> front == -1 && q -> rear == -1);
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

void enqueueAtFront(q *q, int data) {
    if (q -> front == 0) {
        printf("\nInsertion at front is not possible!\n");
        return;
    }
    if (isEmpty(q)) {
        q -> front = 0;
        q -> data[++(q -> rear)] = data;
    } else if (q -> front > 0) {
        q -> data[--(q -> front)] = data;
    }
    printf("\n%d enqueued at front successfully!\n", data);
    display(q);
}

void enqueueAtEnd(q *q, int data) {
    if (isFull(q)) {
        printf("\nInsertion at end is not possible!\n");
        return;
    }
    if (isEmpty(q))
        q -> front = 0;
    q -> data[++(q -> rear)] = data;
    printf("\n%d enqueued at end successfully!\n", data);
    display(q);
}

void dequeueAtFront(q *q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty, cannot dequeue from front!\n");
        return;
    }
    int dequeuedData = q -> data[(q -> front)++];
    if (q -> front > q -> rear) {
        q -> front = q -> rear = -1;
    }
    printf("\n%d dequeued from front successfully!\n", dequeuedData);
    display(q);
}

void dequeueAtEnd(q *q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty, cannot dequeue from end!\n");
        return;
    }
    int dequeuedData = q -> data[(q -> rear)--];
    if (q -> front > q -> rear) {
        q -> front = q -> rear = -1;
    }
    printf("\n%d dequeued from end successfully!\n", dequeuedData);
    display(q);
}

void peekAtFront(q *q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty, cannot peek at front!\n");
        return;
    }
    printf("\nPeek at front: %d\n", q -> data[q -> front]);
}

void peekAtRear(q *q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty, cannot peek at rear!\n");
        return;
    }
    printf("\nPeek at rear: %d\n", q -> data[q -> rear]);
}

int main() {
    int option, data, size;
    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);
    q *q = createQueue(size);
    do {
        printf("\nChoose an option:\n"
               "1. Enqueue at front\n"
               "2. Enqueue at end\n"
               "3. Dequeue from front\n"
               "4. Dequeue from end\n"
               "5. Peek at front\n"
               "6. Peek at rear\n"
               "7. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter the data to be enqueued at front: ");
                scanf("%d", &data);
                enqueueAtFront(q, data);
                break;
            case 2:
                printf("\nEnter the data to be enqueued at end: ");
                scanf("%d", &data);
                enqueueAtEnd(q, data);
                break;
            case 3:
                dequeueAtFront(q);
                break;
            case 4:
                dequeueAtEnd(q);
                break;
            case 5:
                peekAtFront(q);
                break;
            case 6:
                peekAtRear(q);
                break;
            case 7:
                free(q -> data);
                free(q);
                printf("\nThe queue has been freed sucessfully!\n");
                break;
            default:
                printf("\nInvalid option! Please choose again.\n");
        }
    } while (option != 7);
    return 0;
}