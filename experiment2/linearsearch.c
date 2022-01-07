#include<stdio.h>
int  Rlinearsearch(int a[],int key,int n);
int main()
{  
	int i,n,pos,key;
	int a[10];
	printf("enter the value of n");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
	{  
		scanf("%d",&a[i]);
	}
	printf("enter value of key element to be search");
	scanf("%d",&key);
	pos=Rlinearsearch(a,key,n);
	if(pos>0)
	printf("element is found at %d position",pos);
	else
	printf("element not found");     
	return 0;  
} 

int Rlinearsearch(int a[],int key,int n)
{
	if(n>0)
	{
		if(a[n-1]==key)
		return n-1;
		else
		return Rlinearsearch(a,key,n-1);
	}
		return -1;
}
