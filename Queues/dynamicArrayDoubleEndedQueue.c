// Double Ended Queue

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the double-ended queue
typedef struct queue {
    int *data;      // Array to store queue elements
    int size;       // Maximum capacity of the queue
    int front;      // Index of the front element
    int rear;       // Index of the rear element
} q;

// Function to create a double-ended queue with the given size
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
    return (q -> front == -1 && q -> rear == -1);
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

// Function to enqueue an element at the front of the queue
void enqueueAtFront(q *q, int data) {
    // Check if insertion at front is possible
    if (q -> front == 0) {
        printf("\nInsertion at front is not possible!\n");
        return;
    }
    // If queue is empty, adjust front and rear indices
    if (isEmpty(q)) {
        q -> front = 0;
        q -> data[++(q -> rear)] = data;
    } else if (q -> front > 0) {
        q -> data[--(q -> front)] = data;
    }
    printf("\n%d enqueued at front successfully!\n", data);
    display(q);
}

// Function to enqueue an element at the end of the queue
void enqueueAtEnd(q *q, int data) {
    // Check if insertion at end is possible
    if (isFull(q)) {
        printf("\nInsertion at end is not possible!\n");
        return;
    }
    // If queue is empty, adjust front index
    if (isEmpty(q))
        q -> front = 0;
    // Increment rear index and insert data
    q -> data[++(q -> rear)] = data;
    printf("\n%d enqueued at end successfully!\n", data);
    display(q);
}

// Function to dequeue an element from the front of the queue
void dequeueAtFront(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nQueue is empty, cannot dequeue from front!\n");
        return;
    }
    // Dequeue data from front and adjust front index
    int dequeuedData = q -> data[(q -> front)++];
    // If queue becomes empty, reset front and rear indices
    if (q -> front > q -> rear) {
        q -> front = q -> rear = -1;
    }
    printf("\n%d dequeued from front successfully!\n", dequeuedData);
    display(q);
}

// Function to dequeue an element from the end of the queue
void dequeueAtEnd(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nQueue is empty, cannot dequeue from end!\n");
        return;
    }
    // Dequeue data from end and decrement rear index
    int dequeuedData = q -> data[(q -> rear)--];
    // If queue becomes empty, reset front and rear indices
    if (q -> front > q -> rear) {
        q -> front = q -> rear = -1;
    }
    printf("\n%d dequeued from end successfully!\n", dequeuedData);
    display(q);
}

// Function to peek at the front element of the queue
void peekAtFront(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nQueue is empty, cannot peek at front!\n");
        return;
    }
    // Display the front element of the queue
    printf("\nPeek at front: %d\n", q -> data[q -> front]);
}

// Function to peek at the rear element of the queue
void peekAtRear(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nQueue is empty, cannot peek at rear!\n");
        return;
    }
    // Display the rear element of the queue
    printf("\nPeek at rear: %d\n", q -> data[q -> rear]);
}

// Main function
int main() {
    // Declare variables
    int option, data, size;
    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);
    // Create a double-ended queue
    q *q = createQueue(size);
    // Menu-driven loop for queue operations
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
        // Perform operation based on user input
        switch (option) {
            case 1:
                // Enqueue data at the front of the queue
                printf("\nEnter the data to be enqueued at front: ");
                scanf("%d", &data);
                enqueueAtFront(q, data);
                break;
            case 2:
                // Enqueue data at the end of the queue
                printf("\nEnter the data to be enqueued at end: ");
                scanf("%d", &data);
                enqueueAtEnd(q, data);
                break;
            case 3:
                // Dequeue data from the front of the queue
                dequeueAtFront(q);
                break;
            case 4:
                // Dequeue data from the end of the queue
                dequeueAtEnd(q);
                break;
            case 5:
                // Peek at the front element of the queue
                peekAtFront(q);
                break;
            case 6:
                // Peek at the rear element of the queue
                peekAtRear(q);
                break;
            case 7:
                // Free the queue and exit the program
                free(q -> data);
                free(q);
                printf("\nThe queue has been freed successfully!\n");
                break;
            default:
                printf("\nInvalid option! Please choose again.\n");
        }
    } while (option != 7); // Continue loop until the user chooses to exit
    return 0;
}