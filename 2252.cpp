#include <iostream>
#include <vector>
#include <queue>



using namespace std;

int n;
int m;
vector<int> indegree;
vector <vector<int> > graph;

void BFS(void)
{
	queue <int> q;
	for (int i=1; i <=n; i++)
	{
		if(indegree[1]==0)
			q.push(1);
	}
	
	while (!q.empty())
	{	
		int now = q.front();
		q.pop();
		cout <<now<<" ";
		int length=graph[now].size();
		for (int i=0; i<length; i++)
		{
			int next=graph[now][i];
			indegree[next]--;
			if(indegree[next]==0)
				q.push(next);
		}
	}
}
int main ()
{
	cin >> n >>m;
	indegree.resize(n+1);
	graph.resize(n+1);
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		indegree[v]+=1;
	}
	BFS();
	cout << endl;
	return 0;

}	
