/*
#include <iostream>
using namespace std;
int check (int ax,int ay, int r1, int bx, int by,int r2);
int main(){
	int t;
	int ax, ay, r1;
	int bx, by, r2;
	cin>>t;
	for(int i=0; i<t; i++)
	{	
			cin>>ax>>ay>>r1>>bx>>by>>r2;
			cout<<check(ax,ay,r1,bx,by,r2)<<endl;
	}
	return 0;
}

int check (int ax,int ay, int r1, int bx, int by,int r2)
{
	if (ax==bx && ay==by && r1==r2)
		return -1;
	if (ax==bx && ay==by && r1!=r2)
		return 0;
	if ((ax!=bx && ay==by) || (ax==bx && ay!=by))
		return 1;
	if (ax!=bx && ay!=by)
		return 2;


}
1. 터렛이 재는 거리는 그냥 각 원의 반지름. (r1,r2)

2. 터렛의 위치는 원의 중심점(x1,y1) , (x2,y2)


두원위 위치관계로 나올수 있는 답은 총 4개 .

1.만나지않는다 = 0

2.내접, 외접 == 1

3.두점에서 만난다 == 2

4.같다 = -1

-------------------------


정답. (rl 은 큰 반지름, rs 는 작은반지름, d는 두 원의 중심점간 거리)


2점 : rl - rs < d < rl+ rs

1점 : rl - rs = d (내접) . rl+ rs =d (외접)

0점 : rl - rs >d(내부에있다) . rl + rs < d (외부에 있다)

무한대 : rl = r2 , x1==x2, y1==y2.


 **주의 : 원점간 거리를 재는 변수는 실수로 선언해야한다.. 이거때문에 계속틀려서...하아..

---------------------
*/
#include<iostream>

#include<math.h>

using namespace std;


int main()

{


 int T;

 int x1, y1, r1, x2, y2, r2;

 int * ans;

 double d;

 int rl, rs;

 cin >> T;


 ans = new int[T];


 for (int i = 0; i < T; i++) {

  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));


  if (r1 > r2) {

   rl = r1;

   rs = r2;

  }

  else {

   rl = r2;

   rs = r1;

  }

  if (d == 0) {

   if (r1 == r2) {

    ans[i] = -1;

   }

   else {

    ans[i] = 0;

   }

  }

  else if (r1 + r2 > d && rl - rs < d) {

   ans[i] = 2;

   

  }

  else if (r1 + r2 == d || rl - rs == d) {

   ans[i] = 1;

  }

  else if (r1 + r2 < d || rl - rs > d) {

   ans[i] = 0;

  }

 }

 for (int i = 0; i < T; i++) {

  cout << ans[i] << endl;

 }


 return 0;

}
