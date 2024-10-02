#include <stdio.h>
#include <stdlib.h>

// Structure of a node
typedef struct Node {
    int data;
    struct Node *left, *right;
    int isThreaded;  // Indicates if the right pointer is a thread
} Node;

// Create a new node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->isThreaded = 0;
    return node;
}

// Insert a node into the binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Inserting in left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // Inserting in right subtree
    else if (data > root->data) {
        if (root->isThreaded) {
            Node* temp = createNode(data);
            temp->right = root->right;
            temp->isThreaded = 1;
            root->right = temp;
            root->isThreaded = 0;
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Find the leftmost node in the tree (for in-order traversal start)
Node* leftMost(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// In-order traversal of a right-threaded binary tree
void inOrderTraversal(Node* root) {
    Node* current = leftMost(root);

    while (current != NULL) {
        // Print the current node
        printf("%d ", current->data);

        // If the node is threaded, go to its in-order successor
        if (current->isThreaded) {
            current = current->right;
        } else {
            // Otherwise, go to the leftmost node in the right subtree
            current = leftMost(current->right);
        }
    }
}

int main() {
    Node* root = NULL;

    // Insert nodes into the threaded binary tree
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    printf("In-order traversal of the right-threaded binary tree:\n");
    inOrderTraversal(root);

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------
// Explaination of Code.

/*
-> Creating the Strucure
typedef struct Node {
    int data;
    struct Node *left, *right;
    int isThreaded;
} Node;
isThreaded: A flag to indicate whether the right pointer is a thread 
(points to the in-order successor instead of a normal right child).


->Creating a New Node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->isThreaded = 0;  // Initially, no threading
    return node;
}
Setting the isThreaded flag to 0 (Not threaded Initially).


----> Insert Operation in Threaded Binary Search Tree.. <----

1. Check if the root is NULL:
If the tree is empty (root == NULL), create a new node and return it. This is the base case for recursion, 
used when a new node is inserted in an empty spot.



2. Inserting in the left Subtree

if (data < root->data) {
    root->left = insert(root->left, data);
}
If the value to be inserted (data) is less than the current node's value (root->data), 
recursively call insert on the left subtree (root->left).



3. Inserting in the Right subtree.

else if (data > root->data) {
    if (root->isThreaded) {
        // Create a new node and update the threading
        Node* temp = createNode(data);
        temp->right = root->right;  // Set new node's right pointer to the current node's right
        temp->isThreaded = 1;       // Mark the new node as threaded
        root->right = temp;         // Insert the new node as the right child
        root->isThreaded = 0;       // Remove the thread from the current root
    } else {
        // If no threading, move to the right child
        root->right = insert(root->right, data);
    }
}
If (data > root->data), the new value should be inserted in the right subtree.

If the current node has a right thread (root->isThreaded == 1):
A thread exists when a node's right pointer points to its in-order successor rather than a child node.
We need to insert the new node between the current node and the in-order successor, without losing the thread.
Steps for this scenario:

Create a new node (temp).
Set the new node's right pointer to point to the current node's right thread (which is the in-order successor). 
This keeps the in-order structure intact.
Mark the new node as threaded (temp->isThreaded = 1), indicating that the new node also has a thread.
Set the current node's right pointer to the new node (root->right = temp), making the new node its right child.
Remove the thread from the current node (root->isThreaded = 0) since it now has a regular right child.
If there’s no thread (else part):

If the current node doesn't have a thread, it behaves like a regular binary search tree, 
and we recursively insert into the right subtree (root->right = insert(root->right, data)).

*/