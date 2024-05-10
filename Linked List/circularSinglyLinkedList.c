// Circular Singly Linked List

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular singly linked list
typedef struct node {
    int data;            // Data stored in the node
    struct node *next;   // Pointer to the next node
} node;

// Define a structure for the circular singly linked list
typedef struct list {
    struct node *head;  // Pointer to the head of the list
    int size;           // Size of the list
} list;

// Function to create a circular singly linked list
list *createList() {
    // Allocate memory for the new list
    list *newList = (list *) malloc(sizeof(list));
    // Check if memory allocation is successful
    if (newList == NULL) {
        printf("\nMemory could not be dynamically allocated for the new list!\n");
        exit(1);
    }
    // Initialize list attributes
    newList -> head = NULL;
    newList -> size = 0;
    return newList;
}

// Function to create a new node with given data
node *createNode(int data) {
    // Allocate memory for the new node
    node *newNode = (node *) malloc(sizeof(node));
    // Check if memory allocation is successful
    if (newNode == NULL) {
        printf("\nMemory could not be dynamically allocated for the new node!\n");
        exit(1);
    }
    // Initialize node attributes
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

// Function to display the circular singly linked list
void display(list *list) {
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        printf("\nThe list is empty, cannot display!\n");
        return;
    }
    // Traverse the list and display each node's data
    node *current = list -> head;
    printf("\nThe updated list elements are:\n");
    do {
        printf("%d\t", current -> data);
        current = current -> next;
    } while(current != list -> head);
    printf("\n");
}

// Function to free the circular singly linked list
void freeList(list *list) {
    // Check if the list is not empty
    if (list -> head != NULL || list -> size != 0) {
        node *current = list -> head, *nextNode = NULL;
        // Traverse the list and free each node
        do {
            nextNode = current -> next;
            free(current);
            current = nextNode;
        } while(current != list -> head);
    }
    // Free the list itself
    free(list);
    printf("\nThe list has been freed successfully!\n");
}

// Function to insert a new node at the front of the list
void insertAtFront(list *list, int data) {
    // Create a new node with the given data
    node *newNode = createNode(data);
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        // If empty, set the new node as the head
        list -> head = newNode;
        newNode -> next = newNode;
    } else {
        // If not empty, insert the new node at the front
        node *current = list -> head;
        newNode -> next = list -> head;
        while (current -> next != list -> head) {
            current = current -> next;
        }
        list -> head = newNode;
        current -> next = newNode;
    }
    // Increment the size of the list
    (list -> size)++;
    printf("\n%d has been successfully inserted at the front of the list!\n", data);
    display(list);
}

// Function to insert a new node at the end of the list
void insertAtEnd(list *list, int data) {
    // Create a new node with the given data
    node *newNode = createNode(data);
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        // If empty, set the new node as the head
        list -> head = newNode;
        newNode -> next = newNode;
    } else {
        // If not empty, insert the new node at the end
        node *current = list -> head;
        while (current -> next != list -> head) {
            current = current -> next;
        }
        newNode -> next = list -> head;
        current -> next = newNode;
    }
    // Increment the size of the list
    (list -> size)++;
    printf("\n%d has been successfully inserted at the end of the list!\n", data);
    display(list);
}

// Function to insert a new node in order in the list
void insertByOrder(list *list, int data) {
    // Create a new node with the given data
    node *newNode = createNode(data);
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        // If empty, set the new node as the head
        list -> head = newNode;
        newNode -> next = newNode;
    } else if (list -> head -> data >= newNode -> data) {
        // If new node's data is less than head's data, insert at the front
        node *current = list -> head;
        while (current -> next != list -> head) {
            current = current -> next;
        }
        current -> next = newNode;
        newNode -> next = list -> head;
        list -> head = newNode;
    } else {
        // If not empty, insert the new node in order
        node *current = list -> head;
        while (current -> next != list -> head && newNode -> data >= current -> next -> data) {
            current = current -> next;
        }
        newNode -> next = current -> next;
        current -> next = newNode;
    }
    // Increment the size of the list
    (list -> size)++;
    printf("\n%d has been successfully inserted into the list!\n", data);
    display(list);
}

// Function to search for a node by its position in the list
void searchByPosition(list *list, int position) {
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        printf("\nThe list is empty, cannot search at specified position!\n");
        return;
    }
    // Initialize counter and traverse the list to find the node at the specified position
    node *current = list -> head;
    int count = 0;
    do {
        current = current -> next;
        count++;
    } while (current != list -> head && count < position - 1);
    // Display the data of the node at the specified position
    printf("\n%d is at position %d\n", current -> data, position);
}

// Function to search for a node by its data in the list
int searchByKey(list *list, int key) {
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        printf("\nThe list is empty, cannot search!\n");
        return -1;
    }
    // Initialize variables for position and flag to indicate if the key is found
    int position = 1;
    node *current = list -> head;
    // Traverse the list to find the node with the specified key
    do {
        if (current -> data == key) {
            return position;
        }
        current = current -> next;
        position++;
    } while (current != list -> head);
    // Return -1 if key is not found
    return -1;
}

// Function to delete a node at a specified position in the circular doubly linked list
void deleteByPosition(list *list, int position) {
    // Initialize pointers for traversal and count of nodes visited
    node *current = list -> head, *previous = NULL;
    int count = 0;
    // Traverse the list until the desired position or end of list is reached
    while (current -> next != list -> head && count < position) {
        previous = current;
        current = current -> next;
        count++;
    }
    // Check if the node to be deleted is the head node
    if (previous == NULL) {
        // If the node to be deleted is the head, adjust pointers accordingly
        while (current -> next != list -> head) {
            current = current -> next;
        }
        current -> next = list -> head -> next;
        // Free the memory occupied by the head node
        free(list -> head);
        // Update the head pointer to the next node
        list -> head = current -> next;
    } else {
        // If the node to be deleted is not the head, adjust the previous node's next pointer
        previous -> next = current -> next;
    }
    // Decrement the size of the list
    (list -> size)--;
    // Display the updated list
    display(list);
}

// Function to delete a node by its data in the list
void deleteByKey(list *list, int key) {
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        printf("\nThe list is empty, cannot delete!\n");
        return;
    }
    // Initialize variables for flag and position of the node to be deleted
    int position = searchByKey(list, key);
    if (position == -1) {
        printf("\nThe key could not be found in the list!\n");
        return;
    }
    // Initialize flag to indicate if the key is found
    int flag = 0;
    node *current = list -> head;
    // Traverse the list to find the node with the specified key
    do {
        if (current -> data == key) {
            flag = 1;
            break;
        }
        current = current -> next;
    } while(current != list -> head);
    // Check if the key is found and delete the node
    if (flag == 1) {
        node *prev = NULL;
        // Traverse the list to find the previous node of the node to be deleted
        for (int i = 1; i < position; i++) {
            prev = current;
            current = current -> next;
        }
        if (current == list -> head) {
            // If the node to be deleted is the head, update head pointer
            if (list -> size == 1) {
                list -> head = NULL;
            } else {
                list -> head = current -> next;
                prev -> next = list -> head;
            }
        } else {
            // Update previous node's next pointer to skip the node to be deleted
            prev -> next = current -> next;
        }
        // Free memory occupied by the node to be deleted
        free(current);
        // Decrement the size of the list
        (list -> size)--;
        printf("\n%d has been successfully deleted from the list!\n", key);
        display(list);
    }
}

// Function to reverse the order of nodes in the list
void reverseList(list *list) {
    node *current = list -> head, *previous = NULL, *nextNode = NULL;
    // Traverse the list and reverse the links between nodes
    do {
        nextNode = current -> next;
        current -> next = previous;
        previous = current;
        current = nextNode;
    } while (current != list -> head);
    // Adjust the head pointer to point to the last node
    list -> head -> next = previous;
    list -> head = previous;
    // Display the updated list
    display(list);
}

// Function to create a copy of the original list
void copyList(list *originalList) {
    // Create a new list to store the copied elements
    list *copiedList = createList();
    // Initialize a pointer to traverse the original list
    node *current = originalList -> head;
    // Loop through the original list and insert each element at the end of the copied list
    for (int i = 0; i < originalList -> size; i++) {
        insertAtEnd(copiedList, current -> data);
        current = current -> next;
    }
    // Print a message indicating successful copying
    printf("\nThe list has been copied successfully!\n");
    // Display the copied list
    display(copiedList);
    // Free the memory occupied by the copied list
    freeList(copiedList);
}

// Main function
int main() {
    // Declare variables
    int option, position, key, data;
    // Create a circular singly linked list
    list *list = createList();
    // Menu-driven loop for list operations
    do {
        printf("\nChoose any one of the following options:\n"
        "1. Insert at front\n"
        "2. Insert at end\n"
        "3. Insert by order\n"
        "4. Delete by position\n"
        "5. Delete by key\n"
        "6. Search by position\n"
        "7. Search by key\n"
        "8. Reverse the list\n"
        "9. Exit\n");
        scanf("%d", &option);
        // Perform operation based on user input
        switch(option) {
            case 1:
                // Insert data at the front of the list
                printf("\nEnter the data to be inserted at the front: ");
                scanf("%d", &data);
                insertAtFront(list, data);
                break;
            case 2:
                // Insert data at the end of the list
                printf("\nEnter the data to be inserted at the end: ");
                scanf("%d", &data);
                insertAtEnd(list, data);
                break;
            case 3:
                // Insert data in order in the list
                printf("\nEnter the data to be inserted in order: ");
                scanf("%d", &data);
                insertByOrder(list, data);
                break;
            case 4:
                // Delete data by position in the list
                printf("\nEnter the position for the data to be deleted at: ");
                scanf("%d", &position);
                deleteByPosition(list, position);
                break;
            case 5:
                // Delete data by key in the list
                printf("\nEnter the key to be deleted: ");
                scanf("%d", &key);
                deleteByKey(list, key);
                break;
            case 6:
                // Search data by position in the list
                printf("\nEnter the position for the data to be searched at: ");
                scanf("%d", &position);
                searchByPosition(list, position);
                break;
            case 7:
                // Search data by key in the list
                printf("\nEnter the key to be searched: ");
                scanf("%d", &key);
                searchByPosition(list, key);
                break;
            case 8:
                // Reverse the list
                reverseList(list);
                break;
            case 9:
                // Copy the list
                copyList(list);
                break;
            case 10:
                // Free the list and exit the program
                freeList(list);
                break;
            default:
                printf("\nChoose a valid option!\n");
        }
    } while (option != 10); // Continue loop until the user chooses to exit
}