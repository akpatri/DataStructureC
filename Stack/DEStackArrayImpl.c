//Double Ended Stack array Implementation
//LStack->left end stack
//RStack->Right end stack
//F(front) represent RStack
//R(rear) represent LStack
#include<stdio.h>
#define capacity 3
int arr[capacity];
int front=-1;
int rear=-1;
int countF=0;
int countR=0;
int isEmpty(char c){
    if(c=='r')
        return countR==0;
    else if(c=='f')
        return countF==0;
}
int isFull(){
    return (countF+countR)==capacity;
}
//insert From first side of queue
void insert_rear(int data){
    if(!isFull()){
        countR++;
        arr[++rear]=data;
        printf("Data Inserted");
    }
    else{
        printf("L-Stack is Full");
        return;
    }
}
//Insert from Last side of queue
void insert_front(int data){
    if(!isFull()){
        countF++;
        arr[front--]=data;
        printf("Data Inserted");
    }
    else{
        printf("R-Stack is Full");
        return;
    }
}
//delete from left side queue
int delete_rear(){
    if(!isEmpty('r')){
        countR--;
        printf("L-Stack data deleted %d",arr[rear]);
        return arr[rear--];
    }
    else{
        printf("L-Stack is Empty");
        return 0;
    }
}
//delete from right side queue
int delete_front(){
    if(!isEmpty('f')){
        countF--;
        printf("R-Stack data deleted :%d",arr[++front]);
        return arr[front];
    }
    else{
        printf("R-Stack is empty");
        return 0;
    }
}
int FTop(){
    if(countF){
        int fr=front+1;
        printf("R-Stack Top data :%d",arr[fr]);
        return arr[front];
    }
    else{
        printf("R-Stack is empty");
        return 0;
    }
}
int RTop(){
    if(countR){
        printf("L-Stack Top data :%d",arr[rear]);
        return arr[rear];
    }
    else{
        printf("L-Stack is empty");
        return 0;
    }
}
int size(){
    printf("Total size :%d",countF+countR);
    return countF+countR;
}
int menu(){
    printf("1 :L-Stack Insert\n");
    printf("2 :R-Stack Insert\n");
    printf("3 :L-Stack Remove\n");
    printf("4 :R-Stack Remove\n");
    printf("5 :L-Stack Top\n");
    printf("6 :R-Stack Top\n");
    printf("7 :Total size \n");
    printf("Choose an Option :");
    int ch;
    scanf("%d",&ch);
    return ch;
}
int main(){
    int data;
    while(1){
        switch(menu()){
        case 1:
            printf("Insert data :");
            scanf("%d",&data);
            insert_rear(data);
            break;
        case 2:
            printf("Insert data :");
            scanf("%d",&data);
            insert_front(data);
            break;
        case 3:
            delete_rear();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            RTop();
            break;
        case 6:
            FTop();
            break;
        case 7:
            size();
            break;
        default :
            printf("Enter valid Option");
        }
        getch();
        system("cls");
    }
}
