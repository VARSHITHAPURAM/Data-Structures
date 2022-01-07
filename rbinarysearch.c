#include<stdio.h>
int Rbinarysearch(int[],int ,int ,int ,int);
int main()
{
	int i,n,pos,key,beg,end;
	int a[10];
	printf("enter n value: ");
	scanf("%d",&n);
	printf("enter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter key value: ");
	scanf("%d",&key);
	pos=Rbinarysearch(a,key,n,beg,end);
	if(pos>=0)
		printf("element is found at %d position",pos);
	else
		printf("element not found");
	return 0;
}
int Rbinarysearch(int a[],int key,int n,int l,int r)
{
	int m;
	m=(l+r)/2;
	if(a[m]==key)
		return m;
	else if(a[m]>key)
		return Rbinarysearch(a,key,n,l,m-1);
	else
		return Rbinarysearch(a,key,n,m+1,r);
	return -1;
}
