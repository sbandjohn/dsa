#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxn = 10100;
int a[maxn];
int n;

int kth(int* a, int* ed, int k){
	int sz = ed-a;
	if (sz==1) return a[0];
	int l=0, r=sz-1;
	int v = a[l+rand()%sz];
	while (l<=r){
		while (l<=r && a[l]<v) ++l;
		while (l<=r && a[r]>v) --r;
		if (l<=r){
			swap(a[l], a[r]);
			++l; --r;
		}
	}
	sz = r+1;
	if (k<=sz) return kth(a,a+sz,k);
	else return kth(a+sz, ed, k-sz);
}

int get(){
	scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%d",a+i);
	cout<<kth(a,a+n,(n+1)>>1)<<endl;
	return 1;
}

int main(){
	get();
	return 0;
}

