#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* tail=NULL;
struct node* createNode(int data){
    struct node* NewNode=(struct node*)malloc(sizeof(struct node));
    if(NewNode){
        NewNode->next=NULL;
        NewNode->data=data;
        return NewNode;
    }
    else
        return NULL;
};
void insertTail(int data){
    struct node* newNode=createNode(data);
    if(!head){
        head=newNode;
    }
    else{
        tail->next=newNode;
    }
    tail=newNode;
    printf("Enqueed...");
}
int deleteHead(){
    if(head==NULL){
        printf("Queue is empty");
        return -1;
    }
    else{
        struct node* temp=head;
        int x=head->data;
        head=head->next;
        free(temp);
        printf("Dequees.......");
        return x;
    }
}

int show(){
    return head->data;
}
int menu(){
    printf("1 :Enque \n");
    printf("2 :DeQue \n");
    printf("3 :Show Front \n");
    int ch;
    printf("Choose your Option :");
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
            insertTail(data);
            break;
        case 2:
            if(!head)
                printf("Empty List");
            else
                printf("%d",deleteHead());
            break;
        case 3:
            if(!head)
                printf("Empty List");
            else
                printf("%d",show());
            break;
        default :
            printf("Enter valid option");
        }
        getch();
        system("cls");
    }
}
