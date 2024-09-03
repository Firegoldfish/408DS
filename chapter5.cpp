#include<iostream>
using namespace std;
#define MaxSize 50

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

typedef struct Queue
{
    int data[MaxSize];
    int front,rear;
};

//初始化
void InitQueue(Queue &Q){
    Q.rear=Q.front=0;
}

bool InQueue(Queue &Q,int x){
    if ((Q.rear+1)%MaxSize==Q.front)
    {
        return false;
    }
    else{
        Q.data[Q.rear]=x;
        Q.rear=(Q.rear+1)%MaxSize;
        return true;
    }
}

//判断空
bool IfQueueEmpty(Queue Q){
    if (Q.rear=Q.front)
    {
        return true;
    }
    else {
        return false;
    }
}

int OutQueue(Queue &Q){
    int x;
    if (Q.rear==Q.front)
    {
        return 999;
    }
    else {
        x=Q.data[Q.front];
        Q.front=(Q.front+1)%MaxSize;
        return true;
    }
}

void PreOrder(BiTree T){
    if (T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if (T!=NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if (T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void LevelOrder(BiTree T){
    InitQueue(Q);
    BiTree p;
    InQueue(Q,T);
    while (!IfQueueEmpty(Q))
    {
        OutQueue(Q, p);
        visit(p);
        if(p->lchild!=NULL) InQueue(Q,p->lchild);
        if(p->rchild!=NULL) InQueue(Q,p->rchild);
    }
}

//线索化二叉树
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag,rtag;
}ThreadNode, *ThreadTree;

//递归化
void InThread(ThreadTree &p, ThreadTree &pre){
    if (p!=NULL)
    {
        InThread(p->lchild, pre);
        if (p->lchild!=NULL)    
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if (pre!=NULL && pre->rchild==NULL)
        {
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild, pre);
    }
}

//ltag==0 lchild

//主过程
void CreateInThread(ThreadTree T){
    ThreadTree pre = NULL;
    if (T!=NULL)
    {
        InThread(T,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}

ThreadNode *Firstnode(ThreadNode *p){
    while (p->rtag==0)
    {
        p=p->lchild;
    }
    return p;
}

ThreadNode *Nextnode (ThreadNode *p){
    if (p->rtag==0)
    {
        return Firstnode(p->rchild);
    }
    else{
        return p->rchild;
    }
}

