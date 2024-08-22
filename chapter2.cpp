#include<iostream>
#include<cstdio>
#define maxsize 50
using namespace std;
typedef struct SqList
{
    int data[maxsize];
    int length;
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