#include <stdio.h>
#include <stdlib.h>

// Node structure for Double Threaded Binary Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int leftThread;  // 1 if left is a thread (predecessor), 0 if it's a real left child
    int rightThread; // 1 if right is a thread (successor), 0 if it's a real right child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 1;  // Initially, the left pointer is a thread
    newNode->rightThread = 1; // Initially, the right pointer is a thread
    return newNode;
}

// Iterative insertion in Double Threaded Binary Tree
struct Node* insertIter(struct Node* root, int data) {
    // Create the new node to be inserted
    struct Node* newNode = createNode(data);

    // If the tree is empty, return the new node as the root
    if (root == NULL) {
        return newNode;
    }

    struct Node* parent = NULL;
    struct Node* current = root;

    // Find the correct position for the new node
    while (current != NULL) {
        parent = current;

        // If the data is smaller, move to the left
        if (data < current->data) {
            if (current->leftThread == 0) {
                current = current->left; // Move to the left child
            } else {
                break; // Stop if left is a thread
            }
        }
        // If the data is larger, move to the right
        else if (data > current->data) {
            if (current->rightThread == 0) {
                current = current->right; // Move to the right child
            } else {
                break; // Stop if right is a thread
            }
        } else {
            // Duplicate values are not allowed
            return root;
        }
    }

    // Insert the new node as the left or right child of the parent
    if (data < parent->data) {
        // Insert as the left child
        newNode->left = parent->left;   // Inherit parent's left thread (predecessor)
        newNode->right = parent;        // Set parent as the successor
        parent->left = newNode;         // Update parent's left pointer
        parent->leftThread = 0;         // Parent's left is now a real child
    } else {
        // Insert as the right child
        newNode->right = parent->right; // Inherit parent's right thread (successor)
        newNode->left = parent;         // Set parent as the predecessor
        parent->right = newNode;        // Update parent's right pointer
        parent->rightThread = 0;        // Parent's right is now a real child
    }

    return root;
}

// In-order traversal using threads
void inOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* current = root;

    // Find the leftmost node
    while (current != NULL && current->leftThread == 0) {
        current = current->left;
    }

    // Traverse the tree in in-order sequence
    while (current != NULL) {
        printf("%d ", current->data);

        // If the right pointer is a thread, follow it
        if (current->rightThread == 1) {
            current = current->right;
        } else {
            // Otherwise, move to the leftmost node in the right subtree
            current = current->right;
            while (current != NULL && current->leftThread == 0) {
                current = current->left;
            }
        }
    }
}

// Reverse in-order traversal using threads
void reverseInOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* current = root;

    // Find the rightmost node
    while (current != NULL && current->rightThread == 0) {
        current = current->right;
    }

    // Traverse the tree in reverse in-order sequence
    while (current != NULL) {
        printf("%d ", current->data);

        // If the left pointer is a thread, follow it
        if (current->leftThread == 1) {
            current = current->left;
        } else {
            // Otherwise, move to the rightmost node in the left subtree
            current = current->left;
            while (current != NULL && current->rightThread == 0) {
                current = current->right;
            }
        }
    }
}

// Main function to test the Double Threaded Binary Tree
int main() {
    struct Node* root = NULL;

    // Insert elements using iterative insertion
    root = insertIter(root, 20);
    root = insertIter(root, 10);
    root = insertIter(root, 30);
    root = insertIter(root, 5);
    root = insertIter(root, 15);
    root = insertIter(root, 25);
    root = insertIter(root, 35);

    // Perform in-order traversal
    printf("In-order Traversal of Double Threaded Binary Tree:\n");
    inOrder(root);
    printf("\n");

    // Perform reverse in-order traversal
    printf("Reverse In-order Traversal of Double Threaded Binary Tree:\n");
    reverseInOrder(root);
    printf("\n");

    return 0;
}
