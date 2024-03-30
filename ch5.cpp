#include<iostream>
using namespace std;

typedef struct BiTNode //链式存储二叉树
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct SqTree //顺序存储二叉树
{
    char data[100];
}SqTree;

int GetTogetherFather(SqTree T,int i, int j){
    if (T[i]!='#'&&T[j]!='#') {
        while (i!=j){
            if(i>j) i=i/2;
            else j=j/2;
        }
        return T[i];
    }
}

void visit(BiTree T){
    cout<<T->data<<endl;
}

void PreOrder(BiTree T){ //前序遍历
    if (T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){ //后序遍历
    if (T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
    
}