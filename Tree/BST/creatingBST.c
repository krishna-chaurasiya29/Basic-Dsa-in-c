#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

//Checking weather the given tree is Binary Search Treeee....
int isBST(struct  node* root)
{
    static struct node *prev = NULL;//creating null pointer of node
    if(root!=NULL)//checking weather the given tree is null or not, if not null enter the condition
    {
        if(!isBST(root->left))//calling the same fuction again to check weather the left part of the tree is in bst form
        {//if the fuction is not bst it will return 0
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else//the case when there is no node in tree so we are considering that the tree is Binary search tree
    {
        return 1;
    }
}

int main(){
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p); 
    // printf("\n");
    inOrder(p);
    printf("\n");
    printf("%d", isBST(p)); 
    if(isBST(p)){
        printf("\nThis is a bst" );
    }
    else{
        printf("\nThis is not a bst");
    }
    return 0;
}


/*
Explaination of BST Function

int isBST(struct node* root)
{
    static struct node *prev = NULL;

This accetps the pointer to the root of the tree(struct node * root)
prev will be used to compare the current node's value with the previous node's value.
Initially ,prev is NULL , meaning no nodes have been visited yet

    if (root != NULL)
    {
This checks whether the root is NULL. If the tree (or subtree) is not NULL,
the function proceeds to check if it satisfies the BST property.

Recursive call to Left Subtree
        if (!isBST(root->left))
        {
            return 0;
        }
The function makes a recursive call to isBST on the left subtree (root->left).
This initiates an in-order traversal (left, node, right).
If the left subtree violates the BST property (i.e., isBST(root->left) returns 0), 
the entire tree is not a BST, and the function returns 0.

Comparing Current Node with Previous Node
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
After visitiing the left subtree, we compare the current node(root) with the preivious node
if prev is not null (i.e., we have already visited at least one node), we check
if the current node's data is less than or equal to the previous node's data
If root->data <= prev->data, it means the current node violates the BST property.
The function returns 0 in this case, indicating the tree is not a BST.

Update prev
prev = root;
If the current node satisfies the BST property, we update prev to the current node (root).
This is crucial because now the prev node will hold the most recently visited node in the in-order traversal,
and it will be used to compare with the next node (right subtree).



Recursive call to right subtree
        return isBST(root->right);
    }
the function makes a recursive call to right sub tree this continues the 
in order traversal by checking the right subtree
if the right subtree also satisfies the BST property, the function proceess

      5
     / \
    3   6
   / \
  1   4

Start with the root node 5. prev is NULL initially.
Move to the left subtree (3):
Move to its left subtree (1):
Since 1 has no left child, the left subtree is valid, and prev becomes 1.
Back at node 3, compare 3 with prev (1), it satisfies 3 > 1, so update prev to 3.
Move to the right subtree (4):
Compare 4 with prev (3), it satisfies 4 > 3, so update prev to 4.
Back at node 5, compare 5 with prev (4), it satisfies 5 > 4, so update prev to 5.
Move to the right subtree (6):
Compare 6 with prev (5), it satisfies 6 > 5, so update prev to 6.
Since all nodes satisfy the BST condition, the function returns 1, confirming that the tree is a BST.


*/