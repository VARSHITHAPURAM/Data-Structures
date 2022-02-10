#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};


void Push(struct Node**,int);
int Pop(struct Node**);
void Traversal(struct Node *);

int main(){
	int want_continue, choice, data;
	struct Node *top = NULL;
	printf("Enter 1.push ; 2.pop ; 3.Traversal\n");
	do{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : printf("Enter the value: ");
				  scanf("%d",&data);
				  Push(&top,data);
				  break;

			case 2 : data = Pop(&top);
				printf("Poped item: %d ", data);
				  break;

			case 3 : Traversal(top);
				  break;
		}
		printf("If you want to contine Enter 1 : ");
		scanf("%d",&want_continue);
	}while(want_continue == 1);
	return 0;
}



void Push(struct Node **top,int data){
	struct Node *temp;

	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;

	temp -> next = *top;
	(*top) = temp;

}

int Pop(struct Node **top){
	struct Node *temp;
	int data;
	temp = *top;
	if(*top == NULL){
		printf("UNderflown\n");
		exit(0);
	}
	else{
		temp = *top;
		data = temp->data;
		(*top) = (*top) -> next;
		temp -> next = NULL;
		free(temp);
		return data;
	}
}

void Traversal(struct Node *top){
	struct Node *temp;
	temp = top;
	while(temp != NULL){
		printf("%d\t",temp -> data);
		temp = temp -> next;
	}
}
