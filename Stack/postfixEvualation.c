#include<stdio.h>
#include<string.h>
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
    return arr[-1];
}
int size(){
    return top+1;
}
int isOperand(char c){
    return ((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'));
}
int isOperator(char a){
    switch(a){
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    default :
        return 0;
    }
}
void postEvual(char *a){
    for(int i=0;a[i];i++){
        if(isOperand(a[i])){
            push(a[i]);
        }
        else{
            int n1=pop()%48;
            int n2=pop()%48;
            switch(a[i]){
                case '+':
                    push(n1+n2);
                    break;
                case '-':
                    push(n1-n2);
                    break;
                case '*':
                    push(n1*n2);
                    break;
                case '/':
                    push(n1/n2);
                    break;
            }
        }
    }
    int result=pop();
    printf("%d",result);

}
int main(void){
    char exp[10];
    while(1){
        printf("Enter postfix :");
        scanf("%s",exp);
        printf("Postfix result :");
        postEvual(exp);
        getch();
        system("cls");
    }
}
