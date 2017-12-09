#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 110;

typedef vector<int> List;

List lst[maxn];

List symmetric(const List &a, const List &b){
	int n = a.size(), m = b.size();
	int p = 0, q = 0;
	List c;
	while (p<n || q<m){
		while (p<n && (q==m || a[p]<b[q])) c.push_back(a[p++]);
		while (q<m && (p==n || b[q]<a[p])) c.push_back(b[q++]);
		while (p<n && q<m && a[p]==b[q]){ ++p; ++q; }
	}
	return c;
}

List exclude(const List &a, const List &b){
	int n = a.size(), m = b.size();
	int p = 0, q = 0;
	List c;
	while (p<n || q<m){
		while (p<n && (q==m || a[p]<b[q])) c.push_back(a[p++]);
		while (q<m && (p==n || b[q]<a[p])) q++;
		while (p<n && q<m && a[p] == b[q]){ ++p; ++q;}
	}
	return c;
}

List intersect(const List &A, const List &B){
	return symmetric(A, exclude(A,B));
}

List unite(const List &A, const List &B){
	return symmetric(B, exclude(A,B));
}

int main(){
	ios::sync_with_stdio(false);
	int n, m, x;

	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>m;
		while (m--){
			cin>>x;
			lst[i].push_back(x);
		}
		sort(lst[i].begin(), lst[i].end());
		auto it = unique(lst[i].begin(), lst[i].end()); 
		lst[i].erase(it, lst[i].end());
	}

	cin>>m;
	while (m--){
		int has1 = 0;
		List A, B;
		for (int i=0; i<n; ++i){
			cin>>x;
			if (1 == x){
				if (!has1) A = lst[i];
				else A = intersect(A, lst[i]);
				has1 = 1;
			}
			if (-1 == x) B = unite(B, lst[i]);
		}
		A = exclude(A, B);
		if (A.size())
			for (auto &x : A) cout<<x<<' ';
		else
			cout<<"NOT FOUND";
		cout<<endl;
	}
	
	return 0;
}

