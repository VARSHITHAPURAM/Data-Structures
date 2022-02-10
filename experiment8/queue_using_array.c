#include <stdio.h>
#include <stdlib.h>


#define Max_Size 5
int Queue[Max_Size],rear = -1,front = -1;
int IsFull();
int IsEmpty();
void Enqueue(int);
int Dequeue();
void Traversal();



int main(){
	int want_continue, choice, data,val;
	printf("Enter 1.Enqueue ; 2.Dequeue ; 3.Traversal\n");
	do{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		IsEmpty();
		IsFull();
		switch(choice){
			case 1 : printf("Enter the value: ");
				  scanf("%d",&data);
				  Enqueue(data);
				  break;

			case 2 : val =Dequeue();
				  printf("The deleted value is ""%d\n",val);
				  break;

			case 3 : Traversal();
				  break;
		}
		printf("If you want to contine Enter 1 : ");
		scanf("%d",&want_continue);
	}while(want_continue == 1);
	return 0;
}

int IsFull(){
	return rear == Max_Size - 1;
}

int IsEmpty(){
	return front == -1;
}

void Enqueue(int data){
	if(IsFull() == 1){
		printf("Overflown\n");
		return;
	}
	if(front == -1){
		front = rear = 0;
	}
	else{
		rear += 1;

	}
	Queue[rear] = data;
}

int Dequeue(){
	int data;
	if(IsEmpty() == 1){
		printf("Underflown\n");
		exit(0);
	}
	data = Queue[front];
	if(front == rear){
		front = rear = -1;
	}
	else{
		front += 1;
	}
	return data;

};

void Traversal(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d\t",Queue[i]);
	}
}
