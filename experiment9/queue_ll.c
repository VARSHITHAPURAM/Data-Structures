#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
void Enqueue(int);
int Dequeue();
void Traversal();
struct node *Front = NULL;
struct node *Rear = NULL;

int main(){
	int choice,want_continue,data;
	printf("Enter choice:1.Enqueue,2.Dequeue,3.Traversal\n");
	do{
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter element:");
			       scanf("%d",&data);
			       Enqueue(data);
			       break;
			case 2:data = Dequeue();
			       printf("%d\n",data);
			       break;
			case 3:Traversal();
			       break;
		}
		printf("Want to continue, enter 1:");
		scanf("%d",&want_continue);
	}while(want_continue == 1);
	return 0;
}

void Enqueue(int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = data;
	temp -> next = NULL;
	if(Front == NULL){
		Front = Rear = temp;
	}
	else{
		Rear-> next = temp;
		Rear = temp;
	}
}
int Dequeue(){
	int data;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(Front == NULL){
		printf("Queue is Empty");
	}
	else{
		temp = Front;
		data = temp->data;
		Front = Front -> next;
		free(temp);
	}
	return data;
}

void Traversal(){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = Front;
	if(Front == NULL){
	    printf("Queue is Empty");
	}
	else{
		while(temp != NULL){
			printf("%d\t",temp->data);
			temp = temp -> next;
		}
	}
}
