#include<stdio.h>
#include<stdlib.h>

// creating the user defined variable Node
typedef struct node
{
    int data;
    struct node *left,*right;
}Node;

// Creating the new node
Node *createNode(int data)
{
    Node *n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

//In Order Traversal (Left->root->Right)
void inOrder(Node * root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

// Format -1 of performing the serach operation
Node * searchIter(Node * root,int key)
{
    //In this search operation the a pointer is created which will move with the current node checked
    //and will assigned the current node to the pointer and after the key is found it will return the pointer
    Node *temp=root;
    while(temp!=NULL)
    {
    if(key==temp->data)
    {
        return temp;
    }
    else if(key<temp->data)
    {
        temp=temp->left;
    }
    else{
        temp=temp->right;
    }
    }
    return NULL;
}

// Format 2 of performing the serch operation
Node * search(Node * root, int key)
{//this is recursive process which call the same fuction again and again to find the element
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

int isBST(Node *root)
{
    Node * prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && prev->data>=root->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inOrder(p);
    printf("\n");
    printf("%d", isBST(p)); 
    if(isBST(p)){
        printf("\nThis is a bst" );
    }
    else{
        printf("\nThis is not a bst");
    }
    Node * n=search(p,7);//format 2
    Node * n1=searchIter(p,1);//format 1
    if(n!=NULL)
    {
    printf("\nElement Found %d",n->data);
    }
    else
    printf("\nElement Not found");

    if(n1!=NULL)
    {
    printf("\nElement Found %d",n1->data);
    }
    else
    printf("\nElement Not found");
    return 0;
}