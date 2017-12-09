#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 100100;
typedef long long LL;

LL inversion(int a[], int l, int r){
	static int b[maxn];
	if (l>=r) return 0;
	int mid = (l+r)>>1;
	LL lcnt = inversion(a, l, mid);
	LL rcnt = inversion(a, mid+1, r);
	LL cnt = 0;
	int p = l, q = mid+1;
	for (int i=l; i<=r; ++i){
		if (p<=mid && q>r) { b[i] = a[p++]; continue;}
		if (p>mid && q<=r) { b[i] = a[q++]; continue;}
		if (a[p] < a[q]){
			cnt += r-q+1;
			b[i] = a[p++];
		}else{
			b[i] = a[q++];
		}
	}
	memcpy(a+l, b+l, sizeof(int)*(r-l+1));
	return cnt + lcnt + rcnt;
}

int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	cout<< inversion(a, 0, n-1) <<endl;
	return 0;
}

