#include <iostream>

using namespace std;

int y[9], k[9];

int main(){

	int t; //test case
	int i,j;
	int yonsei[1000]={0,}, korea[1000]={0,};

	cin>>t;
	for(j=0; j<t; j++)
	{
		for(i=0; i<9; i++)
		{
			cin>>y[i]>>k[i];
			yonsei[j]+=y[i];
			korea[j]+=k[i];	
		}
	}
	for(i=0;i<t;i++)
	{
		if (yonsei[i]>korea[i])
			cout<<"Yonsei"<<endl;
		else if (yonsei[i] <korea[i])
			cout<<"Korea"<<endl;
		else 
			cout<<"Draw"<<endl;
	}
	return 0;
}
