#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;

const int maxn = 1000100;

class Node{
public:
	Node *ch[2];
	Node *p;
	int v;
	int id;
}*root, pool[maxn];

Node *ptr, nil;

void init(){
	root = 0;
	ptr = pool;
}

void setRoot(Node *x){
	root = x;
	if (x) x->p = 0;
}

int which(Node *x){
	assert(x->p != 0);
	return x == x->p->ch[1];
}

void setChild(Node *x, int d, Node *y){
	x->ch[d] = y;
	if (y) y->p = x;
}

void rotate(Node *x, int d){
	Node *y = x->ch[d^1];
	Node *p = x->p;
	if (p)
		setChild(p, which(x), y);
	else
		setRoot(y);
	
	setChild(x, d^1, y->ch[d]);
	setChild(y, d, x);
}

Node *splay(Node *x){
	while (x->p){
		Node *p = x->p;
		int d1 = which(x);
		if (p->p){
			Node *q = p->p;
			int d2 = which(p);
			if (d1 == d2){
				rotate(q, d2^1);
				rotate(p, d1^1);
			}else{
				rotate(p, d1^1);
				rotate(q, d2^1);
			}
		}else{
			rotate(p, d1^1);
		}
	}
	return x;
}

Node *insert(Node *(&x),int v, int id, Node *p = 0){
	if (x == 0){
		x = ptr++;
		x->v = v;
		x->id = id;
		x->p = p;
		return x;
	}
	int d = v > x->v;
	return insert(x->ch[d], v, id, x);
}

void insert(int v, int id){
	Node *x = insert(root, v, id, 0);
	splay(x);
}

Node *findDir(Node *x, int d){
	for (; x->ch[d]; x = x->ch[d]) ;
	return x;
}

Node *del(Node *x){
	splay(x);
	if (x->ch[0] == 0){
		setRoot(x->ch[1]);
		return x;
	}
	if (x->ch[1] == 0){
		setRoot(x->ch[0]);
		return x;
	}
	Node *y = x->ch[1];
	Node *z = findDir(y, 0);
	y->p = 0;
	splay(z);
	assert(root == z);
	setChild(z, 0, x->ch[0]);
	return x;
}

void op23(int op){
	int d = op == 2? 1 : 0;
	if (root == 0){
		printf("0\n");
		return ;
	}
	Node *x = findDir(root, d);
	printf("%d\n", x->id);
	del(x);
}

int get(){
	int op;
	scanf("%d", &op);
	if (op == 0) return 0;
	
}

int main(){
	init();
	int op;
	int v,id;
	scanf("%d", &op);
	while (op!=0){
		if (op == 1){
			scanf("%d%d",&id, &v);
			insert(v, id);
		}else
			op23(op);
		scanf("%d",&op);
	}
	return 0;
}