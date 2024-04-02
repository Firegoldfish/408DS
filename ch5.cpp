#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

typedef struct LinkQueue
{
    QueuePtr front, rear;
}LinkQueue;

typedef struct QNode
{
    BiTree data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct TreeNode{ //普通树
    int data;
    struct TreeNode *firstchild, *nextsibling;
}   TreeNode, *Tree;

typedef struct BiTNode //链式存储二叉树
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct SqTree //顺序存储二叉树
{
    char data[100];
}SqTree;

typedef struct CSNode //孩子兄弟表示法
{
    int data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;


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

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    if (!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
}

void EnQueue(LinkQueue &Q,BiTree T){
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if (!p) exit(OVERFLOW);
    p->data=T;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
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

void LevelOrder(BiTree T){ //层次遍历
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q,p);
        visit(p);
        if (p->lchild!=NULL)
        {
            EnQueue(Q,p->lchild);
        }
        if (p->rchild!=NULL)
        {
            EnQueue(Q,p->rchild);
        }
    }
}