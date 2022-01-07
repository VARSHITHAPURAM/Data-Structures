#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void insert_beg(struct node **head,int data)
{
	struct node *p,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	p=*head;
	if(*head==NULL) {
		temp->next=temp;
		*head=temp;
	}
	else {
		while(p->next!=*head) 
			p=p->next;
		temp->next=*head;
		p->next=temp;
		*head=temp;
	}
}
void insert_pos(struct node *head,int data,int pos)
{
	struct node *p,*temp,*q;
	int k=1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	p=head;
	while(k<pos) {
		q=p;
		p=p->next;
		k++;
	}
	q->next=temp;
	temp->next=p;
}
void insert_end(struct node **head,int data)
{
	struct node *p,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	p=*head;
	if(*head==NULL)
	{
		temp->next=temp;
		*head=temp;
	}
	else {
		while(p->next!=*head)
			p=p->next;
		p->next=temp;
		temp->next=*head;
	}
}
void traversal(struct node *head)
{
	struct node*p;
	p=head;
	do {
		printf("%d \t",p->data);
		p=p->next;
	}while(p!=head);
}
void delete_beg(struct node **head)
{
	struct node *p=*head;
	if(*head==NULL)
	{
		printf("Empty CLL \n");
		return;
	}
	if((*head)->next !=*head)
	{
		*head=NULL;
		free(p);
	}
	else {
		while(p->next!=*head)
			p=p->next;
		*head=(*head)->next;
		p->next=*head;
		free(p);
	}
}
void delete_end(struct node **head)
{
	struct node *p=*head,*q;
	if(*head==NULL) {
		printf("Empty CLL \n");
		return;
	}
	if((*head)->next !=*head)
	{
		*head=NULL;
		free(p);
	}
	else {
		while(p->next!=*head){
			q=p;
			p=p->next;
		}
		q->next=*head;
		free(p);
	}
}
void delete_pos(struct node **head,int pos)
{
	struct node *p=*head,*q;
	int k=1;
	if(*head==NULL) {
		printf("Empty CLL \n");
		return;
	}
	if((*head)->next=*head)
	{
		*head=NULL;
		free(p);
	}
	else {
		while(k<pos) {
			q=p;
			p=p->next;
			k++;
		}
		q->next=p->next;
		free(p);
	}
}
struct node* search(struct node *head,int key)
{
	struct node *p;
	p=head;
	while(p!=NULL) {
		if(p->data=key)
			return p;
		p=p->next;
	}
	return NULL;
}
int main()
{
	int choice,want_continue,pos,data,key;
	printf("Enter choice (1.insert at beginning 2.insert at position 3.insert at end 4.traversal 5.delete at beginning 6.delete at end 7.delete at position) \n");
	struct node *head=NULL,*r;
	do {
		printf("Enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter value to be inserted at beginning: \n");
				scanf("%d",&data);
				insert_beg(&head,data);
				break;
			case 2:printf("enter value & position to be inserted: \n");
				scanf("%d%d",&data,&pos);
				insert_pos(head,data,pos);
				break;
			case 3:printf("Enter data to be inserted at end: \n");
				scanf("%d",&data);
				insert_end(&head,data);
				break;
			case 4:traversal(head);
				break;
			case 5:delete_beg(&head);
				break;
			case 6:delete_end(&head);
				break;
			case 7:printf("Enter the position to be deleted: \n");
				scanf("%d",&pos);
				delete_pos(&head,pos);
				break;
			case 8:printf("Enter key to be searched: \n");
				scanf("%d",&key);
				r=search(head,key);
				if(r==NULL)
					printf("Not found \n");
				else
					printf("Found \n");
				break;
		}
		printf("Want to continue: (enter 1) \n");
		scanf("%d",&want_continue);		
	}while(want_continue==1);
	return 0;
}
