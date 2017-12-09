#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	int n, m;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i=0; i<n; ++i) scanf("%d", &a[i]);
	scanf("%d", &m);
	vector<int> b(m);
	for (int i=0; i<m; ++i) scanf("%d", &b[i]);
	int p = 0, q = 0;
	while (p<n || q<m){
		while (p<n && (q==m || a[p]<b[q])) printf("%d ", a[p++]);
		while (q<m && (p==n || b[q]<a[p])) printf("%d ", b[q++]);
		while (p<n && q<m && a[p]==b[q]) {
			++p; ++q;
		}
	}
	return 0;
}

