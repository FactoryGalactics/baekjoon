#include <iostream>

using namespace std;

int visited[1001];
int visited2[1001];
int map[1001][1001];
int queue[1001];

int n;
int rear, front;

void dfs(int v);
void bfs(int v);

int main (){
	int k, v;
	cin >>n>>k>>v;
	
	int x,y;	
	for(int i=0; i<k; i++)
	{
		cin>>x>>y;
		map[x][y]=map[y][x]=1;
	}
	dfs(v);
	cout <<endl;
	bfs(v);
	cout <<endl;
	return 0;
}


void dfs(int v){
	visited[v]=1;
	cout <<v <<" ";
	for (int i=1; i<=n; i++)
	{	
		if(map[v][i]==1 && visited[i]==0)
			dfs(i);
	}		
}


void bfs(int v){
	
	visited2[v]=1;
	queue[rear++]=v;
	while(front <rear)
	{
		v = queue[front++];
		cout<< v <<" ";

		for (int i=1; i<=n; i++)
		{	

			if(map[v][i]==1 && visited2[i]==0)
			{
				visited2[i]=1;
				queue[rear++]=i;

			}
		}
	}
}


