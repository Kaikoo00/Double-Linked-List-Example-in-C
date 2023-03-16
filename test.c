//Edrico Putra Pramana
//LB20 - 2602078133

#include <stdlib.h>
#include <stdio.h>

struct node{
	int x;
	struct node *next;
	struct node *prev;
};
struct node *head,*tail;
int data_count;

void display(){
	if(!data_count){
		printf("Linked List is still empty!\n");
		system("pause");
		system("cls");
		return;
	}
    int i=0;
    printf("======================\n");
    printf("|| Index || Element ||\n");
    printf("======================\n");
    for(struct node *curr=head; curr!=NULL; curr=curr->next){
        printf("||%7d||%9d||\n", i, curr->x);
        printf("----------------------\n");
        i++;
    }
    system("pause");
    system("cls");
    return;
}

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
    if(head==NULL){
        printf("Please create a new linked list first.\n");
        return;
    }
	printf("Deleted item: %d\n", head->x);
	head = head->next;
	head->prev = NULL;
    data_count--;
}

void delete_tail(){
    if(head==NULL){
        printf("Please create a new linked list first.\n");
        return;
    }
	printf("Deleted item : %d\n", tail->x);
	tail = tail->prev;
	tail->next = NULL;
    data_count--;
}

void delete_midList(int pos){
    if(head==NULL){
        printf("Please create a new linked list first.\n");
        return;
    }

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

void menu_insert(){
    int ch;
    do
    {
        printf("==========Insert Menu==========\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert at Custom Position\n");
        printf("0. Exit\n");
        printf("Input your choice:");
        scanf("%d", &ch);getchar();
        system("cls");
    } while (0>ch || ch>3);

    switch (ch)
    {
    case 0:
        system("cls");
        return;
        break;

    case 1:
        int insertHead;
        printf("Input your number:");
        scanf("%d", &insertHead);getchar();
        if(data_count==0)CreateLinkedList(insertHead);
        else insert_head(insertHead);
        system("cls");
        break;

    case 2:
        int insertTail;
        printf("Input your number:");
        scanf("%d", &insertTail);getchar();
        if(data_count==0)CreateLinkedList(insertTail);
        else insert_tail(insertTail);
        system("cls");
        break;

    case 3:
        int insertMid;
        printf("Insert your number:");
        scanf("%d", &insertMid);getchar();
        printf("Insert the position(Index):");
        int pos;
        scanf("%d", &pos);getchar();
        if(data_count==0 && pos == 0) CreateLinkedList(insertMid);
        else insert_midList(pos, insertMid);
        system("cls");
        break;

    default:
        printf("Invalid Input\n");
        system("pause");
        system("cls");
        return;
    }
    display();
    return;
}

void menu_delete(){
    int ch;
    do
    {
        printf("==========Delete Menu==========\n");
        printf("1. Delete at the Beginning\n");
        printf("2. Delete at the End\n");
        printf("3. Delete at Custom Position\n");
        printf("0. Exit\n");
        printf("Input your choice:");
        scanf("%d", &ch);getchar();
        system("cls");
    } while (0>ch || ch>3);

    switch(ch){
        case 0:
            system("cls");
            return;
            break;
        
        case 1:
            delete_head();
            printf("Succeed\n");
            break;
        
        case 2:
            delete_tail();
            printf("Succedd\n");
            break;
        
        case 3:
            int i=0;
            printf("======================\n");
            printf("|| Index || Element ||\n");
            printf("======================\n");
            for(struct node *curr=head; curr!=NULL; curr=curr->next){
                printf("||%7d||%9d||\n", i, curr->x);
                printf("----------------------\n");
                i++;
            }
            int pos;
            printf("Input the position of the element(Index):");
            scanf("%d", &pos);getchar();
            if(0<=pos<data_count){
                delete_midList(pos);
            }
            else{
                printf("Invalid Positiomn\n");
                printf("Canceled\n");
            }
            break;
        
        default:
            printf("Invalid Input\n");
            break;
    }
    system("cls");
    display();
}

void print_menu(){
    while(1){
        int ch;
        do
        {
            printf("=========MENU=========\n");
            printf("1. Insert\n");
            printf("2. Delete\n");
            printf("3. Display\n");
            printf("0. Exit\n");
            printf("Input your choice:");
            scanf("%d", &ch); getchar();
            system("cls");
        } while (ch<0 || ch>3);
        
        switch (ch)
        {
        case 0:
            system("cls");
            printf("Thank you for using the program!\n");
            exit(1);
            break;
        
        case 1:
            menu_insert();
            break;

        case 2:
            menu_delete();
            break;
        
        case 3:
            display();
            break;
        
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}

int main()
{
    print_menu();
    return 0;
}
