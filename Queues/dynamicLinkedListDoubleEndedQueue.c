// Dynamic Double Ended Queue

#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
typedef struct node {
    int data;           // Data of the node
    struct node *next;  // Pointer to the next node
} node;

// Define a queue structure to manage the double-ended queue
typedef struct q {
    int size;           // Number of elements in the queue
    struct node *front; // Pointer to the front of the queue
    struct node *rear;  // Pointer to the rear of the queue
} q;

// Function to check if the queue is empty
int isEmpty(q *q) {
    return (q -> size == 0);
}

// Function to create an empty double-ended queue
q *createQ() {
    // Allocate memory for the queue structure
    q *newQ = (q *)malloc(sizeof(q));
    // Check if memory allocation is successful
    if (newQ == NULL) {
        printf("\nMemory could not be dynamically allocated for the new queue.\n");
        return NULL;
    }
    // Initialize queue attributes
    newQ -> size = 0;
    newQ -> front = newQ -> rear = NULL;
    return newQ;
}

// Function to create a new node with user input data
node *createNode() {
    // Allocate memory for the new node
    node *newNode = (node *)malloc(sizeof(node));
    // Check if memory allocation is successful
    if (newNode == NULL) {
        printf("\nMemory could not be dynamically allocated for the new node.\n");
        return NULL;
    }
    // Input data for the new node
    printf("\nEnter the data to be enqueued: ");
    scanf("%d", &(newNode -> data));
    // Initialize next pointer to NULL
    newNode -> next = NULL;
    return newNode;
}

// Function to display the elements of the double-ended queue
void displayQ(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot display! (Queue Underflow)\n");
        return;
    }
    // Traverse the queue and display elements
    node *current = q -> front;
    printf("\nThe updated queue elements are:\n");
    while (current != NULL) {
        printf("%d\t", current -> data);
        current = current -> next;
    }
    printf("\n");
}

// Function to enqueue an element at the front of the double-ended queue
void enqueueAtFront(q *q) {
    // Create a new node with user input data
    node *newNode = createNode();
    // Check if the queue is empty
    if (isEmpty(q)) {
        q -> front = q -> rear = newNode;
    } else {
        newNode -> next = q -> front;
        q -> front = newNode;
    }
    // Increment the queue size
    (q -> size)++;
    // Display the updated queue
    printf("\n%d has been successfully enqueued at the front of the queue!\n", newNode -> data);
    displayQ(q);
}

// Function to enqueue an element at the rear of the double-ended queue
void enqueueAtRear(q *q) {
    // Create a new node with user input data
    node *newNode = createNode();
    // Check if the queue is empty
    if (isEmpty(q)) {
        q -> front = q -> rear = newNode;
    } else {
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }
    // Increment the queue size
    (q -> size)++;
    // Display the updated queue
    printf("\n%d has been successfully enqueued at the rear of the queue!\n", newNode -> data);
    displayQ(q);
}

// Function to dequeue an element from the front of the double-ended queue
void dequeueAtFront(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    // Remove the front node and adjust front pointer
    node *temp = q -> front;
    q -> front = q -> front -> next;
    // Update rear pointer if queue becomes empty
    if (q -> front == NULL) {
        q -> rear = NULL;
    }
    // Display the dequeued data and free the memory
    printf("\n%d has been successfully dequeued from the front of the queue!\n", temp -> data);
    free(temp);
    // Decrement the queue size
    (q -> size)--;
    // Display the updated queue
    displayQ(q);
}

// Function to dequeue an element from the rear of the double-ended queue
void dequeueAtRear(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    // Traverse the queue to find the second last node
    node *current = q -> front;
    while (current -> next != q -> rear) {
        current = current -> next;
    }
    // Display the dequeued data and free the memory
    printf("\n%d has been successfully dequeued from the rear of the queue!\n", q -> rear -> data);
    free(q -> rear);
    // Update rear pointer and adjust next pointer of second last node
    q -> rear = current;
    q -> rear -> next = NULL;
    // Decrement the queue size
    (q -> size)--;
    // Display the updated queue
    displayQ(q);
}

// Function to peek at the front element of the double-ended queue
void peekAtFront(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot peek! (Queue Underflow)\n");
        return;
    }
    // Display the front element of the queue
    printf("\n%d is at the front of the queue.\n", q -> front -> data);
}

// Function to peek at the rear element of the double-ended queue
void peekAtRear(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot peek! (Queue Underflow)\n");
        return;
    }
    // Display the rear element of the queue
    printf("\n%d is at the rear of the queue.\n", q -> rear -> data);
}

// Function to free the memory allocated for the double-ended queue
void freeQ(q *q) {
    // Check if the queue is not empty
    if (!isEmpty(q)) {
        node *current = q -> front, *nextNode;
        // Traverse the queue and free memory for each node
        while (current != NULL) {
            nextNode = current -> next;
            free(current);
            current = nextNode;
        }
    }
    // Free memory for the queue structure
    free(q);
    printf("\nThe queue has been freed successfully!\n");
}

// Main function
int main() {
    int option;
    // Create an empty double-ended queue
    q *q = createQ();
    // Menu-driven loop for queue operations
    do {
        printf("\nChoose any one of the following options:\n"
               "1. Enqueue at front\n"
               "2. Enqueue at rear\n"
               "3. Dequeue at front\n"
               "4. Dequeue at rear\n"
               "5. Peek at front\n"
               "6. Peek at rear\n"
               "7. Exit\n");
        scanf("%d", &option);
        // Perform operation based on user input
        switch (option) {
            case 1: enqueueAtFront(q); break;
            case 2: enqueueAtRear(q); break;
            case 3: dequeueAtFront(q); break;
            case 4: dequeueAtRear(q); break;
            case 5: peekAtFront(q); break;
            case 6: peekAtRear(q); break;
            case 7: freeQ(q); break;
            default: printf("\nInvalid option, Try again!\n");
        }
    } while (option != 7); // Continue loop until the user chooses to exit
    return 0;
}