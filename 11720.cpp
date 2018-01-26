#include <iostream>

using namespace std;

int main(){

	int n;
	cin >>n;
	int sum=0;
	char input[101]={0,};
	cin>>input;
	
	for (int i=0; i<n; i++)
	{
		sum += (input[i]-'0'); //char형에 -0을 해주면, 숫자로 바뀌어짐
	}
	
	
	cout<<sum<<endl;
	return 0;
}
