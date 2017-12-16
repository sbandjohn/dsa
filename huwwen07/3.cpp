#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000;

int lnk[maxn],sz[maxn];

int find(int x){
	if (x!=lnk[x]) lnk[x] = find(lnk[x]);
	return lnk[x];
}

int unite(int x,int y){
	int a = find(x), b = find(y);
	if (sz[a]<sz[b]){ lnk[a] = b; sz[b]+=sz[a]; return b;}
	else {lnk[b]=a; sz[a]+=sz[b];return a;}
}

int get(int T){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		lnk[i] = i;
		sz[i] = 1;
		lnk[i+n] = i+n;
		sz[i+n]=1;
	}
	bool sus=false;
	for (int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if (sus) continue;
		int a = find(x), b = find(y);
		if (a==b){
			sus=true;
		}else{
			unite(x,y+n);
			unite(x+n,y);
		}
	}
	if (T>1) printf("\n");
	printf("Scenario #%d:\n%s bugs found!\n",T,sus?"Suspicious":"No suspicious");
	return 1;
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;++i) get(i);
	return 0;
}