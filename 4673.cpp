#include <iostream>

using namespace std;

int self[10001];

int d (int n);

int main(){
	for (int i=1; i<=10000;i++)
	{
		self[d(i)]=1;
		if(!self[i])cout<<i<<endl;
	}
	return 0;
}

int d (int i){
	
	int res=i;
	if(i >=10000){	res+=i/10000; i%=10000;}
	if(i >=1000){	res+=i/1000; i%=1000;}
	if(i >=100){	res+=i/100; i%=100;}
	if(i >=10){	res+=i/10; i%=10;}
	
	return res+=i;
}


