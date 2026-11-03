#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*top=NULL;
void push()
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&newnode->data);
	newnode->next=top;
	top=newnode;
	printf("Inserted sucessfully");
}
void pop()
{
	struct node*temp;
	if(top==NULL)
	{
		printf("Stack underflow");
	}
	else
	{
		temp=top;
		printf("Deleted element:%d",top->data);
		top=top->next;
		free(temp);
	}
}
void display()
{
	struct node*temp;
	if(top=NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		temp=top;
		printf("Stack Elements are:");
		while(temp!=NULL)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	int ch;
	do
	{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter the choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exit");
				break;
			default:
				printf("Invalid choice");
		}
	}while(ch!=4);
	return 0;
}
