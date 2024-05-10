// Static Double Ended Queue

#include <stdio.h>
#define MAX 5

struct deque {
    int data[MAX];
    int front, rear;
} dq;

int isFull() {
    return ((dq.rear == MAX - 1 && dq.front == 0) || (dq.rear + 1 == dq.front));
}

int isEmpty() {
    return (dq.front == -1);
}

void display() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot display! (Deque Underflow)\n");
        return;
    }
    printf("\nThe updated deque elements are: \n");
    int i = dq.front;
    while (i != dq.rear) {
        printf("%d\t", dq.data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", dq.data[dq.rear]);
}

void enqueueFront() {
    if (isFull()) {
        printf("\nThe deque is full, cannot enqueue at front! (Deque Overflow)\n");
        return;
    }
    if (dq.front == -1) {
        dq.front = dq.rear = 0;
    } else if (dq.front == 0) {
        dq.front = MAX - 1;
    } else {
        dq.front--;
    }
    printf("\nEnter the data to be enqueued at front: ");
    scanf("%d", &(dq.data[dq.front]));
    printf("\n%d has been successfully enqueued at front!\n", dq.data[dq.front]);
    display();
}

void enqueueRear() {
    if (isFull()) {
        printf("\nThe deque is full, cannot enqueue at rear! (Deque Overflow)\n");
        return;
    }
    if (dq.front == -1) {
        dq.front = dq.rear = 0;
    } else if (dq.rear == MAX - 1) {
        dq.rear = 0;
    } else {
        dq.rear++;
    }
    printf("\nEnter the data to be enqueued at rear: ");
    scanf("%d", &(dq.data[dq.rear]));
    printf("\n%d has been successfully enqueued at rear!\n", dq.data[dq.rear]);
    display();
}

void dequeueFront() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot dequeue from front! (Deque Underflow)\n");
        return;
    }
    int dequeuedValue = dq.data[dq.front];
    if (dq.front == dq.rear) {
        dq.front = dq.rear = -1;
    } else {
        dq.front = (dq.front + 1) % MAX;
    }
    printf("\n%d has been successfully dequeued from front!\n", dequeuedValue);
    display();
}

void dequeueRear() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot dequeue from rear! (Deque Underflow)\n");
        return;
    }
    int dequeuedValue = dq.data[dq.rear];
    if (dq.front == dq.rear) {
        dq.front = dq.rear = -1;
    } else if (dq.rear == 0) {
        dq.rear = MAX - 1;
    } else {
        dq.rear--;
    }
    printf("\n%d has been successfully dequeued from rear!\n", dequeuedValue);
    display();
}

void peekFront() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot peek from front! (Deque Underflow)\n");
        return;
    }
    printf("\n%d is at the front of the deque.\n", dq.data[dq.front]);
}

void peekRear() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot peek from rear! (Deque Underflow)\n");
        return;
    }
    printf("\n%d is at the rear of the deque.\n", dq.data[dq.rear]);
}

int main() {
    dq.front = dq.rear = -1;
    int option;
    do {
        printf("\nChoose any one of the following options:\n"
               "1. Enqueue at front\n"
               "2. Enqueue at rear\n"
               "3. Dequeue from front\n"
               "4. Dequeue from rear\n"
               "5. Peek at front\n"
               "6. Peek at rear\n"
               "7. Exit\n");
        scanf("%d", &(option));
        switch (option) {
            case 1: enqueueFront(); break;
            case 2: enqueueRear(); break;
            case 3: dequeueFront(); break;
            case 4: dequeueRear(); break;
            case 5: peekFront(); break;
            case 6: peekRear(); break;
            case 7: printf("\nExiting program\n"); return 0;
            default: printf("\nInvalid option, Try again!");
        }
    } while (option != 7);
}
