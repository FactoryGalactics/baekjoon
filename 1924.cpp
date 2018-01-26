#include <iostream>
using namespace std;

int main(){
	
	int x, y;
	int sum=0;
	cin >>x >>y;
	if(x<1 ||x>12 || y>31 || y<0)
		return 0;
	// 1,3,5,7,9,11 ->31 , 2->28, 4,6,8,10,12->30
	int month[13]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
	char day[7][10]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	for (int i=0; i<x; i++)
	{
		sum+=month[i];
	}
	sum+=y;
	for(int i=0; i<7;i++)
	{
		if(sum%7==i+1)
			cout<<day[i]<<endl;
	}
	if(sum%7==0)
		cout<<day[6]<<endl;
	return 0;
}
 
