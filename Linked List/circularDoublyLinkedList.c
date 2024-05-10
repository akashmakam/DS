// Circular Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular doubly linked list
typedef struct node {
    int data;
    struct node *next;
    struct node *previous;
} node;

// Define a structure for the circular doubly linked list
typedef struct list {
    struct node *head;
    int size;
} list;

// Function to create a circular doubly linked list
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
    newNode -> previous = NULL;
    return newNode;
}

// Function to free the circular doubly linked list
void freeList(list *list) {
    // Check if the list is not empty
    if (list -> head != NULL) {
        // Free each node in the list
        node *current = list -> head, *nextNode = NULL;
        do {
            nextNode = current -> next;
            free(current);
            current = nextNode;
        } while (current != list -> head);
    }
    // Free the list itself
    free(list);
    printf("\nThe list has been freed successfully!\n");
}

// Function to display the circular doubly linked list
void display(list *list) {
    // Check if the list is empty
    if (list -> head == NULL) {
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

// Function to insert a new node at the front of the list
void insertAtFront(list *list, int data) {
    // Create a new node with the given data
    node *newNode = createNode(data);
    // Check if the list is empty
    if (list -> head == NULL) {
        // If empty, set the new node as the head
        list -> head = newNode;
        newNode -> next = newNode;
        newNode -> previous = newNode;
    } else {
        // If not empty, insert the new node at the front
        newNode -> next = list -> head;
        newNode -> previous = list -> head -> previous;
        list -> head -> previous -> next = newNode;
        list -> head -> previous = newNode;
        list -> head = newNode;
    }
    // Increment the size of the list
    (list -> size)++;
    printf("\n%d has been successfully inserted into the list at the front!\n", data);
    display(list);
}

// Function to insert a new node at the rear of the list
void insertAtRear(list *list, int data) {
    // Create a new node with the given data
    node *newNode = createNode(data);
    // Check if the list is empty
    if (list -> head == NULL) {
        // If empty, set the new node as the head
        list -> head = newNode;
        newNode -> next = newNode;
        newNode -> previous = newNode;
    } else {
        // If not empty, insert the new node at the rear
        newNode -> next = list -> head;
        newNode -> previous = list -> head -> previous;
        list -> head -> previous -> next = newNode;
        list -> head -> previous = newNode;
    }
    // Increment the size of the list
    (list -> size)++;
    printf("\n%d has been successfully inserted into the list at the rear!\n", data);
    display(list);
}

// Function to insert a new node in order in the list
void insertByOrder(list *list) {
    int data;
    // Prompt user to enter the data to be stored in the new node
    printf("\nEnter the data to be stored in the new node: ");
    scanf("%d", &data);
    // Create a new node with the given data
    node *newNode = createNode(data);
    // Check if the list is empty or the new node's data is smaller than the head's data
    if (list -> head == NULL || list -> size == 0 || newNode -> data <= list -> head -> data) {
        // If empty or the new node's data is smaller, insert at the front
        newNode -> previous = list -> head -> previous;
        newNode -> previous -> next = newNode;
        list -> head -> previous = newNode;
        newNode -> next = list -> head;
        list -> head = newNode;
    } else {
        // Traverse the list to find the correct position to insert the new node
        node *current = list -> head;
        while (current -> next != list -> head && current -> next -> data < newNode -> data) {
            current = current -> next;
        }
        // Insert the new node in the correct position
        newNode -> next = current -> next;
        newNode -> previous = current;
        current -> next = newNode;
        newNode -> next -> previous = newNode;
    }
    // Increment the size of the list
    (list -> size)++;
    printf("\n%d has been inserted into the list successfully!\n", data);
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
    int count = 0;
    node *current = list -> head;
    while ((count < position - 1) && (current -> next != list -> head)) {
        current = current -> next;
        count++;
    }
    // Display the data of the node at the specified position
    printf("\n%d is at position %d\n", current -> data, position);
}

// Function to search for a node by its data in the list
void searchByKey(list *list, int key) {
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        printf("\nThe list is empty, cannot search!\n");
        return;
    }
    // Initialize variables for position and flag to indicate if the key is found
    int position = 1, flag = 0;
    node *current = list -> head;
    // Traverse the list to find the node with the specified key
    do {
        if (current -> data == key) {
            flag = 1;
            break;
        }
        current = current -> next;
        position++;
    } while(current != list -> head);
    // Check if the key is found and display the result
    if (flag == 0) {
        printf("\n%d was not found in the list!\n", key);
        return;
    }
    printf("\n%d was found at position %d of the list\n", key, position);
}

// Function to delete a node by its data in the list
void deleteByKey(list *list, int key) {
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        printf("\nThe list is empty, cannot delete!\n");
        return;
    }
    // Initialize flag to indicate if the key is found
    int flag = 0;
    node *current = list -> head;
    // Traverse the list to find the node with the specified key
    do {
        if (current -> data == key) {
            // If found, adjust pointers to remove the node
            current -> previous -> next = current -> next;
            current -> next -> previous = current -> previous;
            // If the node to be deleted is the head, update the head pointer
            if (list -> head -> data == key)
                list -> head = current -> next;
            // Free the memory occupied by the node
            free(current);
            // Set flag to indicate successful deletion
            flag = 1;
            break;
        }
        current = current -> next;
    } while(current != list -> head);
    // Check if the key is found and display the result
    if (flag == 0) {
        printf("\nThe key could not be found in the list!\n");
        return;
    }
    // Decrement the size of the list
    (list -> size)--;
    // If the list becomes empty, update head pointer
    if (list -> size == 0) {
        list -> head = NULL;
    } else if (list -> size == 1) {
        // If only one node remains, update pointers to form a circular list
        list -> head -> next = list -> head;
        list -> head -> previous = list -> head;
    }
    // Display the updated list
    display(list);
}

// Function to delete a node by its position in the list
void deleteByPosition(list *list, int position) {
    // Check if the list is empty
    if (list -> head == NULL || list -> size == 0) {
        printf("The list is empty, cannot delete at specified position!");
        return;
    }
    // Initialize counter and traverse the list to find the node at the specified position
    int count = 0;
    node *current = list -> head;
    do {
        current = current -> next;
        count++;
    } while(current != list -> head && count < position - 1);
    // Adjust pointers to remove the node at the specified position
    current -> previous -> next = current -> next;
    current -> next -> previous = current -> previous;
    // If the node to be deleted is the head, update the head pointer
    if (position == 1)
        list -> head = current -> next;
    // Free the memory occupied by the node
    free(current);
    // Decrement the size of the list
    (list -> size)--;
    // If the list becomes empty, update head pointer
    if (list -> size == 0) {
        list -> head = NULL;
    } else if (list -> size == 1) {
        // If only one node remains, update pointers to form a circular list
        list -> head -> next = list -> head;
        list -> head -> previous = list -> head;
    }
    // Display the updated list
    display(list);
}

// Main function
int main() {
    // Declare variables
    int option, position, key, data;
    // Create a circular doubly linked list
    list *list = createList();
    // Menu-driven loop for list operations
    do {
        printf("\nChoose any one of the following options:\n"
        "1. Insert at front\n"
        "2. Insert at rear\n"
        "3. Insert by order\n"
        "4. Delete by position\n"
        "5. Delete by key\n"
        "6. Search by position\n"
        "7. Search by key\n"
        "8. Exit\n");
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
                // Insert data at the rear of the list
                printf("\nEnter the data to be inserted at the end: ");
                scanf("%d", &data);
                insertAtRear(list, data);
                break;
            case 3:
                // Insert data in order in the list
                insertByOrder(list);
                break;
            case 4:
                // Delete data by position in the list
                printf("\nEnter the position for the data to be deleted at: ");
                scanf("%d", &position);
                while (position < 1 || position > list -> size) {
                    printf("\nThe entered position is out of bounds, enter between 1 and %d!\n", list -> size);
                    scanf("%d", &position);
                }
                deleteByPosition(list, position);
                break;
            case 5:
                // Delete data by key in the list
                printf("\nEnter the key to be deleted: \n");
                scanf("%d", &key);
                deleteByKey(list, key);
                break;
            case 6:
                // Search data by position in the list
                printf("\nEnter the position for the data to be searched at: ");
                scanf("%d", &position);
                while (position < 1 || position > list -> size) {
                    printf("\nThe entered position is out of bounds, enter between 1 and %d!\n", list -> size);
                    scanf("%d", &position);
                }
                searchByPosition(list, position);
                break;
            case 7:
                // Search data by key in the list
                printf("\nEnter the key to be searched: ");
                scanf("%d", &key);
                searchByKey(list, key);
                break;
            case 8:
                // Free the list and exit the program
                freeList(list);
                break;
            default:
                printf("\nChoose a valid option!\n");
        }
    } while (option != 5); // Continue loop until the user chooses to exit
}