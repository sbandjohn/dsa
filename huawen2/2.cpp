#include <bits/stdc++.h>
using namespace std;

const int maxn=500;

typedef pair<int,int> pr;

vector<pr> a,b;

int cmp(const pr& a, const pr& b){
	return a.first > b.first;
}

void out(const vector<pr>& c){
	int first=1;
	for (auto p:c){
		if (p.second!=0){
			if (!first) putchar(' ');
			first = 0;
			printf("[ %d %d ]",p.second,p.first);
		}
	}
	putchar('\n');
}

void clean(vector<pr>& a){
	sort(a.begin(),a.end(),cmp);
	vector<pr> b;
	int i=0;
	while (i<a.size()){
		int tmp = 0;
		int j=i;
		while (j<a.size() && a[j].first == a[i].first){
			tmp+=a[j].second;
			++j;
		}
		if (tmp!=0) b.push_back(make_pair(a[i].first, tmp));
		i=j;
	}
	a=b;
}

vector<pr> add(const vector<pr>& a, const vector<pr>& b){
	int i=0;
	int j=0;
	vector<pr> c;
	while (i<a.size() || j<b.size()){
		if (i<a.size() && j<b.size() && a[i].first == b[j].first){
			c.push_back(make_pair(a[i].first, a[i].second+b[j].second));
			++i;++j;
		}else{
			if (j==b.size() || i<a.size() && a[i].first>b[j].first){
				c.push_back(a[i++]);
			}else{
				c.push_back(b[j++]);
			}
		}
	}
	clean(c);
	return c;
}

void read(vector<pr>& a){
	a.clear();
	int x,y;
	while (1){
		scanf("%d%d",&x,&y);
		if (y<0) break;
		a.push_back(make_pair(y,x));
	}
}


int get(){
	read(a);
	clean(a);
	//cout<<"a:";out(a);
	read(b);
	//cout<<"b before:";out(b);
	clean(b);
	//cout<<"b  after:";out(b);
	out(add(a,b));
	return 1;
}

int main(){
	int T;
	cin>>T;
	while (T--) get();
	return 0;
}