#include<stdio.h>
int capacity=10;
int top=-1;
int arr[10];
void push(int data){
    if(top==capacity-1){
        printf("stack overflow.....");
        return;
    }
    else{
        arr[++top]=data;
        printf("data inserted.......");
    }
}
int pop(){
    if(top==-1){
        printf("stack underflow......");
        return -1;
    }
    else{
        int data=arr[top--];
        return data;
    }
}
int peek(){

    if(top==-1){
        printf("Stack underflow......");
        return -1;
    }
    return arr[top];
}
int size(){
    return top+1;
}
int menu(){
    printf("1:Push\n");
    printf("2:Pop\n");
    printf("3:Peek\n");
    printf("4:Size\n\n");
    printf("Select an Option :");
    int ch;
    scanf("%d",&ch);
    return ch;
}
int main(void){

    int data;
    while(1){
        switch(menu()){
        case 1:{
            printf("Enter data :");
            scanf("%d",&data);
            push(data);
            break;
            }
        case 2:{
            printf("%d",pop());
            break;
            }
        case 3:{
            printf("%d",peek());
            break;
        }
        case 4:{
            printf("%d",size());
            break;
        }
        default:
            printf("\nEnter a valid option....");
        }
        getch();
        system("cls");
    }
}
