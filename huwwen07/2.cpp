#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	char c;
	Node *lc, *rc;
	Node(char c_):c(c_),lc(NULL),rc(NULL) {}
};

Node* readTree(){
	char c,t;
	cin>>c>>t;
	if (c == '$') return NULL;
	Node* x = new Node(c);
	if (t=='1') return x;
	x->lc = readTree();
	x->rc = readTree();
	return x;
}

void BFS(Node* x){
	queue<Node*> que;
	stack<Node*> stk;
	que.push(x);
	bool first = true;
	while (!que.empty()){
		x = que.front();
		que.pop();
		if (first) first=false; else cout<<' ';
		cout<<x->c;
		for (Node* y = x->lc; y; stk.push(y), y = y->rc) ;
		while (!stk.empty()){
			que.push(stk.top());
			stk.pop();
		}
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	BFS(readTree());
	return 0;
}