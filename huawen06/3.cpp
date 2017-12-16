#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;


string in2PostConvert(string s){
	s = "(" + s +")";
	stack<char> stk;
	string ans;
	map<char, int> pri;
	pri['+']=pri['-'] = 1;
	pri['*']=pri['/'] = 2;

	for (int i=0;s[i];++i){
		if (s[i]=='('){
			stk.push(s[i]);
		}else if (s[i]==')'){
			while (stk.top() != '('){
				ans += stk.top();
				stk.pop();
			}
			stk.pop();
		}else{
			int p = pri[s[i]];
			if (p){
				while (!stk.empty() && stk.top()!='(' && pri[stk.top()] >= p){
					ans += stk.top();
					stk.pop();
				}
				stk.push(s[i]);
			}else{
				ans += s[i];
			}
		}
	}
	return ans;	
}

class Node{
public:
	char x;
	int type;      // 0: variables, 1: op
	Node *lc,*rc;
	Node(char x_, int type_, Node* lc_, Node* rc_):x(x_),type(type_),lc(lc_),rc(rc_){}
};

Node* post2TreeConvert(string s){
	map<char, int> pri;
	pri['+']=pri['-'] = 1;
	pri['*']=pri['/'] = 2;
	stack<Node*> stk;
	for (int i=0;s[i];++i){
		if (pri[s[i]] == 0){
			stk.push(new Node(s[i], 0, NULL, NULL));
		}else{
			Node* a = stk.top(); stk.pop();
			Node* b = stk.top(); stk.pop();
			stk.push(new Node(s[i], 1, b, a));
		}
	}
	if (stk.empty()) return NULL;
	else return stk.top();
}

int evaluate(Node* root, map<char,int> &value){
	if (root->type==0) return value[root->x];
	int a = evaluate(root->lc, value);
	int b = evaluate(root->rc, value);
	int c;
	switch(root->x){
		case '+': c = a+b; break;
		case '-': c = a-b; break;
		case '*': c = a*b; break;
		case '/': c = a/b; break;
	}
	return c;
}

void print(Node *x){
	if (x==NULL) return ;
	print(x->lc);
	cout<< (x->x)<<' ';
	print(x->rc);
}

int getHight(Node *x){
	if (x==NULL) return 0;
	return 1+max(getHight(x->lc), getHight(x->rc));
}

char graph[maxn][maxn];

void map2Graph(Node* x, int H, int h, int col){
	if (x==NULL) return ;
	//cout<<(x->x)<<','<<h<<','<<col<<endl;
	int row = 2*(H-h) + 1;
	graph[row][col] = x->x;
	int pos;
	if (x->lc != NULL){
		pos = col - (1<<(h-2));
		graph[row+1][col-1]='/';
		map2Graph(x->lc, H, h-1, pos);
	}
	if (x->rc != NULL){
		pos = col + (1<<(h-2));
		graph[row+1][col+1]='\\';
		map2Graph(x->rc, H, h-1, pos);
	}
}

void amazingPrint(Node* root){
	memset(graph,0, sizeof(graph));
	int H = getHight(root);
	map2Graph(root, H, H, 1<<(H-1));
	int maxR = 2*H - 1;
	for (int i=1;i<=maxR; ++i){
		int maxC = 0;
		for (int j=1;j<maxn;++j) if (graph[i][j]) maxC = j;
		for (int j=1;j<=maxC;++j){
			cout<<(!graph[i][j] ? ' ':graph[i][j]);
		}
		cout<<endl;
	}
}

int main(){
	freopen("3.in","r",stdin);
	
	string s;
	cin>>s;
	string t = in2PostConvert(s);
	Node* root = post2TreeConvert(t);
	
	int n;
	cin>>n;
	map<char, int> value;
	for (int i=0;i<n;++i){
		char c; int x;
		cin>>c>>x;
		value[c] = x;
	}
	
	cout<<t<<endl;
	
	amazingPrint(root);
	
	cout<<evaluate(root, value)<<endl;
	
	return 0;
}