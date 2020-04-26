#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
    struct tree *left_gc;
    struct tree *right_gc;
};
typedef struct tree TREE;
TREE * Insert_into_BST(TREE *root)
{
    TREE * newnode;
    newnode=(TREE*)malloc(sizeof(TREE));
    if(newnode==NULL)
    {
        printf("Memory allocation failed");
        return root;
    }
    printf("Enter the value\n");
    scanf("%d",&newnode->data);
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->left_gc=NULL;
    newnode->right_gc=NULL;
    if(root==NULL)
    {
        root=newnode;
        printf("Node inserted\n");
        return root;
    }
    TREE *curr;
    TREE *grand;
    TREE *prev;
    curr=root;
    prev=NULL;
    grand=NULL;
    while(curr!=NULL)
    {
        grand=prev;
        prev=curr;
        if(newnode->data<curr->data)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
    if(newnode->data<prev->data)
    {
        prev->left=newnode;
    }
    else
    {
        prev->right=newnode;
    }
    if(grand!=NULL)
    {
        if(prev=grand->left)
        {
            if(newnode=prev->left)
                grand->left_gc=newnode;
        }
    }
    if(grand!=NULL)
    {
        if(prev=grand->right)
        {
            if(newnode=prev->right)
                grand->right_gc=newnode;
        }
    }
    printf("Node inserted\n");
    return root;
}
void inorder(TREE *root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("\n%d\n",root->data);
    inorder(root->right);
    }
}
void search(TREE *root,int key)
{
    TREE *curr;
    curr=root;
    while(curr!=NULL && curr->data!=key)
    {
        if(key<curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(curr==NULL)
    {
        printf("Key not found\n");
        return;
    }
    if(curr->left_gc!=NULL)
        printf("Left grandchild is %d\n",curr->left_gc->data);
    if(curr->right_gc!=NULL)
        printf("Right grandchild is %d\n",curr->right_gc->data);
    if(curr->left_gc==NULL && curr->right_gc==NULL)
        printf("The node does not have grand children\n");
}
void display_no(TREE *root)
{
    if(root==NULL)
        return;
    if(root->left_gc==NULL && root->right_gc==NULL)
        printf("%d\n",root->data);
        display_no(root->left);
        display_no(root->right);
}
int main()
{
    TREE *root;
    root=NULL;
    int choice;
    int key;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1.Insert\n");
        printf("2.Display\n");
        printf("3.Search and display grandchildren\n");
        printf("4.Display nodes with no grandchildren\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: root=Insert_into_BST(root);
                    break;
            case 2: inorder(root);
                    break;
            case 3: printf("Enter the key to be searched\n");
                    scanf("%d",&key);
                    search(root,key);
                    break;
            case 4: if(root==NULL)
                    printf("Tree is empty\n");
                    else
                        display_no(root);
        }
    }
}

