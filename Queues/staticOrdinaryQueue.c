// Static Ordinary Queue

#include <stdio.h>
#define MAX 5

struct queue {
    int data[MAX];
    int front, rear;
} q;

int isFull() {
    return (q.rear == MAX - 1);
}

int isEmpty() {
    return (q.front == -1 || q.front > q.rear);
}

void display() {
    if (isEmpty()) {
        printf("\nThe queue is empty, cannot display! (Queue Underflow)\n");
        return;
    }
    printf("\nThe updated queue elements are: \n");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d\t", q.data[i]);
    }
    printf("\n");
}

void enqueue() {
    if (isFull()) {
        printf("\nThe queue is full, cannot enqueue! (Queue Overflow)\n");
        return;
    }
    if (isEmpty()) {
        q.front = 0;
    }
    printf("\nEnter the data to be enqueued: ");
    scanf("%d", &(q.data[++(q.rear)]));
    printf("\n%d has been successfully enqueued!\n", q.data[q.rear]);
    display();
}

void dequeue() {
    if (isEmpty()) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    int dequeuedValue = q.data[q.front];
    q.front++;
    printf("\n%d has been successfully dequeued!\n", dequeuedValue);
    if (q.front > q.rear) {
        q.front = q.rear = -1;
    }
    display();
}

void peek() {
    if (isEmpty()) {
        printf("\nThe queue is empty, cannot peek! (Queue Underflow)\n");
        return;
    }
    printf("\n%d is at the front of the queue!\n", q.data[q.front]);
}

int main() {
    q.front = q.rear = -1;
    int option;
    do {
        printf("\nChoose any one of the following options:\n"
               "1. Enqueue\n"
               "2. Dequeue\n"
               "3. Peek\n"
               "4. Exit\n");
        scanf("%d", &(option));
        switch (option) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: printf("\nExiting program\n"); return 0;
            default: printf("\nInvalid option, Try again!");
        }
    } while (option != 4);
}