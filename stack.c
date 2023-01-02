#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

int arr[SIZE],top = -1;

void push();
void pop();
void show();

void main()
{
	int choice;
	while(1)
	{
		printf("Enter 1 for push 2 for pop and 3 for show 4 for exit :");
       		 scanf("%d",&choice);
	switch(choice)
	{
		case 1:push();break;
		case 2:pop();break;
		case 3:show();break;
		case 4:exit(0);
		default:printf("Invalid choice");
	}		
	}
}

void push()
{
	int i;
	if(top == SIZE-1)
		printf("stackoverflow\n");
	else
	{
		top = top+1;
		printf("Enter the num:");
		scanf("%d",&i);
		arr[top] = i;
	}
}

void pop()
{
	int i;
        if(top == -1)
                printf("stackunderflow\n");
        else
        {
                printf("The num removed is %d\n",arr[top]);
                top = top - 1;
        }

}

void show()
{
	int i;
	if(top == -1)
		printf("stack Empty\n");
	else
	{
		for(i=top;i>=0;i--)
			printf("%d ",arr[i]);
		printf("\n");
	}
}
