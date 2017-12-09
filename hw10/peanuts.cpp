#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 51;

class Point{
public:
	int x,y,z;
	int operator < (const Point &p) const{
		return z < p.z;
	}
}points[maxn*maxn];

int get(){
	int n,m,lim;
	scanf("%d%d%d",&n,&m,&lim);
	int cnt = 0;
	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j){
			scanf("%d",&points[cnt].z);
			points[cnt].x = i+1;
			points[cnt].y = j+1;
			++cnt;
		}
	sort(points, points+cnt);
	int t = 0;
	int got = 0;
	for (int i=cnt-1; i>=0; --i){
		int t1;
		if (i == cnt-1){
			t1 = 2*points[i].x + 1;
		}else{ 
			int dis = abs(points[i].x - points[i+1].x) + abs(points[i].y - points[i+1].y);
			t1 = t - points[i+1].x + dis + 1 + points[i].x;
		}
		if (t1 > lim) break;
		t = t1;
		got += points[i].z;
	}
	cout<<got<<endl;
	return 1;
}

int main(){
	int T;
	cin>>T;
	while (T--) get();
	return 0;
}

