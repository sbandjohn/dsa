#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 30;

class Matrix{
public:
	int n, m;
	int a[maxn][maxn];

	Matrix(){
		memset(a,0,sizeof(a));
	}

	void swapRow(int i, int j){
		for (int k=1; k<=m; ++k) swap(a[i][k], a[j][k]);
	}

};

int calc(Matrix A){
	int n = A.n, m = A.m;
	int i = 1, last = 0, pivot = 0;
	
	while (pivot < m){
		++pivot;
		int j;
		for (j=i; j<=n; ++j)
			if (A.a[j][pivot] != 0) break;
		if (j>n) continue;
		A.swapRow(i, j);
		last = pivot;
		for (j=i+1; j<=n; ++j){
			int ratio = A.a[j][pivot] * A.a[i][pivot];
			for (int k=pivot; k<=m; ++k) A.a[j][k] ^= A.a[i][k]*ratio;
		}
		++i;
		if (i>n) break;
	}
	int rk = i-1;
	if (last == m){
		cout<<"Oh,it's impossible~!!"<<endl;
		return 0;
	}else{
		int ans = 1<<(A.m-1-rk);
		cout<<ans<<endl;
		return ans;
	}
}

int get(){
	int s[maxn], t[maxn], y[maxn];
	int n;
	cin>>n;
	for (int i=1;i<=n;++i) cin>>s[i];
	for (int i=1;i<=n;++i) cin>>t[i];
	Matrix A;
	A.n = n;
	A.m = n+1;
	for (int i=1;i<=n;++i) A.a[i][n+1] = s[i]^t[i];
	while (1){
		int x,y;
		cin>>x>>y;
		A.a[y][x] = 1;
		if (x==0) break;
	}
	for (int i=1;i<=n;++i) A.a[i][i] = 1;
	calc(A);
	return 1;
}

	
int main(){
	int T;
	cin>>T;
	while (T--) get();
	return 0;
}

