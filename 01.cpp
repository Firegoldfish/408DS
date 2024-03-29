#include<cstdio>
#include<iostream>
using namespace std;
#define MAXSIZE 50
typedef struct
{
    int data[MAXSIZE];
    int length;
}SqList;
//初始化顺序表
void InitList(SqList &L){
    L.length=0;
}
//插入元素
bool Insert(SqList &L, int i, int value){
    if (i<1||i>L.length+1||L.length>=MAXSIZE)
    {
        return false;
    }
    for (int j = L.length; j >=i; j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=value;
    L.length++;
    return true;
}
//删除最小值
bool Delmin(SqList &L, int &value){
    if (L.length==0)
    {
        return false;
    }
    value=L.data[0];
    int pos=0;
    for (int i = 1; i < L.length; i++)
    {
        if(L.data[i]<value){
            value=L.data[i];
            pos=i;
        }
        L.data[pos]=L.data[L.length-1];
        L.length--;
        return true;
    }
}

int main(){
    SqList L;
    InitList(L);
    Insert(L, 1, 3);
    Insert(L, 2, 5);
    Insert(L, 3, 7);
    Insert(L, 4, 2);
    Insert(L, 5, 8);
    int value;
    Delmin(L, value);
    cout<<value<<endl;
    return 0;
}
