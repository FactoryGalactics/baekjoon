#include <iostream>
using namespace std;

void push ();
void pop ();
int size();
int empty(); // 1, 0
int top();
int stack [100001]={-1,};
	int index=0;

int main(){
	int n, t;
	cin >>n;
	char s[5];
	for(int i=0; i<n; i++){
		cin >>s;
		if(s[0]=='p' && s[1]=='u'){
			cin >>t;
			stack[index++]=t;
		}
		else if (s[0]=='p' &&s[1]=='o')
		{
			if(index<=0)
				cout <<"-1"<<endl;
			else
			{
				index--;
				cout<<stack[index]<<endl;
				stack[index]=-1;
			}
		}
		else if (s[0]=='s')
		{
			cout <<index<<endl;
		}
		else if (s[0]=='e')
		{
			if (stack[0]==-1)
				cout<<"1"<<endl;
			else
				cout<<"0"<<endl;
		}
		else if (s[0]=='t')
		{
			if(index<=0)
				cout<<"-1"<<endl;
			else
				cout<<stack[index-1]<<endl;
			
		}
	}
	
	return 0;
}
