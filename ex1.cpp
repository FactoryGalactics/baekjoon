//익은것을 1, 안 익은 것을 0
// 익은부분을 중심으로 해서 dfs시작 (for 구문으로 찾아야 될듯) 한 단계 한 포문내에서 다 해결해야지 하루치로 계산가능할듯 
//dfs할 때, 좌우상하 다 확인해주어야 함. 좌우상하에 대해서 0이면, 1로 바꾸어주고 cnt +1 -> 없으면, 종료                
// 모든 곳이 다익엇다 map[n][m]==1이다 하면 종료하고, for구문 몇번돌앗는지 카운트 세서 출력하면 그것이 최종 일자.                                                                                                                                                                                                

#include <stdio.h>
#include <iostream>

//baekjoon 7576
using namespace std;
int m, n, h; int map[1005][1005], cnt[1005][1005], chk;
int q[1000050][2], f, r;
int x, y, dab;
int dx[4] = { -1, 1, 0, 0, };
int dy[4] = { 0, 0, -1, 1, };
int main() {
    int i, j, l, k;
    cin >> m >> n;
    for (j = 0; j <= n + 1; j++) {
        for (l = 0; l <= m + 1; l++) {
            map[j][l] = -1; cnt[j][l] = 0;
        }
    }
    f = r = 0;
    for (j = 1; j <= n; j++) {
        for (l = 1; l <= m; l++) {
            cin >> map[j][l];
            if (map[j][l] == 1) {//매번 익은 애들들 큐에 저장
                q[r][0] = j;
                q[r][1] = l;
                r++;
            }
        }
    }
    while (f<r) {
        x = q[f][0];
        y = q[f][1];
        f++;//하나 빼고
        for (k = 0; k<4; k++) {
            if (map[x + dx[k]][y + dy[k]] == 0) {//근처에 안익은애들을 익게함
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


