#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int capacity;
    int front;
    int rear;
    int* arr;
};
struct node* createQueue(unsigned capacity){
    struct Queue* newNode=malloc(sizeof(struct Queue));
    newNode->front=0;
    newNode->rear=-1;
    newNode->arr=malloc(capacity*sizeof(int));
    newNode->capacity=capacity;
    newNode->size=0;
    return newNode;
};
int isFull(struct Queue* Q){
    return Q->size==Q->capacity;
}
int isEmpty(struct Queue* Q){
    return Q->size==0;
}
void enqueue(struct Queue* Q,int data){
    if(!isFull(Q)){
        (Q->size)++;
        Q->arr[++(Q->rear)]=data;
    }
    else
        printf("Queue is Full");
}
int deque(struct Queue* Q){
    if(!isEmpty(Q)){
        (Q->size)--;
        return Q->arr[(Q->front)++];
    }
    else
        return 0;
}
int Top(struct Queue* Q){
    if(!isEmpty(Q))
        return Q->arr[Q->front];
    else
        return 0;
}
int menu(){
    printf("1 :Enqueue \n");
    printf("2 :Dequeue \n");
    printf("3 :Top\n");
    printf("Choose your Option :");
    int c;
    scanf("%d",&c);
    return c;
}
int main(void){
    struct Queue* q1=createQueue(3);
    int data;
    while(1){
        switch(menu()){
        case 1:
            printf("Enter Data :");
            scanf("%d",&data);
            enqueue(q1,data);
            break;
        case 2:
            printf("Removed Data :%d",deque(q1));
            break;
        case 3:
            printf("Top data :%d",Top(q1));
            break;
        }
        getch();
        system("cls");
    }

}
