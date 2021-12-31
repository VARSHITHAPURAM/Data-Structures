#include<stdio.h>
int binarysearch(int a[],int key,int n);
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
	pos=binarysearch(a,key,n);
	if(pos>0)
	printf("element is found at %d position",pos);
	else
	printf("element not found");
	return 0;
}
int binarysearch(int a[],int key,int n)
{
	int mid,beg=0,end=n-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]<key)
			beg=mid+1;
		else
			end=mid-1;
	}
	return 0;
}
	
