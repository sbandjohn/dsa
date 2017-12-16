#include <bits/stdc++.h>
using namespace std;

const int maxn=310;

int pre[maxn],nxt[maxn];

int joseph(int n,int m){
	for (int i=1;i<=n;++i){
		nxt[i]=i+1;
		if (nxt[i]>n) nxt[i]=1;
		pre[nxt[i]]=i;
	}
	int cur=1;
	for (int t=1;t<n;++t){
		for (int j=1;j<=m;++j) cur = nxt[cur];
		int tmp = pre[cur];
		pre[cur] = pre[tmp];
		nxt[pre[cur]]=cur;
	}
	return cur;
}

int main(){
	int n,m;
	cin>>n>>m;
	cout<<joseph(n,m)<<endl;
}