#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long LL;

const int maxd = 5;

int globald, D;

inline LL sqr(LL x){
	return x*x;
}

class Point{
public:
	LL x[maxd];
	void read(){
		for (int i=0; i<D; ++i) cin>>x[i];
	}
	void print(){
		for (int i=0; i<D; ++i) cout<<x[i]<<' ';
	}
	bool operator < (const Point &p)const{
		return x[globald] < p.x[globald];
	}
};

inline LL dis2(const Point &p, const Point &q){
	LL sum = 0;
	for (int i=0; i<D; ++i) sum += sqr(p.x[i] - q.x[i]);
	return sum;
}

typedef pair<Point, LL> PR;
typedef pair<LL, int> PR2;

class KD{
private:
	class Node{
	public:
		Point p;
		int id;
		int d;
		Node *lc, *rc;
		Node(Point p_, int id_, int d_, Node *lc_=NULL, Node *rc_=NULL):
			p(p_), id(id_), d(d_), lc(lc_), rc(rc_) {}
	};
	
	Node *root;
	int d;
	vector<Point> points;

	int cmp(int a, int b){
		return points[a].x[d] < points[b].x[d];
	}

	Node *constructFrom(int l, int r, int depth){
		if (l>r) return NULL;
		int locald = globald = depth % D;;
		int mid = (l+r) >> 1;
		nth_element(points.begin()+l, points.begin()+mid, points.begin()+r+1);
		return new Node(points[mid], mid, locald, 
				constructFrom(l, mid-1, depth+1), constructFrom(mid+1, r, depth+1));
	}

	PR findNearest(Node *node, const Point &p){
		if (node->lc == NULL && node->rc == NULL){
			return make_pair(node->p, dis2(node->p, p));
		}

		int small = p.x[node->d] < node->p.x[node->d];
		Node *first, *second;
		PR fres;

		if (small){
			first = node->lc; second = node->rc;
		}else{
			first = node->rc; second = node->lc;
		}

		if (first != NULL){
			fres = findNearest(first, p);
			if (sqr(p.x[node->d] - node->p.x[node->d]) >= fres.second)
				return fres;
		}

		PR rres = make_pair(node->p, dis2(p, node->p));
		if (second != NULL){
			PR tmp = findNearest(second, p);
			if (tmp.second < rres.second)
				rres = tmp;
		}

		if (first != NULL && fres.second < rres.second) return fres;
		return rres;
	}

	priority_queue<PR2> pq;
	void findKNearest(Node *node, const Point &p,int k){
		if (node == NULL) return ;

		Node *first = node->lc, *second = node->rc;
		if (p.x[node->d] >= node->p.x[node->d]) swap(first, second);

		if (first != NULL) findKNearest(first, p, k);

		PR2 cur = make_pair(dis2(p, node->p), node->id);
		if (pq.size() < k) pq.push(cur);
		else if (cur < pq.top()){
			pq.pop();
			pq.push(cur);
		}

		if ((pq.size() == k) && (sqr(p.x[node->d]-node->p.x[node->d])>=pq.top().first))
			return ;
		if (second != NULL) findKNearest(second, p, k);
	}

	void show(Node *node){
		if (node == NULL) return ;
		cout<<"node:"<<node<<' '; node->p.print();
		cout<< " d: "<<(node->d) <<"    "<< (node->lc) <<"  "<< (node->rc) <<endl;
		show(node->lc);
		show(node->rc);
	}

	void destroy(Node *node){
		if (node == NULL) return ;
		destroy(node->lc);
		destroy(node->rc);
		delete node;
	}

public:
	KD():root(NULL){}

	~KD(){
		destroy(root);
	}

	void construct(const vector<Point> &points_){
		if (root){
			destroy(root);
			root = NULL;
		}
		points = points_;
		root = constructFrom(0, points.size()-1, 0);
	}

	
	PR findNearest(const Point &p){
		return findNearest(root, p);
	}

	vector<Point> findKNearest(const Point &p, int k){
		while (!pq.empty()) pq.pop();
		findKNearest(root, p, k);
		int n = pq.size();
		vector<Point> ans(n);
		for (int i=n-1; i>=0; --i){
			ans[i] = points[pq.top().second];
			pq.pop();
		}
		return ans;
	}

	void show(){
		show(root);
	}
};

int get(){
	int n;
	if (!(cin>>n>>D)) return 0;
	vector<Point> points(n);
	for (int i=0; i<n; ++i) points[i].read();	
	
	KD kd;
	kd.construct(points);
	
	int T;
	cin>>T;
	while (T--){
		Point p;
		int k;
		p.read();
		cin>>k;
		vector<Point> ans = kd.findKNearest(p, k);
		cout<<"the closest "<<k<<" points are:"<<endl;
		for (auto p:ans){
			p.print();
			cout<<endl;
		}
	}

	return 1;
}

int main(){
	while (get()) ;
	return 0;
}
