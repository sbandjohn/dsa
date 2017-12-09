#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#define BLACK 0
#define RED 1
using namespace std;

class RBTree{
private:
	class Node{
	public:
		int v;
		int color;
		Node *ch[2];
		Node *p;
		Node(int v_, int color_, Node *lc_, Node *rc_, Node *p_):
			v(v_), color(color_){
				ch[0] = lc_;
				ch[1] = rc_;
				p = p_;
			}
	};

	Node *nil, *root;

	void destroy(Node *x){
		if (x == nil) return ;
		destroy(x->ch[0]);
		destroy(x->ch[1]);
		delete x;
	}

	int which(Node *x){
		assert(x->p != nil);
		return x == x->p->ch[1];
	}

	void link(Node *x, Node *y, int d){
		x->ch[d] = y;
		if (y != nil) y->p = x;
	}

	void rotate(Node *x, int d){
		Node *p = x->p;
		Node *y = x->ch[d^1];
		if (p != nil) link(p, y, which(x));
		else{
			root = y;
			y->p = nil;
		}
		link(x, y->ch[d], d^1);
		link(y, x, d);
	}

	void adjust(Node *x){
		Node *p = x->p;
		if (p == nil) { x->color = BLACK; return ;}
		if (p->color == BLACK) return ;
		if (p->p == nil){
			p->color = BLACK;
			return ;
		}
		Node *q = p->p;
		assert(q->color == BLACK);
		int d = which(p);
		Node *r = q->ch[d^1];
		if (r->color == RED){
			p->color = BLACK;
			r->color = BLACK;
			q->color = RED;
			adjust(q);
			return ;
		}
		int d2 = which(x);
		if (d == d2){
			rotate(q, d^1);
			p->color = BLACK;
			q->color = RED;
		}else{
			rotate(p, which(x)^1);
			rotate(q, d^1);
			x->color = BLACK;
			q->color = RED;
		}
	}

	void insert(Node *p, int d, int v){
		Node *x = p->ch[d];
		if (x == nil){
			x = new Node(v, RED, nil, nil, p);
			link(p, x, d);
			adjust(x);
			return ;
		}
		insert(x, v>x->v, v);
	}

	int check(Node *p){
		if (p == nil) return 0;
		int lh = check(p->ch[0]);
		int rh = check(p->ch[1]);
		assert(lh == rh);
		return lh + (p->color == BLACK);
	}

	void show(Node *p){
		if (p == nil) return ;
		show(p->ch[0]);
		printf("%d %d  %lx lc:%lx  rc:%lx  p:%lx\n",
				p->v, p->color, (long)p, 
				(long)p->ch[0], (long)p->ch[1], (long)p->p);
		show(p->ch[1]);
	}

public:

	RBTree(){
		nil = new Node(0, BLACK, NULL, NULL, NULL);
		nil->p = nil->ch[0] = nil->ch[1] = nil;
		root = nil;
	}
	~RBTree(){
		destroy(root);
		delete nil;
	}

	void insert(int v){
		if (root == nil){
			root = new Node(v, BLACK, nil, nil, nil);
			return ;
		}
		insert(root, v > root->v, v);
	}

	void check(){
		assert(nil->ch[0] == nil);
		assert(nil->ch[1] == nil);
		assert(nil->p == nil);
		check(root);
	}

	void show(){
		show(root);
	}

};

int main(){
	RBTree rbTree;
	int n;
	cin>>n;
	while (n--){
		int a;
		cin>>a;
		rbTree.insert(a);
		rbTree.check();
	};
	rbTree.show();
	return 0;
}
