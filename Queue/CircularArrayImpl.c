#include<stdio.h>
#define capacity 3
int arr[capacity];
int rear=-1;
int front=-1;
int size=0;
int isFull(){
    return size==capacity;
}
int isEmpty(){
    return size==0;
}
void enque(int data){
    if(front==-1)
        front=0;
    if(!isFull()){
        size++;
        rear=++rear%capacity;
        arr[rear]=data;
        printf("Enqued...");
    }
    else
        printf("Queue is Full");
}
int deque(){
    if(!isEmpty()){
        size--;
        int x=arr[front++];
        front=front%capacity;
        printf("Dequed...");
        return x;
    }
    else{
        printf("Queue is Empty");
        return -01;
    }
}
int top(){
    if(!isEmpty())
        return arr[front];
    else
        printf("Queue is Empty");
}
int menu(){
    printf("1 :Enqueue \n");
    printf("2 :Dequeue \n");
    printf("3 :Front \n");
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
            printf("Enter data :");
            scanf("%d",&data);
            enque(data);
            break;
        case 2:
            deque();
            break;
        case 3:
            if(!isEmpty()){
                printf("Front :%d",top());
            }
            else{
                printf("Queue is Empty");
            }
            break;
        default:
            printf("Enter a Valid Option ");
        }
        getch();
        system("cls");
    }
}
