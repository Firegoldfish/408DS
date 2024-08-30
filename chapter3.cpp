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
    struct LinkNode *next;
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
bool Push(SqStack &S, int x){
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