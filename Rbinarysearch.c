#include<stdio.h>
int Rbinarysearch(int a[],int key,int n,int beg,int end);
int main()
{
	int i,n,pos,key;
	int a[10];
	printf("enter n value: ");
	scanf("%d",&n);
	printf("enter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter key value: ");
	scanf("%d",&key);
	pos=binarysearch(a,key,n,beg,end);
	if(pos>0)
	printf("element is found at %d position",pos);
	else
	printf("element not found");
	return 0;
}
int binarysearch(int a[],int key,int n,int beg,int end)
{
	int mid;
	mid=(beg+end)/2;
	while(beg<=end)
	{
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			return Rbinarysearch(a,key,beg,mid-1);
		else
			return Rbinarysearch(a,key,mid+1,end);
	}
	return 0;
}
