#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef long long LL;

const int maxn = 200100;

const LL B = 233;

LL f[maxn], P[maxn], g[maxn];

char a[maxn], b[maxn];
int n, m;

void powInit(){
	P[0] = 1;
	for (int i=1; i<maxn; ++i) P[i] = P[i-1] * B;
}

LL hashStr(int x, int y, const LL f[]){
	if (x)
		return f[y] - f[x-1]*P[y-x+1];
	return f[y];
}

LL hashGet(const char s[], int n, LL f[]){
	f[0] = s[0];
	for (int i=1; i<n; ++i)
		f[i] = f[i-1]*B + s[i];
	return f[n-1];
}

void print(const char s[], int x, int y){
	for (; x<=y; ++x) putchar(s[x]);
}

int random(int n) { return ((rand()<<15)+rand())%n;}

int cmp(const char s[], const LL f[], int x, int y,
		const char t[], const LL g[], int l, int r){
	if (hashStr(x,y, f) != hashStr(l,r, g)) return 0;
	int len = y-x+1;
	if (len < 10){
		for (int i=0; i<len; ++i) if (s[x+i] != t[l+i]) return 0;
		return 1;
	}
	//print(s,x,y); cout<<"   ";
	//print(t,l,r); cout<<endl;
	
	for (int i = 0; i<10; ++i){
		int t = random(len);
		if (hashStr(x, x+t, f) != hashStr(l, l+t, g)) return 0;
	}
	return 1;
}


int matchLen(int st){
	if (a[st] != b[0]) return 0;
	int remain = n-st;
	int R = min(remain, m), L = 0;
	while (L < R){
		int mid = (L+R-1)/2 +1;
		int res = cmp(a, f, st, st+mid-1, b, g, 0, mid-1);
		//cout<<res<<endl;
		if (res) L = mid;
		else R = mid-1;
	}
	return L;
}

int ans[maxn];
int q;

int main(){
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s", a, b);
	powInit();
	hashGet(a, n, f);
	hashGet(b, m, g);

	for (int i=0; i<n; ++i){
		int len = matchLen(i);
		++ans[len];
		//cout<<i<<":"<<len<<endl;
	}
	while (q--){
		int x;
		scanf("%d",&x);
		printf("%d\n", ans[x]);
	}
	return 0;
}
