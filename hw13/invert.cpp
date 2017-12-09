#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Invert{
private:
	typedef vector<int> List;
	map<string, List> table;

public:
	void addDocument(int id, const vector<string> &d){
		for (auto &c : d){
			List &lst = table[c];
			if (lst.size() == 0 || lst[lst.size()-1] != id)
				lst.push_back(id);
		}
	}

	vector<int> getDocuments(const string &c){
		return table[c];
	}
};

int main(){
	int n,m;
	string c;
	Invert invert;
	cin>>n;
	for (int i=1; i<=n; ++i){
		vector<string> doc;
		cin>>m;
		while (m--){
			cin>>c;
			doc.push_back(c);
		}
		invert.addDocument(i, doc);
	}
	cin>>m;
	while (m--){
		cin>>c;
		vector<int> tmp = invert.getDocuments(c);
		if (tmp.size())
			for (auto &x : tmp) cout<<x<<' ';
		else
			cout<<"NOT FOUND";
		cout<<endl;
	}
	
	return 0;
}

