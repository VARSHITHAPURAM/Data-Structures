#include<stdio.h>
void insertionsort(int[],int);
int main()
{
	int A[20],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	insertionsort(A,n);
	printf("after sorting \n");
	for(i=0;i<n;i++)
	{
		printf("%d \t",A[i]);
	}return 0;
}
void insertionsort(int A[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{	
		key=A[i];
		j=i-1;
		while((j>=0)&&(A[j]>key))
		{	
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
	}
	
}
