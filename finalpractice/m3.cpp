#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 100100;
int a[maxn];

int main(){
	int n;
	scanf("%d", &n);
	a[0] = 0;
	long long ans = 0;
	for (int i=1; i<=n; ++i){
		scanf("%d", a+i);
		if (a[i] > a[i-1]) ans += (long long)a[i] - a[i-1];
	}
	cout<<ans<<endl;
}