#include<stdio.h>
int top=-1;
int capacity=10;
char arr[10];
int stackOverflow(){
    return top==capacity-1;
}
int stackUnderFlow(){
    return top==-1;
}
void push(char arg){
    if(!stackOverflow()){
        arr[++top]=arg;
    }
    else{
        printf("stackOverFlow");
        return;
    }
}
char pop(){
    if(!stackUnderFlow()){
        return arr[top--];
    }
    else{
        printf("stackUnderFlow");
    }
}
char peek(){
    if(!stackUnderFlow()){
        return arr[top];
    }
    else{
        printf("stackUnderFlow");
    }
}
int isOperand(char c){
    return ((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
}
int prority(char c){
    switch(c){
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;

    }
    return -1;
}
void infixToPostfix(char* a){
    char out[10];
    int i,k;
    for(i=0,k=-1;a[i];++i){
        if(isOperand(a[i]))
            out[++k]=a[i];
        else if(a[i]=='(')
            push(a[i]);
        else if(a[i]==')'){
            while(!stackUnderFlow()&&peek()!='('){
                out[++k]=pop();
            }
                pop();
        }
        else{
            while(!stackUnderFlow()&&prority(a[i])<=prority(peek())){
                out[++k]=pop();
            }
            push(a[i]);
        }
    }
    while(!stackUnderFlow()){
        out[++k]=pop();
    }
    out[++k]='\0';
    printf("%s",out);
}
int main(void){
    while(1){
        printf("Enter infix :");
        char a[10];
        scanf("%s",a);
        printf("\nPostFix exp :");
        infixToPostfix(a);
        getch();
        system("cls");
    }
    return 0;
}
