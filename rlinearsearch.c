#include<stdio.h>
int Rlinear_search(int a[],int n,int key);
int main()
{
         int a[10];
         int i,n,pos,key;
         printf("enter the value of n");
         scanf("%d",&n);
         printf("enter the elements");
         for(i=0;i<n;i++)
         {
            scanf("%d",&a[i]);
         }
         printf("enter the value of key");
         scanf("%d",&key);
         pos=Rlinear_search(a,n,key);
         if(pos>=0)
         printf("element is found at %d position",pos);
         else
         printf("element not found");
         return 0;
}

int Rlinear_search(int a[],int n,int key)
{
       
        if(n>0)
        {
        	if(a[n-1]==key)
        		return n-1;
        	else
        	return Rlinear_search(a,n-1,key);
        		}
        		
        		return -1;
}
