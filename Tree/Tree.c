#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node // Define the structure for a node in the binary tree 
{ 
int data; 
struct Node *left, *right; 
} Node; 

Node* createNode(int data) // Function to create a new node 
{ 
Node* newNode = (Node*)malloc(sizeof(Node)); 
newNode->data = data; 
newNode->left = NULL; 
newNode->right = NULL; 
return newNode; 
} 

// Function to perform in-order traversal (Left, Root, Right) 
void inorderTraversal(Node* root) //(L-P-R) 
{ 
if (root == NULL) 
return; 
inorderTraversal(root->left); 
printf("%d ", root->data); 
inorderTraversal(root->right); 
} 

// Function to perform pre-order traversal (Root, Left, Right) 
void preorderTraversal(Node* root) //(P-L-R) 
{ 
if (root == NULL) 
return; 
printf("%d ", root->data); 
preorderTraversal(root->left); 
preorderTraversal(root->right); 
} 
// Function to perform post-order traversal (Left, Right, Root) 
void postorderTraversal(Node* root) //L-R-P 
{ 
if (root == NULL) 
return; 
postorderTraversal(root->left); 
postorderTraversal(root->right); 
printf("%d ", root->data); 
} 
int main()  
{ 
Node* root = createNode (1); 
root ->left = createNode (2); 
root->right = createNode (3); 
root ->left->left = createNode (4); 
root ->left->right = createNode (5); 
root ->right->left = createNode (6); 
root ->right->right = createNode (7); 

printf ("In-order traversal: "); 
inorderTraversal(root); 
printf("\n"); 

printf ("Pre-order traversal: "); 
preorderTraversal(root); 
printf("\n"); 

printf ("post-order traversal: "); 
postorderTraversal(root); 
printf("\n"); 
return 0; 
} 