#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack{
	int arr[SIZE];
	int top;
};

void init_stack(struct stack *st){
	st->top = -1;
}

void push(struct stack *st,int num);
void pop(struct stack *st);
void display(struct stack *st);

int main()
{
	int choice,ele,val;
	struct stack* ptr;
	init_stack(ptr);
	while(1)
	{
		printf("1)PUSH\n2)POP\n3)display\n4)exit\n");
              scanf("%d",&choice);
		switch(choice){
			case 1:
				{
			       printf("\nEnter the element:");
		       		scanf("%d",&val);
		 		push(ptr,val);
				break;}
			case 2: pop(ptr);break;
			case 3:printf("Elements in the stack are :");
			       display(ptr);break;
			case 4: exit(0);
			default : printf("plese enter valid choice");
		}

	}
}
void push(struct stack *st,int num)
{
	if(st->top == (SIZE-1))
		printf("Stackoverflow\n");
	else{
		st->top++;
		st->arr[st->top] = num;
	}
	

}
void pop(struct stack *st)
{
	if(st->top == -1)
		printf("Stackunderflow\n");
	else{
		printf("%d ",st->arr[st->top]);
		st->top--;
	}
}
void display(struct stack *st)
{
	int i;
	if(st->top == -1)
		printf("Stack empty\n");
	else{
	printf("Elements present in the stack are:");
	for(i=st->top;i>=0;i--)
		printf("%d ",st->arr[i]);
	}
}
