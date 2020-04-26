#include<stdio.h>
#include<stdlib.h>
int count=0;
int leaf=0;
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
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
    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    TREE *curr;
    TREE *prev;
    curr=root;
    prev=NULL;
    while(curr!=NULL)
    {
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
    printf("Node inserted");
    return root;
}
void count_nodes(TREE *root)
{
    if(root!=NULL)
    {
    count_nodes(root->left);
    count_nodes(root->right);
    count++;
    }
}
void count_leaf(TREE *root)
{
    if(root!=NULL)
    {
    count_leaf(root->left);
    count_leaf(root->right);
    if(root->left==NULL&&root->right==NULL)
        leaf++;
    }
}
int minimum(TREE * root)
{
    TREE *curr,*prev;
    curr=root;
    prev=NULL;
    while(curr->left!=NULL)
    {
        prev=curr;
        curr=curr->left;
    }
        return prev->left->data;
}
int maximum(TREE * root)
{
    TREE *curr,*prev;
    curr=root;
    prev=NULL;
    while(curr->right!=NULL)
    {
        prev=curr;
        curr=curr->right;
    }
    return prev->right->data;

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
void preorder(TREE *root)
{
     if(root!=NULL)
    {
    printf("\n%d\n",root->data);
    inorder(root->left);
    inorder(root->right);
    }
}
void postorder(TREE *root)
{
     if(root!=NULL)
    {
    inorder(root->left);
    inorder(root->right);
    printf("\n%d\n",root->data);
    }
}
TREE * delete_from_BST(TREE * root, int item)
{
    TREE * currnode, *parent, *successor, *p;

    if(root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    parent = NULL;
    currnode = root;
    while (currnode != NULL && item != currnode->data)
    {
        parent = currnode;
        if(item < currnode->data)
            currnode  = currnode->left;
        else
            currnode = currnode->right;
    }

    if(currnode == NULL)  {
        printf("Item not found\n");
        return root;
    }

    if(currnode->left == NULL)
        p = currnode->right;
    else if (currnode->right == NULL)
        p = currnode->left;
    else
    {
        successor = currnode->right;
        while(successor->left != NULL)
            successor = successor->left;

        successor->left = currnode->left;
        p = currnode->right;
    }

    if (parent == NULL)
    {
        free(currnode);
        return p;
    }

    if(currnode == parent ->left)
        parent->left = p;
    else
        parent->right = p;

    free(currnode);
    return root;
}

int main()
{
    TREE *root=NULL;
    int choice,item,min,max,IN;
    while(1)
    {
        printf("****MENU****\n");
        printf("\n1:Insert BST\n2:inorder\n3:preorder\n4:postorder\n5:delete from BST\n6:Print adress of Root\n7:To print number of nodes\n8:Leaf count\n9:NO. of edges\n10:min Element\n11:max Element\n12:internal nodes\n");
        printf("Enter Your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:root=Insert_into_BST(root);
                   break;
            case 2:inorder(root);break;
            case 3:preorder(root);break;
            case 4:postorder(root);break;
            case 5:printf("Enter the element to delete\n");
                   scanf("%d",&item);
                   root=delete_from_BST(root,item);break;
            case 6:printf("Adress of root is %p",root);break;
            case 7:count=0;
                   count_nodes(root);
                   printf("count is %d\n",count);break;
            case 8:leaf=0;
                   count_leaf(root);
                   printf("Leaf count is %d",leaf);break;
            case 9:count=0;
                   count_nodes(root);
                   printf("Number of edges is %d",count-1);break;
            case 10:min=minimum(root);
                    printf("Min element is %d\n",min);break;
            case 11:max=maximum(root);
                    printf("Max element is %d\n",max);break;
            case 12:count=0;
                    count_nodes(root);
                    leaf=0;
                    count_leaf(root);
                    printf("Internal nodes=%d",(count-leaf-1));

        }
    }
    return 0;
}
