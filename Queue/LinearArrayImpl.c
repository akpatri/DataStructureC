#include<stdio.h>
#define capacity 10
int front=-1;
int rear=-1;
int arr[capacity];
int isFull(){
    return rear==capacity-1;
}
int isEmpty(){
    return (front==-1||front>rear);
}
void insert(int data){
    if(front==-1)
        front=0;
    if(!isFull()){
        arr[++rear]=data;
        printf("Inserted");
    }
    else
        printf("List is full");
}
int del(){
    if(!isEmpty()){
        int res=arr[front++];
        return res;
    }
    else{
        printf("UnderFlow..");
        front=rear=-1;
        return -1;
    }
}
int top(){
    if(!isEmpty())
        return arr[front];
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
    int data;
    while(1){
        switch(menu()){
        case 1:
            printf("Enter Data :");
            scanf("%d",&data);
            insert(data);
            break;
        case 2:
            printf("Removed Data :%d",del());
            break;
        case 3:
            printf("Top data :%d",top());
            break;
        }
        getch();
        system("cls");
    }

}
