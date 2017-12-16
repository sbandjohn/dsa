#include <bits/stdc++.h>

using namespace std;

int huffman(vector<int> a){
	priority_queue<int, vector<int>, greater<int> > pq;
	for (auto x:a) pq.push(x);
	int ans=0;
	while (pq.size()!=1){
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += a+b;
		pq.push(a+b);
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i=0;i<n;++i) cin>>a[i];
	cout<<huffman(a)<<endl;
	return 0;
}