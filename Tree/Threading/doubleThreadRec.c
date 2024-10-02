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

// Recursive insertion in Double Threaded Binary Tree
struct Node* insertRec(struct Node* root, int data) {
    // If the tree is empty, return the new node
    if (root == NULL) {
        return createNode(data);
    }

    // If the new data is smaller than the root's data
    if (data < root->data) {
        // If left is a thread, insert the new node as the left child
        if (root->leftThread == 1) {
            struct Node* newNode = createNode(data);
            newNode->left = root->left;  // Inherit root's left thread (predecessor)
            newNode->right = root;       // Set root as the new node's successor
            root->left = newNode;        // New node becomes the left child
            root->leftThread = 0;        // Root's left is now a real child, not a thread
        } else {
            // Recur down to the left subtree
            root->left = insertRec(root->left, data);
        }
    }
    // If the new data is larger than the root's data
    else if (data > root->data) {
        // If right is a thread, insert the new node as the right child
        if (root->rightThread == 1) {
            struct Node* newNode = createNode(data);
            newNode->right = root->right; // Inherit root's right thread (successor)
            newNode->left = root;         // Set root as the new node's predecessor
            root->right = newNode;        // New node becomes the right child
            root->rightThread = 0;        // Root's right is now a real child, not a thread
        } else {
            // Recur down to the right subtree
            root->right = insertRec(root->right, data);
        }
    }

    // Return the unchanged root pointer
    return root;
}

// In-order traversal using threads
void inOrder(struct Node* root) {
    // Start with the leftmost node
    struct Node* current = root;
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
    // Start with the rightmost node
    struct Node* current = root;
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

    // Insert elements using recursive insertion
    root = insertRec(root, 20);
    root = insertRec(root, 10);
    root = insertRec(root, 30);
    root = insertRec(root, 5);
    root = insertRec(root, 15);
    root = insertRec(root, 25);
    root = insertRec(root, 35);

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
