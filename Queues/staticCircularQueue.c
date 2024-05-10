// Static Circular Queue

#include <stdio.h>

#define MAX 5

struct queue {
    int data[MAX];
    int front, rear;
} q;

int isFull() {
    return ((q.rear + 1) % MAX == q.front);
}

int isEmpty() {
    return (q.front == -1);
}

void display() {
    if (isEmpty()) {
        printf("\nThe queue is empty, cannot display! (Queue Underflow)\n");
        return;
    }
    printf("\nThe updated queue elements are: \n");
    int i = q.front;
    do {
        printf("%d\t", q.data[i]);
        i = (i + 1) % MAX;
    } while (i != (q.rear + 1) % MAX);
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
    q.rear = (q.rear + 1) % MAX;
    printf("\nEnter the data to be enqueued: ");
    scanf("%d", &(q.data[q.rear]));
    printf("\n%d has been successfully enqueued!\n", q.data[q.rear]);
    display();
}


void dequeue() {
    if (isEmpty()) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    int dequeuedValue = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    printf("\n%d has been successfully dequeued!\n", dequeuedValue);
    if (q.front == q.rear) {
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
            default: printf("\nInvalid option, Try again!\n");
        }
    } while (option != 4);
}