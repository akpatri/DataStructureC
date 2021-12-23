#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top:3;
    unsigned int capacity;
    int *array;
};
//create a stack with given capacity
struct stack* createStack(unsigned capacity){
    struct stack* stack=(struct stack*)malloc(sizeof(stack));
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int *)malloc(capacity*sizeof(int));
    return stack;
};
//condition for stackOverFlow
int stackOverFlow(struct stack* s){
    return s->top==s->capacity-1;
}
//condition for stackUnderflow
int stackUnderFlow(struct stack* s){
    return s->top==-1;
}
//push opearation
void push(struct stack* s,int element){
    if(stackOverFlow(s)){
        printf("Stack Over Flow ");
        return;
    }
    else{
        s->array[++(s->top)]=element;
        printf("\nInserted successifully.......");
    }
}
//pop operation
int pop(struct stack* s){
    if(stackUnderFlow(s)){
        printf("\nStackUnderFlow ");
        return -1;
    }
    else{
        int n=s->array[(s->top)--];
        printf("Poped Element is :");
        return n;
    }
}
//peek operation
int peek(struct stack* s){
     if(stackUnderFlow(s)){
        printf("\nStackUnderFlow ");
        return -1;
    }
    else{
        int n=s->array[(s->top)];
        printf("Peeked Element :");
        return n;
}}
//menu
int menu(){
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");

    int ch;
    printf("\nChoose an Option :");
    scanf("%d",&ch);
    return ch;
}
int main(void){
    int data;
    printf("Enter the capacity of stack :");
    scanf("%d",&data);
    struct stack* s=createStack(data);
    system("cls");
    while(1){
        switch(menu()){
        case 1:
            printf("Insert Element :");
            scanf("%d",&data);
            push(s,data);
            break;
        case 2:
            printf("%d",pop(s));
            break;
        case 3:
            printf("%d",peek(s));
            break;

        default:
            printf("\nEnter a Valid option\n");
        }
        getch();
        system("cls");
    }

}
