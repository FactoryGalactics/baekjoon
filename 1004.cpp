#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int t, k;
	int x1, x2, y1, y2;
	int cx[50], cy[50],r[50];

	double a,b;
	int *ans;
	cin >>t;
	ans=new int [t];

	for (int i=0; i<t; i++){
	        cin>>x1>>y1>>x2>>y2;
		cin>>k;
		for (int j=0; j<k; j++){
			cin >>cx[j]>>cy[j]>>r[j];
		}
		for (int j=0; j<k;j++){
			a=sqrt(pow(cx[j]-x1,2)+pow(cy[j]-y1,2));
			b=sqrt(pow(cx[j]-x2,2)+pow(cy[j]-y2,2));

			if(a<r[j] && b>r[j]) 	
				ans[i]++;
			else if (a>r[j] && b<r[j])
				ans[i]++;
		}
	}
	for (int i=0; i<t; i++){
		cout << ans[i]<<endl;
	}
	return 0;

}
