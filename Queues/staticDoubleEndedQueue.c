// Static Double Ended Queue

#include <stdio.h>
#define MAX 5

struct deque {
    int data[MAX];  // Array to store deque elements
    int front, rear;  // Pointers to the front and rear of the deque
} dq;

// Function to check if the deque is full
int isFull() {
    return ((dq.rear == MAX - 1 && dq.front == 0) || (dq.rear + 1 == dq.front));
}

// Function to check if the deque is empty
int isEmpty() {
    return (dq.front == -1);
}

// Function to display the elements of the deque
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

// Function to enqueue an element at the front of the deque
void enqueueFront() {
    if (isFull()) {
        printf("\nThe deque is full, cannot enqueue at front! (Deque Overflow)\n");
        return;
    }
    if (dq.front == -1) {
        dq.front = dq.rear = 0;  // Initialize pointers if deque is empty
    } else if (dq.front == 0) {
        dq.front = MAX - 1;  // Wrap around to the end of the array
    } else {
        dq.front--;  // Move front pointer towards the beginning
    }
    printf("\nEnter the data to be enqueued at front: ");
    scanf("%d", &(dq.data[dq.front]));  // Input data to be enqueued
    printf("\n%d has been successfully enqueued at front!\n", dq.data[dq.front]);
    display();
}

// Function to enqueue an element at the rear of the deque
void enqueueRear() {
    if (isFull()) {
        printf("\nThe deque is full, cannot enqueue at rear! (Deque Overflow)\n");
        return;
    }
    if (dq.front == -1) {
        dq.front = dq.rear = 0;  // Initialize pointers if deque is empty
    } else if (dq.rear == MAX - 1) {
        dq.rear = 0;  // Wrap around to the beginning of the array
    } else {
        dq.rear++;  // Move rear pointer towards the end
    }
    printf("\nEnter the data to be enqueued at rear: ");
    scanf("%d", &(dq.data[dq.rear]));  // Input data to be enqueued
    printf("\n%d has been successfully enqueued at rear!\n", dq.data[dq.rear]);
    display();
}

// Function to dequeue an element from the front of the deque
void dequeueFront() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot dequeue from front! (Deque Underflow)\n");
        return;
    }
    int dequeuedValue = dq.data[dq.front];
    if (dq.front == dq.rear) {
        dq.front = dq.rear = -1;  // Reset pointers if deque becomes empty
    } else {
        dq.front = (dq.front + 1) % MAX;  // Move front pointer circularly
    }
    printf("\n%d has been successfully dequeued from front!\n", dequeuedValue);
    display();
}

// Function to dequeue an element from the rear of the deque
void dequeueRear() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot dequeue from rear! (Deque Underflow)\n");
        return;
    }
    int dequeuedValue = dq.data[dq.rear];
    if (dq.front == dq.rear) {
        dq.front = dq.rear = -1;  // Reset pointers if deque becomes empty
    } else if (dq.rear == 0) {
        dq.rear = MAX - 1;  // Move rear pointer to the end of the array
    } else {
        dq.rear--;  // Move rear pointer towards the beginning
    }
    printf("\n%d has been successfully dequeued from rear!\n", dequeuedValue);
    display();
}

// Function to peek at the front element of the deque
void peekFront() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot peek from front! (Deque Underflow)\n");
        return;
    }
    printf("\n%d is at the front of the deque.\n", dq.data[dq.front]);
}

// Function to peek at the rear element of the deque
void peekRear() {
    if (isEmpty()) {
        printf("\nThe deque is empty, cannot peek from rear! (Deque Underflow)\n");
        return;
    }
    printf("\n%d is at the rear of the deque.\n", dq.data[dq.rear]);
}

// Main function
int main() {
    dq.front = dq.rear = -1;  // Initialize deque pointers
    int option;
    // Menu-driven loop for deque operations
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
        // Perform operation based on user input
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
    } while (option != 7);  // Continue loop until the user chooses to exit
}