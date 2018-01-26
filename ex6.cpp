#include <stdio.h>

int n;
int rear; front;
int queue[10];
int map[10][10];
int visit[10];
void bfs(int v)
{
	int i;
	visit[v]=1;
	queue[rear++]=v;
	while(front<rear)
	{
		v=queue[front++];//pop
		for(i=1; i<=n; i++)
		{
			if(map[v][i]==1 && !visit[1])
			{
				visit[i]=1;
				queue[rear++]=i;
			}
		}
	}
}

