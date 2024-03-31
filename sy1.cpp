#include<iostream> 
#include<cstdio> 
#include<cstring>
int map[1002][1002];
bool visited[1002][1002]; 
int depth[1002][1002]; 
int queue[150100][2]; 
int top;
int adj[5][2] ={{0,0},{0,-1},{0,1},{-1,0},{1,0}};
#define enqueue(i,j) queue[top][0] =i;queue[top][1] =j;top++; 
#define MAX 0x7F7F7F7F
inline void dequeue(int*i, int*j)
{ 
    top--;
    *i =queue[top][0];
    *j =queue[top][1];
} 

int main()
{ //freopen("meteor.12.in","r",stdin); //freopen("out.out","w", stdout);
    int M;
    int i;
    int j;
    int tempX; 
    int tempY; 
    int tempTime; 
    int X;
    int Y;
    int min;
    scanf("%d",&M);
    memset(map, 0x7F, sizeof(map)); 
    for(i =0;i <M; i++){
        scanf("%d%d%d",&tempX, &tempY, &tempTime); 
        for(j =0; j <5; j++){
            X =tempX +adj[j][0];
            Y =tempY +adj[j][1]; 
            if((X>=0&&Y >=0)&& (map[X][Y] >tempTime)){
                map[X][Y] =tempTime;
            }
        }
    }
    memset(visited, 0, sizeof(visited)); 
    depth[0][0] =0;
    top=0;
    enqueue(0, 0);
    visited[0][0] =true; 
    min=MAX;
    for(i=0;i<top;i++)
    { //是队列不是堆栈 
        tempX =queue[i][0]; 
        tempY =queue[i][1]; 
        for(j =1; j <5; j++){
            X =tempX +adj[j][0];
            Y =tempY +adj[j][1]; 
            tempTime=depth[tempX][tempY] +1; 
            if((X>=0&&Y >=0)&&(map[X][Y] >tempTime)&& (visited[X][Y] ==false)){
                enqueue(X, Y); 
                visited[X][Y] =true; 
                depth[X][Y] =tempTime; 
                if(map[X][Y]==MAX){
                    if(min>depth[X][Y]){
                        min=depth[X][Y]; 
                    }
                    goto find;
                }
            }
        }
    }
    find:
    {
        if(min!=MAX){
            printf("%d\n",min);
        }
        else{
            printf("-1\n");
        }
    }
    return 1;
    }
