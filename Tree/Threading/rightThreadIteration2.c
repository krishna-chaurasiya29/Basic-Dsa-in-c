//Through Iteration
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int rightThread; // 0 if the right pointer is to a child, 1 if it's a thread
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->rightThread = 0;
    return newNode;
}

// Insert function for Right Threaded Binary Tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    struct Node* parent = NULL;
    struct Node* current = root;

    // Traverse the tree to find the right position
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            // Go to the left subtree
            if (current->left == NULL)
                break;
            current = current->left;
        } else if (data > current->data) {
            // Go to the right subtree or follow the thread
            if (current->rightThread == 1)
                break;
            current = current->right;
        } else {
            // Duplicate data not allowed
            return root;
        }
    }

    struct Node* newNode = createNode(data);

    if (data < parent->data) {
        parent->left = newNode;
        newNode->right = parent;
        newNode->rightThread = 1;
    } else {
        if (parent->rightThread == 1) {
            newNode->right = parent->right;
            newNode->rightThread = 1;
        }
        parent->right = newNode;
        parent->rightThread = 0;
    }

    return root;
}

// In-order traversal of Right Threaded Binary Tree
void inOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Find the leftmost node
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }

    // Traverse the tree using threads
    while (current != NULL) {
        printf("%d ", current->data);

        if (current->rightThread == 1) {
            current = current->right;
        } else {
            current = current->right;
            while (current != NULL && current->left != NULL) {
                current = current->left;
            }
        }
    }
}

// Main function to test the above implementation
int main() {
    struct Node* root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    printf("In-order Traversal of Right Threaded Binary Tree:\n");
    inOrder(root);

    return 0;
}
