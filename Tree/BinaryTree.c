#include<stdio.h>
#include<stdlib.h>
struct treeNode{
    struct treeNode* lchild;
    struct treeNode* rchild;
    int info;
};
//create queue
struct queue{
    int size;
    int front;
    int rear;
    unsigned capacity;
    struct node **arr;
};
struct queue* createQueue(unsigned capacity){
    struct queue* newQ=malloc(sizeof(struct queue));
    newQ->size=0;
    newQ->front=0;
    newQ->rear=-1;
    newQ->capacity=capacity;
    newQ->arr=malloc(capacity*sizeof(struct treeNode*));
    return newQ;
};
int isEmpty(struct queue* q){
    return q->size==0;
}
int isFull(struct queue* q){
    return q->size==q->capacity;
}
void enqueue(struct queue* q,struct node* data){
    if(!isFull(q)){
        q->size++;
        q->rear=++q->rear%q->capacity;
        q->arr[q->rear]=data;
    }
    else{
        printf("Queue is Full");
        return;
    }
}
struct treeNode* dequeue(struct queue* q){
    if(!isEmpty(q)){
        q->size--;
        int x=q->arr[q->front++];
        q->front=q->front%q->capacity;
        return x;
    }
    else
        printf("Queue is empty");
        return NULL;
}
struct treeNode* top(struct queue* q){
    if(!isEmpty(q))
        return q->arr[q->front];
    else
        printf("Queue is Empty");
        return NULL;
}
//tree
struct treeNode* createNode(int data){
    struct treeNode* newNode=malloc(sizeof(struct treeNode));
    newNode->info=data;
    newNode->lchild=newNode->rchild=NULL;
    return newNode;
};
//tree insertion
struct queue* q1;
struct treeNode* root=NULL;
void insert(int data){
    static int status=0;
    if(!status){
        status=1;
        q1=createQueue(20);
    }
    struct treeNode* newNode=createNode(data);
    if(!root)
        root=newNode;
    else if(!top(q1)->lchild)
        top(q1)->lchild=newNode;
    else if(!top(q1)->rchild)
        dequeue(q1)->rchild=newNode;
    enqueue(q1,newNode);
}
//show tree
struct queue* q2;
void lOrder(){
    if(root){
        static int status=0;
        if(!status){
            status=1;
            q2=createQueue(20);
        }
        enqueue(q2,root);
        while(!isEmpty(q2)){
            if(top(q2)){
                if(top(q2)->lchild)
                    enqueue(q2,top(q2)->lchild);
                if(top(q2)->rchild)
                    enqueue(q2,top(q2)->rchild);
                printf("%d ",dequeue(q2)->info);
            }
        }
    }
    else{
        printf("Tree is Empty");
        return;
    }
}
//lchild-root-rchild
void inOrder(struct treeNode* root){
    if(root){
        inOrder(root->lchild);
        printf("%d ",root->info);
        inOrder(root->rchild);
    }
}
//root-lchild-rchild
void preOrder(struct treeNode* root){
    if(root){
        printf("%d ",root->info);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}
//lchild-rchild-root
void postOrder(struct treeNode* root){
    if(root){
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d ",root->info);
    }
}
int countNode(struct treeNode* root){
    if(!root)
        return 0;
    else
        return 1+countNode(root->lchild)+countNode(root->rchild);
}
int add=0;
int sum(struct treeNode* root){
    if(root){
        if(root->lchild)
            add+=sum(root->lchild);
        if(root->rchild)
            add+=sum(root->rchild);
    }
    return root->info;
}
int menu(){
    printf("1 :LOrderInsert \n");
    printf("2 :InOrderTraverse\n");
    printf("3 :PreOrderTraverse \n");
    printf("4 :PostOrderTraverse \n");
    printf("5 :ShowTree \n");
    printf("6 :countNode \n");
    printf("7 :sumOfNode\n");
    printf("Choose your Option :\n");
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
            insert(data);
            break;
        case 2:
            printf("LOrder :");
            lOrder();
            printf("\nInOrder :");
            inOrder(root);
            printf("\nPreOrder :");
            preOrder(root);
            printf("\nPostOrder :");
            postOrder(root);
            break;
        case 3:
            printf("InOrder :");
            inOrder(root);
            break;
        case 4:
            break;
        case 5:
            printf("LOrder :");
            lOrder();
            printf("\nInOrder :");
            inOrder(root);
            printf("\nPreOrder :");
            preOrder(root);
            printf("\nPostOrder :");
            postOrder(root);
            break;
        case 6:
            printf("Count Node :%d",countNode(root));
            break;
        case 7:
            sum(root);
            printf("sumOfNodes :%d",add+=root->info);
            break;
        default:
            printf("Enter a Valid Option ");
        }
        getch();
        system("cls");
    }
}
