// Array Operations Menu

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the array
typedef struct array {
    int *data;      // Pointer to the array data
    int size;       // Current number of elements in the array
    int capacity;   // Maximum capacity of the array
} array;

// Function to create a new array with a given capacity
array *createArray(int capacity) {
    // Allocate memory for the array structure
    array *newArray = (array *) malloc(sizeof(array));
    // Check if memory allocation was successful
    if (newArray == NULL) {
        printf("\nMemory could not be dynamically allocated for the new array!\n");
        exit(1);
    }
    // Allocate memory for the data array in the structure
    newArray -> data = (int *) malloc(capacity * sizeof(int));
    // Check if memory allocation was successful
    if (newArray -> data == NULL) {
        printf("\nMemory could not be dynamically allocated for the new array!\n");
        exit(1);
    }
    // Initialize size and capacity
    newArray -> size = 0;
    newArray -> capacity = capacity;
    return newArray;
}

// Function to check if the array is full
int isFull(array *array) {
    return (array -> size == array -> capacity);
}

// Function to check if the array is empty
int isEmpty(array *array) {
    return (array -> size == 0);
}

// Function to display the contents of the array
void display(array *array) {
    // Check if the array is empty
    if (isEmpty(array)) {
        printf("\nThe array is empty, cannot display!\n");
        return;
    }
    printf("\nThe updated array elements are:\n");
    // Iterate over the elements and print them
    for (int i = 0; i < array -> size; i++) {
        printf("%d\t", array -> data[i]);
    }
    printf("\n");
}

// Function to read contents into the array
void read(array *array) {
    printf("\nEnter the contents of the array:\n");
    // Read elements into the array
    for (int i = 0; i < array -> capacity; i++) {
        scanf("%d", &(array -> data[i]));
    }
    // Display the array
    display(array);
}

// Function to insert an element at a specified position
void insertByPosition(array *array, int position, int data) {
    // Check if the array is full
    if (isFull(array)) {
        printf("\nThe array is full, cannot insert!\n");
        return;
    }
    // Shift elements to make space for the new element
    for (int i = array -> capacity; i >= position; i--) {
        array -> data[i] = array -> data[i - 1];
    }
    // Insert the new element
    array -> data[position - 1] = data;
    // Increment the size of the array
    (array -> size)++;
    // Display the updated array
    display(array);
}

// Function to insert an element in sorted order
void insertByOrder(array *array, int data) {
    // Check if the array is full
    if (isFull(array)) {
        printf("\nThe array is full, cannot insert!\n");
        return;
    }
    int count = 0;
    // Find the position to insert the new element
    for (int i = 0; i < array -> size; i++) {
        if (data <= array -> data[i]) {
            break;
        }
        count++;
    }
    // Shift elements to make space for the new element
    for (int i = array -> capacity; i >= count; i--) {
        array -> data[i] = array -> data[i - 1];
    }
    // Insert the new element
    array -> data[count] = data;
    // Increment the size of the array
    (array -> size)++;
    // Display the updated array
    display(array);
}

// Function to delete an element at a specified position
void deleteByPosition(array *array, int position) {
    // Check if the array is empty
    if (isEmpty(array)) {
        printf("\nThe array is empty, cannot delete!\n");
        return;
    }
    // Shift elements to overwrite the element to be deleted
    for (int i = position - 1; i < array -> size; i++) {
        array -> data[i] = array -> data[i + 1];
    }
    // Decrement the size of the array
    (array -> size)--;
    // Display the updated array
    display(array);
}

// Function to delete an element by its value
void deleteByKey(array *array, int key) {
    // Check if the array is empty
    if (isEmpty(array)) {
        printf("\nThe array is empty, cannot delete!\n");
        return;
    }
    int flag = 0;
    // Find the element with the specified key and delete it
    for (int i = 0; i < array -> size; i++) {
        if (array -> data[i] == key) {
            for (int j = i; j < array -> size - 1; j++) {
                array -> data[j] = array -> data[j + 1];
            }
            // Decrement the size of the array
            (array -> size)--;
            flag = 1;
            break;
        }
    }
    // Display appropriate message based on whether the key was found
    if (flag == 0) {
        printf("\nThe key was not found within the array elements!\n");
    } else {
        printf("\n%d was successfully deleted from the array!\n", key);
        display(array);
    }
}

// Function to search for an element by its position
void searchByPosition(array *array, int position) {
    // Check if the array is empty
    if (isEmpty(array)) {
        printf("\nThe array is empty, cannot search!\n");
        return;
    }
    // Display the element at the specified position
    printf("\n%d is at position %d\n", array -> data[position], position);
}

// Function to search for an element by its value
void searchByKey(array *array, int key) {
    // Check if the array is empty
    if (isEmpty(array)) {
        printf("\nThe array is empty, cannot delete!\n");
        return;
    }
    int count = 1, flag = 0;
    // Search for the key in the array and display its position if found
    for (int i = 0; i < array -> size; i++) {
        if (array -> data[i] == key) {
            printf("\n%d was found at position %d\n", key, count);
            flag = 1;
            break;
        }
        count++;
    }
    // Display appropriate message if the key was not found
    if (flag == 0) {
        printf("\nThe key was not found within the array elements!\n");
    }
}

// Function to reverse the elements of the array
void reverseArray(array *array) {
    int start = 0;
    int end = array -> size - 1;
    // Swap elements from start to end to reverse the array
    while (start < end) {
        int temp = array -> data[start];
        array -> data[start] = array -> data[end];
        array -> data[end] = temp;
        start++;
        end--;
    }
    // Display the reversed array
    display(array);
}

// Main function to demonstrate array operations
int main() {
    int position, option, key, capacity, data;
    // Ask the user for the capacity of the array
    printf("\nEnter the capacity of the array: ");
    scanf("%d", &capacity);
    // Create a new array with the specified capacity
    array *array = createArray(capacity);
    // Menu-driven interface for array operations
    do {
        printf("\nChoose any one of the following options:\n"
        "1. Insert by position\n"
        "2. Insert by order\n"
        "3. Delete by position\n"
        "4. Delete by key\n"
        "5. Search by position\n"
        "6. Search by key\n"
        "7. Reverse contents\n"
        "8. Exit\n");
        scanf("%d", &option);
        switch(option) {
            // Perform the selected operation
            case 1: 
                printf("\nEnter the position at which the data must be inserted at: ");
                scanf("%d", &position);
                // Validate the position input
                while (position < 1 || position > array -> size + 1) {
                    printf("Enter a position between 1 and %d: ", array -> size + 1);
                    scanf("%d", &position);
                }
                printf("\nEnter the data to be stored at position %d: ", position);
                scanf("%d", &data);
                // Insert data at the specified position
                insertByPosition(array, position, data);
                break;
            case 2: 
                printf("\nEnter the data to be inserted in order: ");
                scanf("%d", &data);
                // Insert data in sorted order
                insertByOrder(array, data);
                break;
            case 3:
                printf("\nEnter the position at which the data must be deleted at: ");
                scanf("%d", &position);
                // Validate the position input
                while (position < 1 || position > array -> size) {
                    printf("Enter a position between 1 and %d: ", array -> size);
                    scanf("%d", &position);
                }
                // Delete data at the specified position
                deleteByPosition(array, position);
                break;
            case 4:
                printf("\nEnter the key to be deleted from the array: ");
                scanf("%d", &key);
                // Delete data with the specified key
                deleteByKey(array, key);
                break;
            case 5:
                printf("\nEnter the position at which the data must be searched at: ");
                scanf("%d", &position);
                // Validate the position input
                while (position < 1 || position > array -> size) {
                    printf("Enter a position between 1 and %d: ", array -> size);
                    scanf("%d", &position);
                }
                // Search for data at the specified position
                searchByPosition(array, position);
                break;
            case 6:
                printf("\nEnter the key to be searched from the array: ");
                scanf("%d", &key);
                // Search for data with the specified key
                searchByKey(array, key);
                break;
            case 7:
                // Reverse the contents of the array
                reverseArray(array);
                break;
            case 8:
                // Free dynamically allocated memory and exit the program
                free(array -> data);
                free(array);
                printf("\nExiting program!\n");
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while(option != 8);
    return 0;
}