#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct	node *next;
};

//function to display the data in the list
display(struct node *head)
{
	if(head == NULL)
	{
		printf("NULL\n");
	}
	else
	{

		printf("|%d|", head-> data);
		display(head->next);
	}
}

struct node* front(struct node *head)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d",&p->data);
	p->next=head;
	return (p);
}

struct node* end(struct node *head)
{
	struct node *p,*q;
	p=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d",&p->data);
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
	}
	else{
		q=head;
		while(q->next!=NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
	return head;
}
struct node* deletf(struct node *a)
{
	struct node *temp;
	if(a==NULL)
		printf("NO elements in list");
	else
	{
		temp=a;
		a=a->next;
		printf("Node %d is deleted \n",temp->data);
		free(temp);
	}
	return a;
}

struct node* deletr(struct node *head)
{
	struct node *p,*q;
	q=head;
	if(q->next==NULL)
	{
		return NULL;
	}
	while(q->next->next!=NULL)
	{
		q=q->next;
	}
	p=q->next;
	q->next=NULL;
	free(p);
	return head;
}


int main()
{
	struct node *prev,*head, *p;
	int n,i,key;
	head=NULL;
	for(;;)
	{
		printf("Enter the option\n1.display\n2.insert\n3.delete\n");
		scanf("%d",&key);
		switch (key)
		{
			case 2:  printf("Enter the option\n1.Ifront\n2.Iend	\n");
				scanf("%d",&key);
				switch(key)
				{
					case 1: head = front(head);break;
					case 2: head = end(head);break;
				}
				break;
			case 1: display(head);break;
			case 3: printf("Enter the option\n1.Dfront\n2.Dend \n");
                    scanf("%d",&key);
                    switch(key)
                    {
                        case 1:head=deletf(head);break;
                        case 2:head=deletr(head);break;

                    }
                    break;
			default:return 0;
		}
	}
}
