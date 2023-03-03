#include <stdlib.h>
#include <stdio.h>

struct node{
	int x;
	struct node *next;
	struct node *prev;
};
struct node *head,*tail;
int data_count;

void CreateLinkedList(int value){
	printf("Inputted Value: %d\n", value);
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
	newnode->x=value;
	newnode->next=NULL;
	head=newnode;
	tail=head;
	head->next=tail;head->prev=NULL;
	tail->prev=head;tail->next=NULL;
    data_count++;
}

void insert_head(int value){
	printf("Inputted Value: %d\n", value);
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
	newnode->x = value;
	head->prev=newnode;
	newnode->next = head;
	head = newnode;
    data_count++;
}

void insert_tail(int value){
	printf("Inputted Value: %d\n", value);
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
	newnode->x = value;
	newnode->next = NULL;
	newnode->prev = tail;
	tail->next=newnode;
	tail = newnode;
    data_count++;
}

void insert_midList(int pos, int value){
	if(pos==0){
		insert_head(value);
		return;
	}

	if(pos>data_count){
		printf("Invalid position\n");
		return;
	}

	if(pos==data_count){
		insert_tail(value);
		return;
	}
	printf("Inputted Value: %d || Index : %d\n", value, pos);
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->x = value;
	struct node *curr, *prev;
	curr = head;
	for(int i = 0; i<pos; i++){
		prev = curr;
		curr = curr->next;
	}
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = curr;
	curr->prev = newnode;
    data_count++;
    return;
}

void delete_head(){
	printf("Deleted item: %d\n", head->x);
	head = head->next;
	head->prev = NULL;
    data_count--;
}

void delete_tail(){
	printf("Deleted item : %d\n", tail->x);
	tail = tail->prev;
	tail->next = NULL;
    data_count--;
}

void delete_midList(int pos){
	if(pos==0){
		delete_head();
		return;
	}

	if(pos>=data_count){
		printf("Invalid Position\n");
		return;
	}

	if(pos==data_count-1){
		delete_tail();
		return;
	}

	struct node *curr, *prev, *next;
	curr = head;
	for(int i = 0; i<pos; i++){
		prev = curr;
		curr = curr->next;
		next = curr->next;
	}
	printf("Deleted Item: %d", curr->x);printf(" || Index : %d\n", pos);
	prev->next = next;
	next->prev = prev;
	free(curr);
    data_count--;
    return;
}

int main()
{
	CreateLinkedList(1);
	insert_tail(2);
	insert_tail(3);
	insert_midList(2, 4);
	printf("Print list using head as reference point:\n");
	printf("%d %d %d %d\n", head->x, head->next->x, head->next->next->x, head->next->next->next->x);
	printf("Print list using tail as reference point:\n");
	printf("%d %d %d %d\n\n", tail->prev->prev->prev->x, tail->prev->prev->x, tail->prev->x, tail->x);

	printf("Check if the input exception works: \n");
	insert_midList(5, 10);
	printf("\n");

	delete_head();
	printf("Print list using head as reference point:\n");
	printf("%d %d %d\n", head->x, head->next->x, head->next->next->x);
	printf("Print list using tail as reference point:\n");
	printf("%d %d %d\n\n", tail->prev->prev->x, tail->prev->x, tail->x);

	delete_tail();
	printf("Print list using head as reference point:\n");
	printf("%d %d\n", head->x, head->next->x);
	printf("Print list using tail as reference point:\n");
	printf("%d %d\n\n", tail->prev->x, tail->x);

	insert_tail(3);
	printf("Input check:\n");
	printf("%d %d %d %d\n\n", head->x, head->next->x, tail->prev->x, tail->x);

	printf("Check if delete exception works:\n");
	delete_midList(10);
	printf("\n");

	delete_midList(1);
	printf("Print list using head as reference point:\n");
	printf("%d %d\n", head->x, head->next->x);
	printf("Print list using tail as reference point:\n");
	printf("%d %d\n", tail->prev->x, tail->x);
    return 0;
}
