#include<stdio.h>
void selectionsort(int[],int);
int main()
{
	int A[20],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	selectionsort(A,n);
	printf("after sorting  \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}return 0;
}
void selectionsort(int A[],int n)
{
	int i,j,temp,minp;
	for(i=0;i<n-1;i++)
	{		
		minp=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[minp])
			{
			minp=A[j];
			}
			if(i!=minp)
			{
				temp=A[i];
				A[i]=A[minp];
				A[minp]=temp;
			}
		}
	}
	
}
