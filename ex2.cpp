#include <stdio.h>
#include <iostream>
//baekjoon 7576
using namespace std;
int m,n, h;
int map[1005][1005];
int chk;
int cnt[1005][1005];
int q[1000050][2], f, r;
int x,y, dab;
int dx[4] = {-1, 1, 0, 0, };
int dy[4] = { 0, 0, -1, 1, };
int main(){
	int i,j,k,l;
	cin >> m >> n;
	for (j=0; j<=n+1; j++){
		 for(l=0; l<=m+1; l++){
			map[j][l]=-1; cnt[j][l]=0;
		 }
 	}
	f = r =0;
	for(j=1; j<=n+1; j++) {
		for(l=1; l<=m; l++){
			cin >> map[j][l];
			if(map[j][l] ==1){
				q[r][0]=j;
				q[r][1]=l;
				r++;
			}
		}
	}
	while (f<r){
		x = q[f][0];
		y = q[f][1]; 	
		f++;
		for(k=0; k<4; k++){
			if (map[x+dx[k]][y+dy[k]] ==0) {
	                	map[x + dx[k]][y + dy[k]] = 1;
                		cnt[x + dx[k]][y + dy[k]] = cnt[x][y] + 1;//매번 그넘이 언제 익었나를 저장
                		q[r][0] = x + dx[k];//이번에 익은넘을 집어넣음
                		q[r][1] = y + dy[k];
                		r++;
			}
		}
	}
	dab = 0;
	chk = 0;//안익은애들을 저장

   	 for (j = 1; j <= n; j++) {
        	for (l = 1; l <= m; l++) {
            		if (dab < cnt[j][l]) //가장 늦게 익은애들을 저장
                		dab = cnt[j][l];
            		if (map[j][l] == 0)
                		chk = 1;
        	}	
    	} if (chk == 1)
        	cout << -1;
    	else
        	cout << dab;
 		return 0;
}

