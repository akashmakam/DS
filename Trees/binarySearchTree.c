// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} node;

typedef struct tree {
    struct node *root;
} tree;

typedef struct queue {
    int front, rear;
    node *data[MAX];
} queue;

tree *createTree() {
    tree *newTree = (tree *) malloc(sizeof(tree));
    if (newTree == NULL) {
        printf("\nMemory could not be dynamically allocated for the new tree!\n");
        exit(1);
    }
    newTree -> root = NULL;
    return newTree;
}

node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("\nMemory could not be dynamically allocated for the new node!\n");
        exit(1);
    }
    newNode -> data = data;
    newNode -> right = newNode -> left = NULL;
    return newNode;
}

void freeTree(node *root) {
    if (root == NULL)
        return;
    freeTree(root -> left);
    freeTree(root -> right);
    free(root);
}

// Depth First Search (DFS) Traversals
void inOrderTraversal(node *root) {
    if (root == NULL)
        return;
    inOrderTraversal(root -> left);
    printf("%d\t", root -> data);
    inOrderTraversal(root -> right);
}

void preOrderTraversal(node *root) {
    if (root == NULL)
        return;
    printf("%d\t", root -> data);
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(node *root) {
    if (root == NULL)
        return;
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    printf("%d\t", root -> data);
}

//Breadth First Search (BFS) Traversal
void enqueue(queue *q, node *item) {
    if (q -> rear == MAX - 1) {
        printf("\nQueue is full, cannot enqueue!\n");
        exit(1);
    }
    q -> data[++(q -> rear)] = item;
}

node *dequeue(queue *q) {
    if (q -> front > q -> rear) {
        printf("\nQueue is empty, cannot dequeue!\n");
        exit(1);
    }
    return q -> data[(q -> front)++];
}

void levelOrderTraversal(node *root) {
    if (root == NULL) {
        printf("\nThe tree is empty, cannot traverse!\n");
        return;
    }
    queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("\nMemory could not be dynamically allocated for the queue!\n");
        exit(1);
    }
    q -> front = 0;
    q -> rear = -1;
    enqueue(q, root);
    while (q -> front <= q->rear) {
        int levelSize = q -> rear - q -> front + 1;
        for (int i = 0; i < levelSize; i++) {
            node *current = dequeue(q);
            printf("%d ", current -> data);
            if (current -> left != NULL)
                enqueue(q, current -> left);
            if (current -> right != NULL)
                enqueue(q, current -> right);
        }
        printf("\n");
    }
    free(q);
}

// Function to find the height of the tree
int heightOfTree(node *root) {
    if (root == NULL)
        return 0;
    int leftHeight = heightOfTree(root -> left);
    int rightHeight = heightOfTree(root -> right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to count all nodes in the tree
int countNodes(node *root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root -> left) + countNodes(root -> right);
}

// Function to find maximum value in the tree
void findMax(node* root) {
    if (root == NULL) {
        printf("The tree is empty, cannot find maximum value!\n");
        return;
    }
    node* current = root;
    node* parent = NULL;
    while (current -> right != NULL) {
        parent = current;
        current = current -> right;
    }
    if (parent == NULL) {
        printf("The maximum value is %d, and it's the only element in the tree.\n", current -> data);
    } else {
        printf("The maximum value in the tree is %d. It is the right child of the node with value %d.\n", current -> data, parent -> data);
    }
}

// Function to find maximum value in the tree
void findMin(node *root) {
    if (root == NULL) {
        printf("\nThe tree is empty, cannot find minimum value!\n");
        return;
    }
    node *current = root;
    node *parent = NULL;
    while (current -> left != NULL) {
        parent = current;
        current = current -> left;
    }
    if (parent == NULL) {
        printf("The minimum value is %d, and it's the only element in the tree.\n", current -> data);
    } else {
        printf("The minimum value in the tree is %d. It is the right child of the node with value %d.\n", current -> data, parent -> data);
    }
}

//Function to insert a node at leaf nodes
void insert(tree *tree, int data) {
    node *newNode = createNode(data);
    if (tree -> root == NULL) {
        tree -> root = newNode;
    } else {
        node *current = tree -> root;
        node *parent = NULL;
        while (current != NULL) {
            parent = current;
            if (data > current -> data) {
                current = current -> right;
            } else if (data < current -> data) {
                current = current -> left;
            } else {
                printf("\n%d is already present in the tree!\n", data);
                free(newNode);
                return;
            }
        }
        if (data > parent -> data) {
            parent -> right = newNode;
        } else {
            parent -> left = newNode;
        }
    }
    levelOrderTraversal(tree -> root);
}

//Function to search the tree for a key
void searchByKey(node *root, int key) {
    if (root == NULL) {
        printf("The tree is empty, cannot search!\n");
        return;
    }

    node *current = root;
    node *parent = NULL;

    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current -> data)
            current = current -> left;
        else
            current = current -> right;
    }
    if (current == NULL) {
        printf("The key %d was not found in the tree!\n", key);
    } else {
        if (parent == NULL)
            printf("%d is present in the tree, it is the root.\n", key);
        else if (key > parent -> data)
            printf("%d is present in the tree, it is the right child of %d.\n", key, parent->data);
        else
            printf("%d is present in the tree, it is the left child of %d.\n", key, parent->data);
    }
}

node *deleteByKey(node *root, int key) {
    // Check if the tree is empty
    if (root == NULL) {
        printf("\nThe tree is empty, cannot delete!\n");
        return NULL;
    }
    // Since the tree is not empty, we can search the key to be deleted in the given tree
    node *current = root, *parent = NULL;
    while (current != NULL && current -> data != key) {
        parent = current;
        if (key > current -> data)
            current = current -> right;
        else
            current = current -> left;
    }
    // If key was not found
    if (current == NULL) {
        printf("The key %d was not found in the tree!\n", key);
        return root;
    }
    // If key was found
    // Case 1: Node to be deleted has 0 children:
    if (current -> right == NULL && current -> left == NULL) {
        // If its the only node in the tree:
        if (parent == NULL) {
            free(current);
            return NULL;
        }
        // If its not the only node in the tree:
        if (parent -> right == current)
            parent -> right = NULL;
        else if (parent -> left == current)
            parent -> left = NULL;
        free(current);
    
    // Case 2: Node to be deleted has 1 child:
    } else if (current -> right == NULL || current -> left == NULL) {
        // Determine which child it is, left or right child:
        node *child = (current -> right != NULL)? current -> right : current -> left;
        // If it is the only node in the tree other than its child:
        if (parent == NULL) {
            free(current);
            return child;
        }
        // If it is not the only node in the tree other than its child:
        if (parent -> right == current)
            parent -> right = child;
        else if (parent -> left == current)
            parent -> left = child;
        free(current);
    
    // Case 3: Node to be deleted has 2 children:
    } else {
        // Find the inorder successor (the smallest node in the right subtree)
        node *inOrderSuccessorParent = current;
        node *inOrderSuccessor = current->right;
        while (inOrderSuccessor -> left != NULL) {
            inOrderSuccessorParent = inOrderSuccessor;
            inOrderSuccessor = inOrderSuccessor -> left;
        }

        // Replace the value of the current node with the value of the inorder successor
        current -> data = inOrderSuccessor -> data;

        // Delete the inorder successor
        if (inOrderSuccessorParent == current) {
            // If the inorder successor is the right child of the current node
            inOrderSuccessorParent -> right = inOrderSuccessor -> right;
        } else {
            // If the inorder successor is deeper in the right subtree
            inOrderSuccessorParent -> left = inOrderSuccessor -> right;
        }
        free(inOrderSuccessor);
    }
    levelOrderTraversal(root);
    return root;
}

int main() {
    tree *tree = createTree();
    int option, data, key;
    do {
        printf("\nChoose any one of the following options:\n"
        "1. Insert node\n"
        "2. Preorder Traversal\n"
        "3. Inorder Traversal\n"
        "4. Postorder Traversal\n"
        "5. Counting all nodes\n"
        "6. Finding height\n"
        "7. Maximum value\n"
        "8. Minimum value\n"
        "9. Searching by key\n"
        "10. Delete by key\n"
        "11. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\nEnter the data to be stored in the tree: ");
                scanf("%d", &data);
                insert(tree, data);
                break;
            case 2:
                printf("\nThe tree in preorder traversal format is as follows:\n");
                preOrderTraversal(tree -> root);
                printf("\n");
                break;
            case 3:
                printf("\nThe tree in inorder traversal format is as follows:\n");
                inOrderTraversal(tree -> root);
                printf("\n");
                break;
            case 4:
                printf("\nThe tree in postorder traversal format is as follows:\n");
                postOrderTraversal(tree -> root);
                printf("\n");
                break;
            case 5:
                printf("\nThe total number of nodes in the tree is %d.\n", countNodes(tree -> root));
                break;
            case 6:
                printf("\nThe total height of the tree is %d\n", heightOfTree(tree -> root));
                break;
            case 7:
                findMax(tree -> root);
                break;
            case 8:
                findMin(tree -> root);
                break;
            case 9:
                printf("\nEnter the key to be searched in the tree: ");
                scanf("%d", &key);
                searchByKey(tree -> root, key);
                break;
            case 10:
                printf("\nEnter the key to be deleted in the tree: ");
                scanf("%d", &key);
                deleteByKey(tree -> root, key);
                break;
            case 11:
                freeTree(tree -> root);
                free(tree);
                printf("\nExiting program!\n");
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while(option != 11);
    return 0;
}