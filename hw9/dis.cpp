#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef long long LL;

class Point{
public:
	LL x,y,z;
};

LL sqr(LL x){return x*x;}

LL dis2(Point p, Point q){
	return sqr(p.x-q.x)+sqr(p.y-q.y)+sqr(p.z-q.z);
}

const int maxn = 100;

Point points[maxn];

class Ele{
	public:
	LL dis2;
	int x,y;
};

int cmp(const Ele& p, const Ele& q){
	if (p.dis2>q.dis2) return 1;
	if (p.dis2<q.dis2) return 0;
	if (p.x<q.x) return 1;
	if (p.x>q.x) return 0;
	if (p.y<q.y) return 1;
	return 0;
}

int get(){
	int n;
	cin>>n;
	for (int i=0;i<n;++i) cin>>points[i].x>>points[i].y>>points[i].z;
	
	vector<Ele> s;
	for (int i=0;i<n;++i)
		for (int j=i+1;j<n;++j){
			Ele ele;
			ele.dis2 = dis2(points[i], points[j]);
			ele.x = i; ele.y=j;
			s.push_back(ele);
		}
	sort(s.begin(), s.end(), cmp);
	for (Ele ele:s){
		printf("(%lld,%lld,%lld)-(%lld,%lld,%lld)=%.2f\n",
				points[ele.x].x, points[ele.x].y, points[ele.x].z,
				points[ele.y].x, points[ele.y].y, points[ele.y].z,
				sqrt(ele.dis2));
	}

	return 1;
}

int main(){
	get();
	return 0;
}

