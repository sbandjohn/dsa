#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int inversion(string s){
	int ans=0;
	for (int i=1;i<s.size();++i)
		for (int j=0;j<i;++j) ans += s[j]>s[i];
	return ans;
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<string> str(n);
	vector<pair<int,int> > a;
	for (int i=0;i<n;++i){
		cin>>str[i];
		a.push_back(make_pair(inversion(str[i]), i));
	}
	sort(a.begin(), a.end());
	for (auto pr: a) cout<<str[pr.second]<<endl;
	return 0;
}

