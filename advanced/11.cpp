#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class P{
public:
	int a[7];
	
	void print() const{
		for (int i=1; i<=6; ++i) printf("%d ", a[i]);
	}
	
	int cmp (const P &p) const{
		for (int i = 1; i<=6; ++i){
			if (a[i] < p.a[i]) return -1;
			if (a[i] > p.a[i]) return 1;
		}
		return 0;
	}
	bool operator < (const P &p) const{
		return cmp(p) < 0;
	}
	bool operator == (const P &p) const{
		return cmp(p) == 0;
	}
	bool operator > (const P &p) const{
		return cmp(p) > 0;
	}
	
}I, sigma, tao;

P operator * (const P &a, const P &b){
	P c;
	for (int i=1; i<=6; ++i) c.a[i] = a.a[b.a[i]];
	return c;
}

vector<P> enumerate(){
	for (int i=1; i<=6; ++i) I.a[i] = i;
	for (int i=1; i<=6; ++i) sigma.a[i] = i%6 + 1;
	tao = I;
	tao.a[2] = 6; tao.a[6] = 2; tao.a[3] = 5; tao.a[5] = 3;
	set<P> G;
	P a = I;
	for (int k=1; k<=6; ++k){
		a = a*sigma;
		G.insert(a);
		G.insert(a*tao);
	}
	
	vector<P> ans;
	for (auto p:G) ans.push_back(p);
	return ans;
}

const int maxm = 500111;

int v[7] = {0, 233, 197, 127, 397, 23, 11};

int hashFun(const P &p){
	long long ans = 0;
	for (int i=1; i<=6; ++i)
		ans = ans * v[i] + p.a[i];
	return ans%maxm;
}

class Set{
public:
	set<P> bucket[maxm];
	
	set<P> &locateBucket(const P &p){
		return bucket[hashFun(p)];
	}
	int find(const P &p) {
		set<P> &s = locateBucket(p);
		auto it = s.find(p);
		return it != s.end();
	}
	void insert(const P &p){
		//cout<<"ins: "; p.print(); cout<<endl;
		locateBucket(p).insert(p);
	}
}all;

int main(){
	auto G = enumerate();
	int n;
	scanf("%d", &n);
	P f,h;
	while (n--){
		for (int i=1; i<=6; ++i) scanf("%d", &f.a[i]);
		for (auto &g : G){
			h = f * g;
			if (all.find(h)){
				cout<<"Twin snowflakes found."<<endl;
				return 0;
			}
		}
		all.insert(f);
	}
	cout<<"No two snowflakes are alike."<<endl;
	return 0;
}