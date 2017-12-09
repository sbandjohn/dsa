#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

template <typename T>
class Loser{
private:
	int n, offset, lowExt, m;
	vector<int> B;
	vector<T> A;

	int loc(int i){
		return i<=lowExt ? offset+i : offset-n+i;
	}

	void adjust(int p){
		int tar = loc(p)>>1;
		while (tar && B[tar]!=-1){
			if (A[p] > A[B[tar]]){
				int q = B[tar];
				B[tar] = p;
				p = q;
			}
			tar>>=1;
		}
		B[tar] = p;
	}

public:
	Loser(int n_, const vector<T> &a){
		n = n_;
		A = vector<T> (n+1);
		for (int i=1; i<=n; ++i) A[i] = a[i-1];
		int s = 1;
		while (s < n ) s<<=1;
		offset = s - 1;
		lowExt = 2*n - s;
		m = offset + lowExt;
		B = vector<int> (m+1, -1);

		for (int i=1; i<=n; ++i){
			B[loc(i)] = i;
			adjust(i);
		}
	}

	int winner(){
		return B[0];
	}

	void replace(const T &v){
		int p = winner();
		A[p] = v;
		adjust(p);
	}

	void printAll(){
		for (int i=0; i <= m-n; ++i) printf("%d ", A[B[i]]);	
		printf("\n");
	}

};

int main(){
	int n, m;
	scanf("%d %d",&n, &m);
	vector<int> a(n);
	for (int i=0; i<n; ++i) scanf("%d", &a[i]);
	Loser<int> loser(n, a);
	loser.printAll();
	while (m--){
		int i, v;
		scanf("%d%d", &i, &v);
		loser.replace(v);
		loser.printAll();
	}
	return 0;
}

	
