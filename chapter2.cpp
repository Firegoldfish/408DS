#include<iostream>
#include<cstdio>
#define maxsize 50
using namespace std;
typedef struct SqList
{
    int data[maxsize];
    int length;
    int max = maxsize;
};

//初始化新线性表
void Initlist(SqList &L){
    L.length=0;
}

//插入数据
bool InsertElem(SqList &L, int &e, int i){
    if(i<1||i>L.length+1)   return false;
    if(L.length>maxsize)    return false;
    for (int j = L.length; j >=i ; j++)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

//删除数据
bool DeleteElem(SqList &L, int &e, int i){
    if(i<1||i>L.length) return false;
    e=L.data[i-1];
    for (int j = i; j < L.length; j--)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

//查找数据
int FindElem(SqList L, int e){
    for (int i = 0; i < L.length; i++)
    {
        if (e==L.data[i])
        {
            return i+1;
        }
    }
    return 0;
}

//以下为链表

//定义
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *Linklist;

//初始化(头)
bool InitLinkList(Linklist &L){
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    return true;
}

//初始化(无头)
bool InitLinkNoHead(Linklist &L){
    L=NULL;
    return true;
}

//求表长
int GetLength(Linklist L){
    int length=0;
    LNode *p=L;
    while (p->next!=NULL)
    {
        p=p->next;
        length++;
    }
    return length;
}

//查找第i个
LNode FindX(Linklist L,int i){
    LNode *p=L;
    int j=0;
    while (p!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}

//插入节点
bool InsertLNode(Linklist &L,int e,int i){
    LNode *p=L;
    int j=0;
    while (p!=NULL && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL) return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//删除节点
bool DeleteLinkNode(Linklist &L, int i, int e){
    LNode *p=L;
    int j=0;
    while (p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL || p->next==NULL){
        return false;
    }
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

//头插法建立链表
Linklist HeadInsert(Linklist &L){
    LNode *s;
    int x;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    cin>>x;
    while (x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode))
        s->next=x;
        s->next=L->next;
        L->next=s;
        cin>>x;
    }
    return L;
}

//尾插法建立链表
Linklist TailInsert(Linklist &L){
    int x;
    L=(LNode*)malloc(sizeof(LNode));
    LNode *s, *r=L;
    cin>>x;
    while (x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        cin>>x;
    }
    r->next=NULL;
    return L;
}








//以下为课后习题
//2.2.3.01
int DeleteMin(SqList &L){
    if(L.length==0) return 0;
    int min=L.data[0];
    int pos=0;
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i]<min){
            min=L.data[i];
            pos=i;
        }
    }
    L.data[pos]=L.data[L.length-1];
    L.length--;
    return min;
}

//2.2.3.02
bool InvertElem(SqList &L){
    if (L.length==0)
    {
        return false;
    }
    int tmp;
    for (int i = 0; i < (L.length)/2; i++)
    {
        tmp=L.data[i];
        L.data[i]=L.data[L.length-i-1];
        L.data[L.length-i-1]=tmp;
    }
    return true;
}

//2.2.3.03
bool DeleteSomeElem(SqList &L,int e){
    if (L.length==0)
    {
        return false;
    }
    int count=0;
    for (int i = 0; i < L.length; i++)
    {
        if(e==L.data[i]){
            count++;
        }
        else {
            L.data[i-count]=L.data[i];
        }
    }
    L.length=L.length-count;
}

//2.2.3.04
bool DeleteRange(SqList &L, int s, int t){
    if (L.length==0||s>t||s==t)
    {
        return false;
    }
    int count=0;
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i]>=s&&L.data[i]<=t){
            count++;
        }
        else {
            L.data[i-count]=L.data[count];
        }
    }
    L.length=L.length-count;
    return true;
}

//2.2.3.05
bool DeleteSameElem(SqList &L){
    if (L.length==0)
    {
        return false;
    }
    int i=0,j=1;
    for (i = 0,j=1; i < L.length; j++)
    {
        if (L.data[i]!=L.data[j])
        {
            L.data[++i]=L.data[j];
        }
    }
    L.length=i+1;
    return true;
}

//2.2.3.06
bool MergeList(SqList A, SqList B, SqList C){
    if (A.length+B.length>maxsize)
    {
        return false;
    }
    int i, j, k;
    while (i<A.length&&j<B.length)
    {
        if(A.data[i]<=B.data[j]){
            C.data[k++]=A.data[i++];
        }
        else {
            C.data[k++]=B.data[j++];
        }
    }
    while (i<A.length)
    {
        C.data[k++]=A.data[i++];
    }
    while (j<B.length)
    {
        C.data[k++]=B.data[j++];
    }
    C.length=k;
    return true;
}