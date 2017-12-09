#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <utility>
using namespace std;

const int maxn = 100;
const int inf = 1<<29;

int dis[maxn][maxn], pre[maxn][maxn];
string name[maxn];
map<string,int> id;

class Road{
public:
	int x,y,z;
}road[maxn][maxn];

int n,m;

int floyd(){
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			dis[i][j] = road[i][j].z;
			pre[i][j] = i;
		}
		dis[i][i] = 0;
		pre[i][i] = -1;
	}
	for (int k=0;k<n;++k)
		for (int i=0;i<n;++i)
			for (int j=0;j<n;++j){
				if (dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					pre[i][j] = pre[k][j];
				}
			}
	return 1;
}

int get(){
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>name[i];
		id[name[i]] = i;
	}
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j) road[i][j].z = inf;
	cin>>m;
	for (int i=0;i<m;++i){
		string s1, s2;
		int tmp;
		cin>>s1>>s2>>tmp;
		int x = id[s1], y = id[s2];
		if (tmp<road[x][y].z){
			road[x][y].z = road[y][x].z = tmp;
		}
	}
	floyd();
	cin>>m;
	for (int i=0;i<m;++i){
		string s1, s2;
		cin>>s1>>s2;
		int x = id[s1], y = id[s2];
		vector<int> seq;
		for (int t = y; t!=x; t=pre[x][t]) seq.push_back(t);
		seq.push_back(x);
		for (int t=seq.size()-1; t>=0; --t){
			cout<<name[seq[t]];
			if (t!=0) printf("->(%d)->",road[seq[t]][seq[t-1]].z);
		}
		cout<<endl;
	}
	return 1;
}

int main(){
	get();
	return 0;
}
