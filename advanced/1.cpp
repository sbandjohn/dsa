#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

typedef long long LL;
const int maxn = 110;

class Matrix{
public:
	LL a[maxn][maxn];
	int n,m;
	Matrix(){memset(a, 0, sizeof(a));}
}I;

int nm;

Matrix multiply(const Matrix &a, const Matrix &b){
	Matrix c;
	c.n = a.n;
	c.m = b.m;
	for (int k=1; k<=a.m; ++k){
		for (int i=1; i<=a.n; ++i){
			LL r = a.a[i][k];
			if (r){
				for (int j=1; j<=b.m; ++j){
					c.a[i][j] += r*b.a[k][j];
				}
			}
		}
	}
	return c;
}

Matrix Pow(const Matrix &A, int n){
	Matrix ans(I), B = A;
	while (n){
		if (n&1) ans = multiply(ans, B);
		B = multiply(B, B);
		n >>= 1;
	}
	return ans;
}

Matrix Pg(int i){
	Matrix a(I);
	a.a[i][nm] = 1;
	return a;
}

Matrix Pe(int i){
	Matrix a(I);
	a.a[i][i] = 0;
	return a;
}

Matrix Ps(int i, int j){
	Matrix a(I);
	a.a[i][i] = 0; a.a[j][j] = 0;
	a.a[i][j] = 1; a.a[j][i] = 1;
	return a;
}

int get(){
	int n, m, k;
	scanf("%d %d %d\n", &n, &m, &k);
	if (n==0) return 0;
	
	nm = n+1;
	I.n = I.m = nm;
	for (int i=1;i<=nm; ++i) I.a[i][i] = 1;
	
	Matrix a;
	a.n = nm; a.m = 1;
	a.a[n+1][1] = 1;
	
	Matrix P(I);
	for (int i=1; i<=k; ++i){
		char c;
		int x,y;
		scanf("%c ", &c, &x);
		if (c == 'g'){
			scanf("%d\n", &x);
			P = multiply(Pg(x), P);
		}
		if (c == 'e'){
			scanf("%d\n", &x);
			P = multiply(Pe(x), P);
		}
		if (c == 's'){
			scanf("%d %d\n", &x, &y);
			P = multiply(Ps(x,y), P);
		}
	}
	
	Matrix b = multiply(Pow(P,m), a);
	for (int i=1; i<=n; ++i) cout<<b.a[i][1]<<' ';
	cout<<endl;
	return 1;
}

int main(){
	while (get()) ;
	return 0;
}