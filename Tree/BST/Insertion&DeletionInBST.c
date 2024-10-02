#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * left,*right;
}Node;

Node * createNode(int data)
{
    Node*n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

//Foramt 1 of serch Operation through iteration
Node * SearchIteration(Node * root,int key)
{
    Node* temp=root;
    while(temp!=NULL)
    {
        if(key==temp->data)
        {
            return temp;
        }
        if(key<root->data)
        {
        temp=temp->left;
        }
        else if(key>root->data)
        {
            temp=temp->right;
        }
    }
    return NULL;
}

// Format 2 of serching Operation through Recurssion
Node * SearchReccursion(Node *root, int key)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(key<root->data)
    {
        return SearchReccursion(root->left,key);
    }
    else
    {
        return SearchReccursion(root->right,key);
    }
}

//Display of Tree in inorder format (LEFT->ROOT->RIGHT)
void inorder(Node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

// To Check weather the given tree is in Binary Search Tree Form
int isBST(Node *root) {
    static Node *prev = NULL;  // Make prev static to retain its value
    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && prev->data >= root->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}


//Fuction to insert node in the tree according to suitable position
void insert(Node *root, int key) {
    Node *prev = NULL;
    Node *temp = root;
    while (temp != NULL) {
        prev = temp;  // Set prev before moving temp
        if (temp->data == key) {
            printf("Data:- %d Already Exists....\n", temp->data);
            return;
        }
        else if (key < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    Node* new = createNode(key);
    if (key < prev->data) {
        prev->left = new;
    } else {
        prev->right = new;
    }
}
struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
    }

    //searching for the node to be deleted
    if (value < root->data){
        deleteNode(root->left,value);
    }
    else if (value > root->data){
        deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        deleteNode(root->left, iPre->data);
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
    inorder(p);
    printf("\n");
    printf("%d", isBST(p)); 
    if(isBST(p)){
        printf("\nThis is a bst" );
    }
    else{
        printf("\nThis is not a bst");
    }
    Node * n=SearchReccursion(p,7);//format 2
    Node * n1=SearchIteration(p,1);//format 1
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
    insert(p,9);
    printf("\n%d",p->right->right->data);
    printf("\n");
    inorder(p);
    return 0;
}