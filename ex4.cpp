#include <iostream>
using namespace std;
//baekjoon 2606

int n; //computer number
int map [100][100]={0,};
int visited[100]={0,};
void dfs (int v){
	int i;
	visited[v]=1;
	for (i=1; i<=n; i++){
		if (map[v][i]==1 && visited[i]!=1)
			dfs(i);
	}
}

int main(){
	int v1, v2, k;
	int cnt=0;
	cin >> n >> k; // k: 쌍의 개수
	for (int i=0; i< k; i++)
	{
		 cin>>v1>>v2;
		 map[v1][v2]=map[v2][v1]=1;
	}
        dfs(1);
	for (int i=1; i<= n; i++)
		if (visited[i]==1) cnt++;
	cout<<cnt-1<<endl;	//1번컴퓨터 제외
}
