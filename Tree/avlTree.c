#include<stdio.h>
#include<stdlib.h>
struct treeNode{
    int info;
    struct treeNode* lchild;
    struct treeNode* rchild;
};
struct treeNode* createNode(int data){
    struct treeNode* newNode=malloc(sizeof(struct treeNode));
    newNode->info=data;
    newNode->lchild=newNode->rchild=NULL;
    return newNode;
};
void inOrder(struct treeNode* root){
    if(root){
        inOrder(root->lchild);
        printf("%d ",root->info);
        inOrder(root->rchild);
    }
}
int max(int a,int b){
    return (a>b)?a:b;
}
int height(struct treeNode* root){
    if(!root)
        return -1;
    else
        return 1+max(height(root->lchild),height(root->rchild));
}
struct treeNode* rRotate(struct treeNode* root){
    struct treeNode* lc1=root->lchild;
    root->lchild=lc1->rchild;
    lc1->rchild=root;
    return lc1;
}
struct treeNode* lRotate(struct treeNode* root){
    struct treeNode* rc1=root->rchild;
    root->rchild=rc1->lchild;
    rc1->lchild=root;
    return rc1;
};
int bFactor(struct treeNode* root){
    return height(root->lchild)-height(root->rchild);
}

struct treeNode* setAvlRot(struct treeNode* root,int data){
    int bf=bFactor(root);
    if(bf>1 && root->lchild->info>data)
        return rRotate(root);
    else if(bf>1 && root->lchild->info<data){
        root->lchild=lRotate(root->lchild);
        return rRotate(root);
    }
    else if(bf<-1&& root->rchild->info<data)
        return lRotate(root);
    else if(bf<-1&& root->rchild->info>data){
        root->rchild=rRotate(root->rchild);
        return lRotate(root);
    }
    return root;
};
struct treeNode* insert(struct treeNode* root,int data){
    if(!root)
        root=createNode(data);
    else{
        if(data<root->info)
            root->lchild=insert(root->lchild,data);
        else if(data>root->info)
            root->rchild=insert(root->rchild,data);
    }
    return setAvlRot(root,data);
};
struct treeNode* minNode(struct treeNode* root){
    if(root){
        while(root->lchild!=NULL){
            root=root->lchild;
        }
        return root;
    }
};
struct treeNode* deleteNode(struct treeNode* root,int value){
    if(root){
        if(root->info==value){
            if(root->lchild&&root->rchild){
                struct treeNode* min=minNode(root->rchild);
                int temp=min->info;
                min->info=root->info;
                root->info=temp;
                deleteNode(root->rchild,value);
            }
            else if(root->lchild &&!root->rchild){
                struct treeNode* lchild=root->lchild;
                free(root);
                return lchild;
            }
            else if(root->rchild &&!root->lchild){
                struct treeNode* rchild=root->rchild;
                free(root);
                return rchild;
            }
            else if(!root->lchild&&!root->rchild){
                free(root);
                return NULL;
            }
        }
        else{
            if(value>root->info){
                root->rchild=deleteNode(root->rchild,value);
            }
            else if(value<root->info){
                root->lchild=deleteNode(root->lchild,value);
            }
        }
        return setAvlRot(root,value);
    }
};
int menu(){
    printf("1 :BSTInsert \n");
    printf("2 :InOrderTraverse\n");
    printf("3 :bFactor\n");
    printf("4 :DeleteNode\n");
    printf("5 :allInfo\n");
    printf("Choose your Option :");
    int ch;
    scanf("%d",&ch);
    return ch;
}
int main(void){
    struct treeNode* root=NULL;;
    int data;
    while(1){
        switch(menu()){
        case 1:
            printf("Enter data :");
            scanf("%d",&data);
            root=insert(root,data);
            printf("Root :%d",root->info);
            break;
        case 2:
            printf("InOrder :");
            inOrder(root);
            break;
        case 3:
            printf("bFactor :%d",bFactor(root));
            break;
        case 4:
            scanf("%d",&data);
            root=deleteNode(root,data);
            printf("Deleted :%d",data);
            break;
        case 5:
             printf("InOrder :");
             inOrder(root);
             printf("\nbFactor :%d",bFactor(root));
             printf("\nRoot :%d",root->info);
             break;
        default:
            printf("Enter a valid Option");
            break;
        }
        getch();
        system("cls");
    }
}
