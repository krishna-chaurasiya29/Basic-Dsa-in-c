#include <stdio.h>
#include <stdlib.h>

// Node structure for the Left Threaded Binary Tree
struct Node {
    int data;                  // Node value
    struct Node* left;         // Left child or thread to predecessor
    struct Node* right;        // Right child pointer
    int leftThread;            // 1 if left is a thread, 0 if it's an actual left child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 0;   // Initially, no thread (actual left child)
    return newNode;
}

// Recursive insertion function for Left Threaded Binary Tree
struct Node* insertRec(struct Node* root, int data) {
    // Base case: if root is NULL, return the new node
    if (root == NULL) {
        return createNode(data);
    }

    // If the new data is smaller, move to the left subtree
    if (data < root->data) {
        // Check if the left pointer is a thread
        if (root->leftThread == 1) {
            // Insert the new node and update threading
            struct Node* newNode = createNode(data);
            newNode->left = root->left;  // Inherit the thread from root
            newNode->leftThread = 1;
            root->left = newNode;        // Set newNode as left child
            root->leftThread = 0;        // Mark root's left as a real child
        } else {
            // Move to the left subtree
            root->left = insertRec(root->left, data);
        }
    }
    // If the new data is greater, move to the right subtree
    else if (data > root->data) {
        root->right = insertRec(root->right, data);
    }
    // Return the root to maintain links in the recursive calls
    return root;
}

// In-order traversal function for Left Threaded Binary Tree
void inOrder(struct Node* root) {
    struct Node* current = root;

    // Traverse the tree until the leftmost node is reached
    while (current != NULL && current->leftThread == 0) {
        current = current->left;
    }

    // Traverse the tree using threads
    while (current != NULL) {
        printf("%d ", current->data);

        // If it's a thread, follow the thread to the predecessor
        if (current->right == NULL || current->right->leftThread == 1) {
            current = current->right;
        } else {
            // Move to the leftmost node in the right subtree
            current = current->right;
            while (current != NULL && current->leftThread == 0) {
                current = current->left;
            }
        }
    }
}

// Main function to test the recursive insertion with left threading
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
    printf("In-order Traversal of Left Threaded Binary Tree:\n");
    inOrder(root);

    return 0;
}
