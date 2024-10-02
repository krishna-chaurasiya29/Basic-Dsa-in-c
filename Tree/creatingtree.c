#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};

struct node *Create()
{
    int x;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data(-1 for no node)\n");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("Enter left child of %d ",x);
    newnode->left=Create();
    printf("Enter right child of %d ",x);
    newnode->right=Create();
    return newnode;
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        printf("%d ",root->data);
        postorder(root->right);
    }
}


int main()
{
    struct node *root=NULL;
    root=create();
    preorder(root);
    postorder(root);
    inorder(root);
}