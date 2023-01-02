#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* addToEmpty(int data){
	struct node* head = malloc(sizeof(struct node));
	head->data = data;
	head->next = NULL;
	return head;
}

void print_nodes(struct node* head){
	if(head == NULL)
		printf("Linked list is empty.\n");
	while(head != NULL){
		printf("%d ",head->data);
		head = head->next;
	}
}

struct node* add_begin(struct node* head,int num){
	struct node* new_node = malloc(sizeof(struct node));
	new_node->data = num;
	new_node->next = head;
	return new_node;
}

struct node* add_end(struct node* head,int num){
	struct node* temp = head;
	struct node* new_node = malloc(sizeof(struct node));
	new_node->data = num;
	new_node->next = NULL;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	return head;
}

struct node* add_pos(struct node* head,int pos,int num){
	if(pos == 1)
		head = add_begin(head,num);
	else{
	pos = pos-1;
	struct node* temp = head;
        struct node* new_node = malloc(sizeof(struct node));
	while(pos > 1){
		temp = temp->next;
		pos = pos-1;
	}
	new_node->data = num;
	new_node->next = temp->next;
	temp->next = new_node;
	}
	return(head);
}

struct node* del_head(struct node* head){
	head = head->next;
	return(head);
}

struct node* del_end(struct node* head){
	struct node* temp = head;
	while(temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	return(head);
}

struct node* del_pos(struct node* head,int pos){
	struct node* temp = head;
	if(pos == 1)
		head = del_head(head);
	else{
		pos = pos-1;
		while(pos > 1){
			temp = temp->next;
			pos = pos-1;
		}
		temp->next = temp->next->next;
	}
	return(head);
}
int main(){
	struct node* head = NULL;
	print_nodes(head);
	head = addToEmpty(10);
	print_nodes(head);
	head = add_begin(head,15);
	printf("\n");
	print_nodes(head);
	head = add_end(head,20);
        printf("\n");
        print_nodes(head);
	printf("\n");
	head = add_pos(head,3,99);
	print_nodes(head);
	printf("\n");
	head = del_pos(head,4);
	print_nodes(head);
        printf("\n");
}
