#include <stdio.h>
 
typedef struct tagQueue{
    int x;
    int y;
    int level;
}Queue;
 
Queue queue[10001];
 
int N,M,i,j;
int Maze[101][101];
int front=0,rear=0;
int visit[101][101]={0};
 
int BFS(int x,int y){
    int popX,popY,popLevel,i,X,Y;
    int dx[4]={0,0,1,-1};//동서남북
    int dy[4]={1,-1,0,0};
    queue[rear].x=x;
    queue[rear].y=y;
    queue[rear].level=1;
    visit[x][y]=1;
    rear++;
    if(N==1 && M==1){ // 1*1 행렬이 입력된 경우
        return 1;
    }
 
    while(front<rear){
        popX=queue[front].x;
        popY=queue[front].y;
        popLevel=queue[front].level;
        front++;
 
        if(popX==N-1 && popY==M-1){
            return popLevel;
        }
 
        for(i=0;i<4;i++){
            X=popX+dx[i];
            Y=popY+dy[i];
 
            if(X>=0 && X<N && Y>=0 && Y<M){
 
                if(Maze[X][Y]==1 && visit[X][Y]==0){
                    if((X==N-1) && (Y==M-1)){
                        return popLevel+1;
                    }
                    queue[rear].x=X;
                    queue[rear].y=Y;
                    queue[rear].level=popLevel+1;
                    visit[X][Y]=1;
                    rear++;
                }
            }
        }
    }
}
 
int main(){
    int result;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%1d",&Maze[i][j]);
        }
    }
    result=BFS(0,0);
    printf("%d\n",result);
    return 0;
}


