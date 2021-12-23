#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* next;
};
struct node* head=NULL;
struct node* createNode(int data){
    struct node* NewNode=(struct node*)malloc(sizeof(struct node));
    if(NewNode){
        NewNode->info=data;
        NewNode->next=NULL;
        return NewNode;
    }
    else{
        printf("\nSpace not available..........");
        return NULL;
        }
};
void push(int data){
    if(head==NULL){
        head=createNode(data);
    }
    else{
        struct node* New=createNode(data);
        New->next=head;
        head=New;
    }
    printf("Data Inserted..............");
}
int pop(){
    if(head==NULL){
        printf("\nStack underflow............");
        return -1;
    }
    else{
        int data=head->info;
        struct node* temp=head;
        head=head->next;
        free(temp);
        return data;
    }
}
int peek(){
    if(head==NULL){
        printf("\nStack Underflow.........");
        return -1;
    }
    else{
        return head->info;
    }
}
int size(){
    int count=0;
    struct node* curr=head;
    while(curr!=NULL){
        curr=curr->next;
        ++count;
    }
    return count;
}
int menu(){
    printf("1:Push......\n");
    printf("2:Pop.......\n");
    printf("3:Peek......\n");
    printf("4:Size......\n\n");
    printf("Choose any Option :");
    int ch;
    scanf("%d",&ch);
    return ch;
}
int main(void){
    int data;
    while(1){
        switch(menu()){
            case 1:
                printf("Enter data :");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                printf("Poped data :");
                printf("%d",pop());
                break;
            case 3:
                printf("Peeked Data :");
                printf("%d",peek());
                break;
            case 4:
                printf("Size :");
                printf("%d",size());
                break;
        }
        getch();
        system("cls");
    }
}
