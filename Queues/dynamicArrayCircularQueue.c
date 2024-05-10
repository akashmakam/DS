// Circular Queue

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the circular queue
typedef struct queue {
    int *data;      // Array to store queue elements
    int size;       // Maximum capacity of the queue
    int front;      // Index of the front element
    int rear;       // Index of the rear element
} q;

// Function to create a circular queue with the given size
q *createQueue(int size) {
    // Allocate memory for the new queue
    q *newQ = (q *) malloc(sizeof(q));
    // Check if memory allocation is successful
    if (newQ == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue!\n");
        exit(1);
    }
    // Allocate memory for the queue data array
    newQ -> data = (int *) malloc(size * sizeof(int));
    // Check if memory allocation is successful
    if (newQ -> data == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue!\n");
        exit(1);
    }
    // Initialize queue attributes
    newQ -> size = size;
    newQ -> front = newQ -> rear = -1;
    return newQ;
}

// Function to check if the queue is empty
int isEmpty(q *q) {
    return(q -> front == -1);
}

// Function to check if the queue is full
int isFull(q *q) {
    return(((q -> rear + 1) % q -> size) == q -> front);
}

// Function to display the elements of the queue
void display(q *q) {
    // Check if the queue is empty
    if(isEmpty(q)) {
        printf("\nThe queue is empty, cannot display!\n");
        return;
    }
    // Display queue elements
    printf("\nThe updated queue elements are:\n");
    int i = q -> front;
    do {
        printf("%d\t", q -> data[i]);
        i = (i + 1) % q -> size;
    } while (i != (q -> rear + 1) % q -> size);
    printf("\n");
}

// Function to enqueue an element into the queue
void enqueue(q *q, int data) {
    // Check if the queue is full
    if(isFull(q)) {
        printf("\nThe queue is full, cannot enqueue!\n");
        return;
    }
    // If queue is empty, adjust front index
    if(isEmpty(q)) {
        q -> front = 0;
    }
    // Increment rear index and insert data
    q -> rear = (q -> rear + 1) % q -> size;
    q -> data[(q -> rear)] = data;
    printf("\n%d has been successfully enqueued!\n", data);
    display(q);
}

// Function to dequeue an element from the queue
void dequeue(q *q) {
    // Check if the queue is empty
    if(isEmpty(q)) {
        printf("\nThe queue is empty, cannot dequeue!\n");
        return;
    }
    // Dequeue data and adjust front index
    int dequeuedData;
    dequeuedData = q -> data[q -> front];
    q -> front = (q -> front + 1) % q -> size;
    // If queue becomes empty, reset front and rear
    if (q -> front == q -> rear) {
        q -> front = q -> rear = -1;
    }
    printf("\n%d has been dequeued from the list successfully!\n", dequeuedData);
    display(q);
}

// Function to peek at the front element of the queue
void peek(q *q) {
    // Check if the queue is empty
    if(isEmpty(q)) {
        printf("\nThe queue is empty, cannot peek!\n");
        return;
    }
    // Display the front element of the queue
    printf("%d is at the front of the queue!\n", q -> data[q -> front]);
}

// Main function
int main() {
    // Declare variables
    int option, data, size;
    printf("\nEnter the size of the queue: ");
    scanf("%d", &(size));
    // Create a circular queue
    q *q = createQueue(size);
    do {
        printf("\nChoose any one of the following options:\n"
        "1. Enqueue\n"
        "2. Dequeue\n"
        "3. Peek\n"
        "4. Exit\n");
        scanf("%d", &option);
        // Perform operation based on user input
        switch (option) {
            case 1:
                // Enqueue data into the queue
                printf("\nEnter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                // Dequeue data from the queue
                dequeue(q);
                break;
            case 3:
                // Peek at the front element of the queue
                peek(q);
                break;
            case 4:
                // Free the queue and exit the program
                free(q -> data);
                free(q);
                printf("\nThe queue has been freed successfully!\n");
                break;
            default:
                printf("\nChoose a valid option!\n");
        }
    } while(option != 4); // Continue loop until the user chooses to exit
    return 0;
}