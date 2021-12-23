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
int isOpenBracket(char c){
    switch(c){
    case '(':
    case '{':
    case '[':
        return 1;
    default :
        return 0;
    }
}
int matchBracket(char a,char b){
    if(a=='('&&b==')')
        return 1;
    else if(a=='{'&&b=='}')
        return 1;
    else if(a=='['&&b==']')
        return 1;
    else
        return 0;
}
int balanceBracket(char *a){
    for(int i=0;a[i];i++){
        if(a[i]=='('||a[i]=='{'||a[i]=='['){
            push(a[i]);
        }
        else if(a[i]==')'||a[i]=='}'||a[i]==']'){
            if(stackUnderFlow()){
                return 0;
            }
            else if(!matchBracket(pop(),a[i])){
                return 0;
            }
        }
    }
    if(stackUnderFlow())
        return 1;
    else
        return 0;
}
int main(void){
    char exp[10];
    while(1){
        printf("Write Expression :");
        scanf("%s",exp);
        printf("Result :");
        if(balanceBracket(exp))
            printf("Balanced paranthesis");
        else
            printf("Unbalanced paranthesis");
            top=-1;
        getch();
        system("cls");
    }
}
