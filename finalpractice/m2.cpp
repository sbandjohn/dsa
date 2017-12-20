#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 52;
const int inf = 1<<29;

int f[maxn][maxn][maxn][maxn], v[maxn][maxn];
int n, m;

inline int in(int x1, int y1){
	return x1>=1 && x1<=n && y1>=1 && y1<=m;
}

void dealwith(int x1, int y1, int x2, int y2, int t){
	if (in(x1, y1) && in(x2, y2)){
		int s;
		if (x1 == x2 && y1 == y2) s = t;	
		else s = t + v[x1][y1] + v[x2][y2];
		f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], s);
	}
}

int dp(){
	memset(f, 0, sizeof(f));
	f[1][1][1][1] = 0;
	for (int k=2; k<=n+m-1; ++k){
		for (int x1 = max(1, k-m); x1<=min(k-1,n); ++x1){
			int y1 = k-x1;
			for (int x2 = max(1, k-m); x2<=min(k-1, n); ++x2){
				int y2 = k-x2;
				if (k==2 || k!=2 && x1!=x2){
					int t = f[x1][y1][x2][y2];
					dealwith(x1+1, y1, x2+1, y2, t);
					dealwith(x1+1, y1, x2, y2+1, t);
					dealwith(x1, y1+1, x2+1, y2, t);
					dealwith(x1, y1+1, x2, y2+1, t);
				}
			}
		}
	}
	return f[n][m][n][m];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j){
			scanf("%d", &v[i][j]);
		}
	cout<< dp() <<endl;
	return 0;
}