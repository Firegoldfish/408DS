#include<iostream>
using namespace std;
#define MaxSize 50

//定义顺序栈
typedef struct SqStack
{
    int data[MaxSize];
    int top;
};

//定义链栈
typedef struct Linknode
{
    int data;
    struct Linknode *next;
}LinkStack;


//初始化栈
void InitStack(SqStack &S){
    S.top=-1;
} 

//判断空
bool IfStackEmpty(SqStack S){
    if(S.top==-1){
        return true;
    }
    else return false;
}

//入栈
bool Push(SqStack &S, char x){
    if (S.top==MaxSize-1)
    {
        return false;
    }
    else{
        S.data[++S.top]=x;
        return true;
    }   
}

//出栈
bool Pop(SqStack &S){
    int x;
    if (S.top==-1)
    {
        return false;
    }
    else {
        x=S.data[S.top--];
        return true;
    }
}

//读栈顶
int GetTop(SqStack S){
    int x;
    if (S.top==-1)
    {
        return 999;
    }
    else {
        x=S.data[S.top];
        return x;
    }
}

//T03
bool Judge(char a[]){
    int i=0,j=0,k=0;
    while (a[i]!='EOF')
    {
        switch (a[i])
        {
        case 'I':
            j++;
            break;
        case 'O':
            k++;
            break;
            if (k>j)
            {
                printf("wrong input");
                return false;
            }
        }
        i++;
        if (j!=k)
        {
            printf("wrong input");
            return false;
        }
        else
        printf("ok");
        return true;
    }
}

//-----------------------------------------------------

//队列(顺序)
typedef struct Queue
{
    int data[MaxSize];
    int front,rear;
};

//初始化
void InitQueue(Queue &Q){
    Q.rear=Q.front=0;
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

//入队
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

//出队
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

//队列(链表)
typedef struct LinkQueue
{
    Linknode *front, *rear;
};

//初始化
void InitLinkQueue(LinkQueue &Q){
    Q.front=Q.rear=(Linknode*)malloc(sizeof(Linknode));
    Q.front->next=NULL;
}

//判断空
bool IfLinkQueueEmpty(LinkQueue Q){
    if (Q.front==Q.rear)
    {
        return true;
    }
    else return false;
}

//入队
void InLinkQueue(LinkQueue &Q, int x){
    Linknode *s = (Linknode *)malloc(sizeof(Linknode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}

//出队
int OutLinkQueue(LinkQueue &Q){
    if (Q.rear==Q.front)
    {
        return 999;
    }
    int x;
    Linknode *s = Q.front->next;
    x=s->data;
    Q.front->next=s->next;
    if (Q.rear==s)
    {
        Q.rear=Q.front;
    }
    free(s);
    return x;
}

//括号匹配

bool Bracketcheck(char *str){
    SqStack s;
    char e;
    InitStack(s);
    int i=0;
    while (str[i]!='\0')
    {
        e=str[i];
        switch (str[i])
        {
        case '(':
            Push(s,'(');
            break;
        case '[':
            Push(s,'[');
            break;
        case '{':
            Push(s,'{');
            break;
        case ')':
            Pop(s);
            if (e!='(')
            {
                return false;
            }
            break;
        case ']':
            Pop(s);
            if (e!='[')
            {
                return false;
            }
            break;
        case '}':
            Pop (s);
            if (e!='{')
            {
                return false;
            }
            break;
        }
        i++;
    }
    if (!IfStackEmpty(s))
        {
            return false;
        }
        else return true;
}


//再入队
int EnQueue(Queue &Q,int x){
    if(Q.front==Q.rear){return 0;}
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return 1;
}
//再出队
int DeQueue(Queue &Q, int &x){
    if(Q.front==Q.rear) return 0;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return 1;
}

//逆置队列进入栈

void Inverser(SqStack &S, Queue &Q){
    while (!IfQueueEmpty(Q))
    {
        x=DeQueue(Q);
        Push(S,x);
    }
    while (!IfStackEmpty(S))
    {
        Pop(S,x);
        EnQueue(Q,x);
    }
    
}