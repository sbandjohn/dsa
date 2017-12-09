#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int maxn = 100;
const int inf = 0x7fffffff;

int dis[maxn][maxn];
int in[maxn], cost[maxn];
int n;

int prim(){
	int ans = 0;
	for (int i=0;i<n;++i){
		in[i] = 0;
		cost[i] = inf;
	}
	cost[0]=0;
	for (int t=0;t<n;++t){
		int choice, best = inf;
		for (int i=0;i<n;++i)
			if (!in[i] && cost[i]<best){
				best = cost[i];
				choice = i;
			}
		in[choice] = 1;
		ans += best;
		
		//cout<<choice<<','<<best<<endl;

		for (int i=0;i<n;++i)
			if (!in[i]) cost[i] = min(cost[i], dis[i][choice]);
	}
	return ans;
}

int get(){
	cin>>n;
	for (int i=0;i<n;++i) for (int j=0;j<n;++j) dis[i][j]=inf;
	for (int x=0;x<n-1;++x){
		char c;
		int m;
		cin>>c>>m;
		for (int i=0;i<m;++i){
			int tmp;
			cin>>c>>tmp;
			int id = c-'A';
			dis[x][id] = dis[id][x] = min(dis[x][id], tmp);
		}
	}
	cout<<prim()<<endl;
	return 0;
}

int main(){
	get();
	return 0;
}

