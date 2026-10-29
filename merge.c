#include<stdio.h>
int main()
{	
int a[10],b[10],c[10],n,m,s,i;
printf("Enter the size first array:");
scanf("%d",&n);
printf("Enter the elements in the first array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
printf("Enter the size the second array:");
scanf("%d",&m); 
printf("enter the elements in the second array:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
for(i=0;i<n;i++)
{
	c[i]=a[i];
}
for(i=0;i<m;i++)
{
	c[i+m]=b[i];
}	
printf("Merged array is:\n");
	for(i=0;i<m+n;i++)
	{
		printf("%d ",c[i]);
	}
}
