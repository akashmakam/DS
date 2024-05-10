// Priority Queue (Insertion is ordered, deletion is normal)

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the priority queue
typedef struct queue {
    int *data;      // Array to store queue elements
    int size;       // Maximum capacity of the queue
    int front;      // Index of the front element
    int rear;       // Index of the rear element
} q;

// Function to create a priority queue with the given size
q *createQueue(int size) {
    // Allocate memory for the new queue
    q *newQ = (q *)malloc(sizeof(q));
    // Check if memory allocation is successful
    if (newQ == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue!\n");
        exit(1);
    }
    // Allocate memory for the queue data array
    newQ -> data = (int *)malloc(size * sizeof(int));
    // Check if memory allocation is successful
    if (newQ -> data == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue!\n");
        free(newQ);
        exit(1);
    }
    // Initialize queue attributes
    newQ -> size = size;
    newQ -> front = newQ -> rear = -1;
    return newQ;
}

// Function to check if the queue is empty
int isEmpty(q *q) {
    return (q -> front == -1 || q -> front > q -> rear);
}

// Function to check if the queue is full
int isFull(q *q) {
    return (q -> rear == q -> size - 1);
}

// Function to display the elements of the queue
void display(q *q) {
    // Check if the queue is empty
    if(isEmpty(q)) {
        printf("\nQueue is empty, cannot display!\n");
        return;
    }
    // Display queue elements
    printf("\nThe updated queue elements are:\n");
    for (int i = q -> front; i <= q -> rear; i++) {
        printf("%d\t", q -> data[i]);
    }
    printf("\n");
}

// Function to enqueue an element into the priority queue
void enqueue(q *q, int data) {
    // Check if the queue is full
    if(isFull(q)) {
        printf("\nQueue is full, cannot enqueue!\n");
        return;
    }
    // If the queue is empty or data is less than or equal to the front element, enqueue at the front
    if (isEmpty(q) || data <= q -> data[q -> front]) {
        q -> front--;
        q -> data[q -> front] = data;
    } else {
        // Otherwise, find the correct position for the new element based on its priority
        int count = q -> rear + 1;
        while (count > q -> front && data < q -> data[count - 1]) {
            q -> data[count] = q -> data[count - 1];
            count--;
        }
        // Insert the new element at its correct position
        q -> data[count] = data;
    }
    // Increment the rear index
    (q -> rear)++;
    // Display the updated queue
    display(q);
}

// Function to dequeue an element from the front of the queue
void dequeue(q *q) {
    // Check if the queue is empty
    if(isEmpty(q)) {
        printf("\nQueue is empty, cannot dequeue!\n");
        return;
    }
    // Dequeue data from the front and adjust front index
    int dequeuedData = q -> data[(q -> front)++];
    // If the queue becomes empty, reset front and rear indices
    if (isEmpty(q)) {
        q -> front = q -> rear = -1;
    }
    printf("\n%d has been dequeued from the queue!\n", dequeuedData);
    // Display the updated queue
    display(q);
}

// Function to peek at the front element of the queue
void peek(q *q) {
    // Check if the queue is empty
    if(isEmpty(q)) {
        printf("\nQueue is empty, cannot peek!\n");
        return;
    }
    // Display the front element of the queue
    printf("\n%d is at the front of the queue!\n", q -> data[q -> front]);
}

// Main function
int main() {
    // Declare variables
    int option, data, size;
    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);
    // Create a priority queue
    q *q = createQueue(size);
    // Menu-driven loop for queue operations
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
                // Enqueue data into the priority queue
                printf("\nEnter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                // Dequeue data from the priority queue
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