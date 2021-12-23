//priority queue using singly LinkedList
//This queue arrange node as decreasing order of priority
//if priority equal for two node then it fallows queue order FIFO
//dequeue also from high to low priority and as queue
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    int priority;
    struct node* next;
};
struct node* head=NULL;
struct node* createNode(int data,int priority){
    struct node* NewNode=malloc(sizeof(struct node));
    NewNode->info=data;
    NewNode->priority=priority;
    NewNode->next=NULL;
    return NewNode;
};
void enqueue(int data,int p){
    struct node* newNode=createNode(data,p);
    struct node* curr=head;
    if(!head)
        head=newNode;
    else if(newNode->priority>head->priority){
        newNode->next=head;
        head=newNode;
    }
    else{
        while(curr->next!=NULL && newNode->priority<=curr->next->priority){
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
    }
    printf("Enqueued......");
}
int deque(){
    if(!head){
        printf("Queue is Empty");
        return -1;
    }
    else{
        struct node* temp=head;
        int x=temp->info;
        head=head->next;
        free(temp);
        printf("Dequeued....%d",x);
        return x;
    }
}
int top(){
    if(!head)
        printf("Queue is Empyt");
    else{
        printf("Top :%d",head->info);
        return head->info;
    }
}
int menu(){
    printf("1 :Enqueue\n");
    printf("2 :Dequeue\n");
    printf("3 :Top\n");
    printf("Choose your Option :");
    int ch;
    scanf("%d",&ch);
    return ch;
}
int main(void){
    int data;
    int proity;
    while(1){
        switch(menu()){
        case 1:
            printf("Enter Data :");
            scanf("%d",&data);
            printf("Enter priority :");
            scanf("%d",&proity);
            enqueue(data,proity);
            break;
        case 2:
            deque();
            break;
        case 3:
            top();
            break;
        }
        getch();
        system("cls");
    }
}
