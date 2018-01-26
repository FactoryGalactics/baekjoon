#include <iostream>


using namespace std;

int coin[10001];
int dp[10001];

int main(){
	//input,,,,,,,,,,,,,,,,,,
	int n, total;
	
	cin>>n>>total;
	for (int i=0; i<n;i++) 
	{
		cin>>coin[i];
	}
	dp[0]=1;
	for (int i=0;i<n;i++){
		for (int j=1; j<=total; j++){
			if (coin[i]<=j){
				dp[j]+=dp[j-coin[i]];
			}
		}
	}
	cout<<dp[total]<<endl;
	return 0;
}
   
   
