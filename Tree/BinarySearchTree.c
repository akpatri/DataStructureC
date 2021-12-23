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
struct treeNode* insert(struct treeNode* root,int value){
    if(root==NULL){
        root=createNode(value);
    }
    else{
        if(root->info>value){
            root->lchild=insert(root->lchild,value);
        }
        else if(root->info<value){
            root->rchild=insert(root->rchild,value);
        }
    }
    return root;
};
void inOrder(struct treeNode* root){
    if(root){
        inOrder(root->lchild);
        printf("%d ",root->info);
        inOrder(root->rchild);
    }
}
struct treeNode* minNode(struct treeNode* root){
    if(root){
        while(root->lchild!=NULL){
            root=root->lchild;
        }
        return root;
    }
};
struct treeNode* maxNode(struct treeNode* root){
    if(root){
        while(root->rchild!=NULL){
            root=root->rchild;
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
        return root;
    }
};
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
int countNode(struct treeNode* root){
    if(!root)
        return 0;
    else
        return 1+countNode(root->lchild)+countNode(root->rchild);
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
int bFactor(struct treeNode* root){
    return height(root->lchild)-height(root->rchild);
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
int depth(struct treeNode* root){

}
int menu(){
    printf("1 :BSTInsert \n");
    printf("2 :InOrderTraverse\n");
    printf("3 :MiniMum Number\n");
    printf("4 :MaxTerm Node\n");
    printf("5 :deleteNode \n");
    printf("6 :sumOfNode\n");
    printf("7 :countNode\n");
    printf("8 :height\n");
    printf("9 :gFactor\n");
    printf("10 :rRotate\n");
    printf("11 :lRotate\n");
    printf("Choose your Option :");
    int ch;
    scanf("%d",&ch);
    return ch;
}
int main(void){
    struct treeNode* root=NULL;
    int data;
    while(1){
        switch(menu()){
        case 1:
            printf("Enter data :");
            scanf("%d",&data);
            root=insert(root,data);
            break;
        case 2:
            printf("\nInOrder :");
            inOrder(root);
            break;
        case 3:
            printf("MIN Node :%d",minNode(root)->info);
            break;
        case 4:
            printf("Max Node :%d",maxNode(root)->info);
            break;
        case 5:
            printf("DeleteNode :");
            scanf("%d",&data);
            deleteNode(root,data);
            break;
        case 6:
            sum(root);
            printf("Sum :%d",add+=root->info);
            break;
        case 7:
            printf("%d",countNode(root));
            break;
        case 8:
            printf("%d",height(root));
            break;
        case 9:
            printf("gFactor :%d",bFactor(root));
            break;
        case 10:
            root=rRotate(root);
            printf("rRotate :%d",bFactor(root));
            break;
        case 11:
            root=lRotate(root);
            printf("lRotate :%d",bFactor(root));
            break;
        default:
            printf("Enter a Valid Option ");
        }
        getch();
        system("cls");
    }
}
