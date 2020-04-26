#include<stdio.h>
#include<stdlib.h>
int header=0;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
    struct node *link;
};
typedef struct node NODE;
NODE* insert_at_front(NODE *head)
{
    NODE *newnode,*p;
    newnode=(NODE *)malloc(sizeof(NODE));
    printf("Enter data to be entered\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->link=NULL;
    header++;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    newnode->next=head;
    head->prev=newnode;
    p=head;
    if((newnode->data)%2==0)
    {
        while(p!=NULL && (p->data)%2!=0)
        {
            p=p->next;
        }
        if(p!=NULL)
            newnode->link=p;
    }
    else
    {
        while(p!=NULL && (p->data)%2==0)
        {
            p=p->next;
        }
        if(p!=NULL)
            newnode->link=p;
    }
    return newnode;
}
NODE* delete_at_front(NODE *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE *temp;
    temp=head;
    head=head->next;
    printf("The node deleted is %d\n",temp->data);
    free(temp);
    header--;
    return head;
}
void display(NODE *head)
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    NODE *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
void print_link(NODE *head)
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    NODE *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->link;
    }
}
int main()
{
    NODE *head;
    head=NULL;
    int choice;
    while(1)
    {
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.Display\n");
        printf("4.link\n");
        printf("5.header\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert_at_front(head);
                    break;
            case 2: head=delete_at_front(head);
                    break;
            case 3: display(head);
                    break;
            case 4: print_link(head);
                    break;
            case 5: printf("Header is %d",header);
                    break;
        }
    }
    return 0;
}
