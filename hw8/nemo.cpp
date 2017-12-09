#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
using namespace std;

const int maxx = 220;
const int maxn = maxx*maxx;
const int maxm = maxn*4;
const int inf = 1<<29;

int cost[maxx][maxx][4];
int n,m;

void init(){
	memset(cost,0,sizeof(cost));
}

void wallVertical(int x,int y){
	cost[x][y][2]=inf;
	cost[x-1][y][0]=inf;
}
void wallHorizontal(int x,int y){
	cost[x][y][3]=cost[x][y-1][1]=inf;
}
void doorVertical(int x, int y){
	cost[x][y][2]=cost[x-1][y][0]=1;
}
void doorHorizontal(int x, int y){
	cost[x][y][3]=cost[x][y-1][1]=1;
}

int dis[maxx][maxx],in[maxx][maxx];
typedef pair<int,int> PR;

int spfa(int sx, int sy){
	if (sx<0 || sx>=maxx || sy<0 || sy>=maxx) return 0;
	for (int i=0;i<maxx;++i)
		for (int j=0;j<maxx;++j){
			dis[i][j] = inf;
			in[i][j]=0;
		}
	dis[0][0] = 0;
	queue<PR> que;
	que.push(make_pair(0,0));

	const int mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

	while (!que.empty()){
		PR pr = que.front();
		que.pop();
		int x = pr.first, y = pr.second;
		in[x][y]=0;
		for (int d=0;d<4;++d){
			int xx = x+mov[d][0], yy=y+mov[d][1];
			if (xx>=0 && xx<maxx && yy>=0 && yy<maxx){
				if (cost[x][y][d]<inf){
					int s = dis[x][y] + cost[x][y][d];
					if (s < dis[xx][yy]){
						dis[xx][yy]=s;
						if (!in[xx][yy]){
							que.push(make_pair(xx,yy));
							in[xx][yy]=1;
						}
					}
				}
			}
		}
	}
	
	/*for (int i=0;i<5;++i)
		for (int j=0;j<5;++j)
			cout<<i<<','<<j<<":"<<dis[i][j]<<endl;
	*/		
	if (dis[sx][sy]==inf) return -1;
	return dis[sx][sy];
}

int get(){
	scanf("%d%d",&m,&n);
	if (m==-1) return 0;
	init();

	for (int i=0;i<m;++i){
		int x,y,d,t;
		scanf("%d%d%d%d",&x,&y,&d,&t);
		if (d==1)
			for (int delta=0;delta<t;++delta)
				wallVertical(x, y+delta);
		if (d==0)
			for (int delta=0;delta<t;++delta)
				wallHorizontal(x+delta, y);
	}
	for (int i=0;i<n;++i){
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		if (d==1)
			doorVertical(x,y);
		else
			doorHorizontal(x,y);
	}

	double fx,fy;
	scanf("%lf%lf",&fx,&fy);

	int ans = spfa((int)fx, (int)fy);
	cout<<ans<<endl;
	return 1;
}

int main(){
	while (get()) ;
	return 0;
}

