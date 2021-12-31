#include<stdio.h>
void bubblesort(int[],int);
int main()
{
	int A[20],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	bubblesort(A,n);
	printf("after sorting \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}return 0;
}
void bubblesort(int A[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{	
		for(j=0;j<n-1-i;j++)
		{	
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	
}
