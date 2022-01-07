#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
int top=-1;
int stack[maxsize];
int isempty()
{
	return top<0;
}
int isfull()
{
	return (top==maxsize-1);
}
void push(int item)
{
	if(isfull()==1)
	{
		printf("Overflow \n");
		return;
	}
	top+=1;
	stack[top]=item;
}
int pop()
{
	if(isempty()==1)
	{
		printf("Overflow \n");
		return 0;
	}
	return stack[top--];
}
void traversal()
{
	for(int i=0;i<=top;i++)
		printf("%d \n",stack[i]);
}
int main()
{
	int choice,want_continue,item;
	printf("Enter choice [1.push 2.pop 3.traversal]: \n");
	do {
		printf("Enter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter data to be pushed: \n");
				scanf("%d",&item);
				push(item);
				break;
			case 2:item=pop();
				printf("%d",item);
				break;
			case 3:traversal();
				break;
		}
		printf("Want to continue:[enter 1] \n");
		scanf("%d",&want_continue);
	}while(want_continue==1);
	return 0;
}
