// Dynamic Ordinary Queue

#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
typedef struct node {
    int data;           // Data of the node
    struct node *next;  // Pointer to the next node
} node;

// Define a queue structure to manage the ordinary queue
typedef struct q {
    int size;           // Number of elements in the queue
    struct node *front; // Pointer to the front of the queue
    struct node *rear;  // Pointer to the rear of the queue
} q;

// Function to check if the queue is empty
int isEmpty(q *q) {
    return (q -> size == 0);
}

// Function to create an empty ordinary queue
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

// Function to display the elements of the ordinary queue
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

// Function to enqueue an element into the ordinary queue
void enqueue(q *q) {
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
    printf("\n%d has been successfully enqueued!\n", newNode -> data);
    displayQ(q);
}

// Function to dequeue an element from the ordinary queue
void dequeue(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot dequeue! (Queue Underflow)\n");
        return;
    }
    // Remove the front node and adjust front pointer
    node *temp = q -> front;
    q -> front = q -> front -> next;
    // Display the dequeued data and free the memory
    printf("\n%d has been successfully dequeued!\n", temp -> data);
    free(temp);
    // Decrement the queue size
    (q -> size)--;
    // Display the updated queue
    displayQ(q);
}

// Function to peek at the front element of the ordinary queue
void peek(q *q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("\nThe queue is empty, cannot peek! (Queue Underflow)\n");
        return;
    }
    // Display the front element of the queue
    printf("\n%d is at the front of the queue.\n", q -> front -> data);
}

// Function to free the memory allocated for the ordinary queue
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
    // Create an empty ordinary queue
    q *q = createQ();
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
            case 1: enqueue(q); break;
            case 2: dequeue(q); break;
            case 3: peek(q); break;
            case 4: freeQ(q); break;
            default: printf("\nInvalid option, Try again!\n");
        }
    } while (option != 4); // Continue loop until the user chooses to exit
    return 0;
}