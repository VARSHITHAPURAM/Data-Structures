#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void insert(struct node **head,int data,int pos)
{
	struct node *p,*q,*temp;
	int k=1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp -> data=data;
	p=*head;
	if(pos==1)
	{
		temp -> next=*head;
		*head=temp;
	}
	else {
		while((p!=NULL)&&(k<pos))
		{
			q=p;
			p=p->next;
			k++;
		}
		q->next=temp;
		temp->next=p;
	}
}
void delete(struct node **head,int pos)
{
	struct node *p,*q;
	int k=1;
	p=*head;
	if(pos==1)
	{
		*head=(*head) -> next;
		free(p);
	}
	else {
		while((p!=NULL)&&(k<pos))
		{
			q=p;
			p=p->next;
			k++;
		}
		if(p==NULL)
			printf("Node doesnot exist \n");
		else{
			q->next=p->next;
			free(p);
		}
	}
}
void traversal(struct node *head)
{
	struct node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d \t",p->data);
		p=p->next;
	}
}
struct node* search(struct node *head,int key)
{
	struct node *p;
	p=head;
	while(p!=NULL)
	{
		if(p->data == key)
			return p;
		p=p->next;
	}
	return NULL;
}
void kelement(struct node *head,int pos)
{
	struct node *p=head,*q;
	int c=1;
	while(c<=pos) {
		p=p->next;
		c++;
	}
	q = head;
	while(p!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	printf("%d  \n",q->data);
}
int main()
{
	int choice,want_continue,pos,data,key;
	printf("enter choice: 1.insert 2.delete 3.traversal 4.search 5.k element \n");
	struct node *head = NULL,*r;
	do {
		printf("enter choice \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter value & position: \n");
				scanf("%d%d",&data,&pos);
				insert(&head,data,pos);
				break;
			case 2: printf("enter position to delete: \n");
				scanf("%d",&pos);
				delete(&head,pos);
				break;
			case 3: traversal(head);
				break;
			case 4: printf("enter key value: \n");
				scanf("%d",&key);
				r = search(head,key);
				if(r==NULL)
					printf("Unsuccessful search \n");
				else
					printf("Successful search \n");
				break;
			case 5: printf("enter kth position from end: \n");
				scanf("%d",&pos);
				kelement(head,pos);
				break;
		}
		printf("want to continue,enter 1 \n");
		scanf("%d",&want_continue);
	}while(want_continue==1);
	return 0;
}	
		
	
