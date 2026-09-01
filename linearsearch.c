#include<stdio.h>
int main()
{
	int a[10],i,k,n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the number to be search:");
	scanf("%d",&k);
	
	for(i=0;i<n;i++)
	{	
		if(a[i]==k)
		{
			printf("The number found at %d and index position %d",i+1,i);
			return 0;
		}
	}
	printf("Element not found");
}
	
