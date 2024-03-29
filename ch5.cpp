#include<iostream>
using namespace std;

typedef struct BiTNode //链式存储二叉树
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int GetTogetherFather(SqTree T,int i, int j){
    if (T[i]!='#'&&T[j]!='#') {
        while (i!=j){
            if(i>j) i=i/2;
            else j=j/2;
        }
        return T[i];
    }
}