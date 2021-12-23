#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int count=0;
struct node* last=NULL;
struct node* createNode(int data){
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=newNode;
    return newNode;
};
void insertLast(int data){
    struct node* newNode=createNode(data);
    if(!last)
        last=newNode;
    else{
        newNode->next=last->next;
        last->next=newNode;
        last=newNode;
    }
    printf("Queueed");
    count++;
}
int removeHead(){
    if(!last){
        printf("List is Empty");
        return -1;
    }
    else if(last->next==last){
        count--;
        free(last);
        last=NULL;
        printf("Dequeueed");
    }
    else{
        count--;
        struct node* temp=last->next;
        last->next=temp->next;
        int x=temp->data;
        free(temp);
        printf("Dequeueed");
        return x;
    }
}
void showHead(){
    if(!last){
        printf("List is empty");
        return;
    }
    printf("Your data :%d",(last->next)->data);
}
int size(){
    return count;
}
int menu(){
    printf("1 :Enqueue \n");
    printf("2 :Dequeue \n");
    printf("3 :Top \n");
    printf("4 :Size \n");
    printf("Choose your Option :");
    int ch;
    scanf("%d",&ch);
    return ch;
}
int main(void){
    int data;
    while(1){
        switch(menu()){
        case 1:
            printf("Enter Data :");
            scanf("%d",&data);
            insertLast(data);
            break;
        case 2:
            removeHead();
            break;
        case 3:
            showHead();
            break;
        case 4:
            printf("Size is :%d",size());
            break;
        default:
            printf("Enter a Valid Option");
            break;
        }
        getch();
        system("cls");
    }
}
