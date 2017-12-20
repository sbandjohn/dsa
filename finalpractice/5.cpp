#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 400100;

char s[maxn];
int  p[maxn];

void kmp_init(char s[], int n, int p[]){
	p[0] = -1;
	int j = -1;
	for (int i=1; i<n; ++i){
		while (j!=-1 && s[j+1]!=s[i]) j = p[j];
		if (s[j+1] == s[i]) ++j;
		p[i] = j;
	}
}

int get(){
	if (scanf("%s", s) != 1) return 0;
	int n = strlen(s);
	kmp_init(s, n, p);
	int x = n-1;
	vector<int> ans;
	ans.push_back(n);
	while (p[x] != -1){
		ans.push_back(p[x]+1);
		x = p[x];
	}
	for (int i = ans.size()-1; i>=0; --i) cout<<ans[i]<<' ';
	cout<<endl;
	return 1;
}
int main(){
	while (get()) ;
	return 0;
}