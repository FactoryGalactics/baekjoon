#include <iostream>

using namespace std;
int wine[10000];
int dp[10000];
int max(int a, int b);
int main(){
	int n;
	cin >>n;
	for (int i=1; i<=n; i++)
		cin >> wine[i]; 
	int result=0;
	for(int i=1; i<=3 && i<=n; i++)
	{
			if(i==1)
				dp[i]=wine[i];
			else
				dp[i]=wine[i]+wine[i-1];
	}
	for (int i=3; i<=n; i++){
		result=max(dp[i-2]+wine[i], dp[i-1]);
		result=max(result,dp[i-3]+wine[i-1]+wine[i]);
		dp[i]=result;
	}
	cout<<dp[n]<<endl;
	return 0;
}

int max (int a, int b){
	return a >b ? a: b;
}









































































































































































































