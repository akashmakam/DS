// Static Ordinary Queue

#include <stdio.h>
#define MAX 5

struct queue {
    int data[MAX];  // Array to store queue elements
    int front, rear;  // Pointers to the front and rear of the queue
} q;

// Function to check if the queue is full
int isFull() {
    return (q.rear == MAX - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (q.front == -1 || q.front > q.rear);
}

// Function to display the elements of the queue
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

// Function to enqueue an element into the queue
void enqueue() {
    if (isFull()) {
        printf("\nThe queue is full, cannot enqueue! (Queue Overflow)\n");
        return;
    }
    if (isEmpty()) {
        q.front = 0;  // Set front pointer if queue is empty
    }
    printf("\nEnter the data to be enqueued: ");
    scanf("%d", &(q.data[++(q.rear)]));  // Input data to be enqueued
    printf("\n%d has been successfully enqueued!\n", q.data[q.rear]);
    display();
}

// Function to dequeue an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    int dequeuedValue = q.data[q.front];  // Store dequeued value
    q.front++;  // Move front pointer to dequeue element
    printf("\n%d has been successfully dequeued!\n", dequeuedValue);
    if (q.front > q.rear) {
        q.front = q.rear = -1;  // Reset pointers if queue becomes empty
    }
    display();
}

// Function to peek at the front element of the queue
void peek() {
    if (isEmpty()) {
        printf("\nThe queue is empty, cannot peek! (Queue Underflow)\n");
        return;
    }
    printf("\n%d is at the front of the queue!\n", q.data[q.front]);
}

// Main function
int main() {
    q.front = q.rear = -1;  // Initialize queue pointers
    int option;
    // Menu-driven loop for queue operations
    do {
        printf("\nChoose any one of the following options:\n"
               "1. Enqueue\n"
               "2. Dequeue\n"
               "3. Peek\n"
               "4. Exit\n");
        scanf("%d", &(option));
        // Perform operation based on user input
        switch (option) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: printf("\nExiting program\n"); return 0;
            default: printf("\nInvalid option, Try again!");
        }
    } while (option != 4);  // Continue loop until the user chooses to exit
}