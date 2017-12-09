#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxn = 100100;
int a[maxn];
int n,T;

int get(){
	scanf("%d%d",&n,&T);
	for (int i=0;i<n;++i) scanf("%d",a+i);
	sort(a, a+n);
	int r=0;
	int ans = 0;
	T = abs(T);
	for (int l=0;l<n;++l){
		while (r==l || (r<n && a[r]-a[l]<T)) ++r;
		if (l==0 || a[l]!=a[l-1]){
			ans += (r<n && a[r]-a[l] == T);
		}
	}
	cout<<ans<<endl;
	return 1;
}

int main(){
	get();
	return 0;
}
