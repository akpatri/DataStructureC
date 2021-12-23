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
void infixToPostfix(char* a,int *size){

    int i,k;
    for(i=0,k=-1;a[i];++i){
        //printf("%c",a[i]);

        if(isOperand(a[i]))
            a[++k]=a[i];
        else if(a[i]=='(')
            push(a[i]);
        else if(a[i]==')'){
            while(!stackUnderFlow()&&peek()!='('){
                a[++k]=pop();
            }
            if (!stackUnderFlow() && peek() != '(')
                return -1; // invalid expression
            else
                pop();
        }
        else{
            while(!stackUnderFlow()&&prority(a[i])<=prority(peek())){
                a[++k]=pop();
            }
            push(a[i]);
        }

    }
    while(!stackUnderFlow()){
        a[++k]=pop();
    }
    a[++k]='\0';
    *size=strlen(a);
    //printf("%s",out);
}
void reverseString(char *a,int size){
    for(int lower=0,upper=size-1;lower<upper;lower++,upper--){
        char temp=a[lower];
        a[lower]=a[upper];
        a[upper]=temp;
    }
}
void replacePranthesis(char* a){
    for(int i=0;a[i];i++){
        if(a[i]=='('){
            a[i]=')';
        }
        else if(a[i]==')'){
            a[i]='(';
        }
    }
}
void infixToPrefix(char *exp,int size){
    reverseString(exp,size);
    replacePranthesis(exp);
    infixToPostfix(exp,&size);
    reverseString(exp,size);
    printf("%s",exp);
}
int main(void){
    while(1){
        printf("Enter Infix Exp :");
        char exp[10];
        scanf("%s",&exp);
        printf("Prefix Expression :");
        infixToPrefix(exp,strlen(exp));
        getch();
        system("cls");
    }
}
