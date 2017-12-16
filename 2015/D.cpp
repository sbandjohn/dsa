#include <bits/stdc++.h>
using namespace std;

const int maxn = 4000;
const int inf = (1<<30)-1;

int n,b;

int f[maxn][maxn][2];
int a[maxn];

int dp(){
	for (int i=1;i<=n;++i){
		for (int j=0;j<=i;++j){
			f[i][j][0]=f[i][j][1]=-inf;
			if (i-1>=j) f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]);
			if (j>=1){
				int tmp = -inf;
				if (f[i-1][j-1][0]>-inf) tmp = max(tmp, f[i-1][j-1][0] + 0);
				if (f[i-1][j-1][1]>-inf) tmp = max(tmp, f[i-1][j-1][1] + a[i]);
				f[i][j][1]=tmp;
			}
		}
	}
}

int get(){
	scanf("%d%d",&n,&b);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int j=0;j<=n;++j) f[0][j][0]=f[0][j][1]=-inf;
	f[0][0][0]=0;
	dp();
	int ans1 = max(f[n][b][0], f[n][b][1]);
	f[0][0][0]=-inf;
	f[0][0][1]=0;
	dp();
	int ans2 = f[n][b][1];
	//cout<<ans1<<','<<ans2<<endl;
	printf("%d\n",max(ans1,ans2));
	return 1;
}

int main(){
	freopen("D.in","r",stdin);
	get();
	return 0;
}