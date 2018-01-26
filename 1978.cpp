#include <iostream>
using namespace std;

int gcd(int a);

int main(){
	int n, k;
	cin >>n;
	int cnt=0;
	for (int i=1; i<=n; i++)
	{
		cin >>k;
		if(gcd(k)==-1 && k>1) //1은 소수가 아니다.
			cnt++;
	}
	cout <<cnt<<endl;
	return 0;
}

int gcd(int a){
	int cnt=0;
	for (int i=1;i<=a;i++)
		if(a%i==0)
			cnt++;
	if (cnt<=2)
		return -1;
	else
		return 0;
}
