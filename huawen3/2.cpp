#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 16;

LL f[maxn];

LL dp(int n){
	f[0] = 1;
	for (int i=1;i<=n;++i){
		f[i] = 0;
		for (int j=0;j<=i-1;++j){
			f[i] += f[j]*f[i-1-j];
		}
	}
	return f[n];
}

int main(){
	int n;
	cin>>n;
	cout<<dp(n)<<endl;
	return 0;
}