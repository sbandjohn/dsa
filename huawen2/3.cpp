#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

int a[maxn],b[maxn];

int isZero(int *a){
	for (int i=maxn-1;i>=0;--i) if (a[i]!=0) return 0;
	return 1;
}

int divide(int *a, int *b){
	int remain = 0;
	for (int i = maxn-1; i>=0; --i){
		remain = remain*10 + a[i];
		b[i] = remain/2;
		remain %= 2;
	}
	return remain;
}

int read(int *a){
	string str;
	cin>>str;
	int len = str.size();
	for (int i=0;i<len;++i){
		a[i] = str[len-1-i]-'0';
	}
	return len;
}

int out(int *b){
	int i=maxn-1;
	while (b[i]==0 && i>0) --i;
	for (int j=i;j>=0;--j) printf("%d",b[j]);
	printf("\n");
	return i;
}

int main(){
	int len = read(a);
	vector<int> ans;
	do{
		ans.push_back(divide(a,b));
		memcpy(a,b,sizeof(a));
	}while(!isZero(a));
	for (int i=ans.size()-1;i>=0;--i) cout<<ans[i];
	cout<<endl;
	
	return 0;
}