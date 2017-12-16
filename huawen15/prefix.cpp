#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#define MS(a,b) memset(a,b,sizeof(a))

const int maxn = 1010;
const int maxm = 30;
const int maxnode = maxn*maxm;

class Trie{
public:
	class Node{
	public:
		int cnt;
		int word;
		int ch[maxm];
		Node(){
			cnt = 0;
			word = 0;
			MS(ch, -1);
		}
	}tree[maxnode];

	int tot;

	void init(){
		tot = 1;
		tree[0] = Node();
	}

	void insert(char *s){
		int x = 0;
		tree[x].cnt++;
		for (int i=0; s[i]; ++i){
			int c = s[i] - 'a';
			if (tree[x].ch[c] == -1){
				tree[x].ch[c] = tot;
				tree[tot++] = Node();
			}
			x = tree[x].ch[c];
			tree[x].cnt ++;
		}
		tree[x].word = 1;
	}
	
	void print(char *s){
		int x = 0;
		for (int i=0; s[i]; ++i){
			int c = s[i] - 'a';
			putchar(s[i]);
			x = tree[x].ch[c];
			if (s[i+1] == 0 || tree[x].cnt == 1) break;
		}
	}
};

char s[maxn][maxm];

int main(){
	Trie *trie = new Trie();
	trie->init();
	int n = 0;
	while (scanf("%s", s[n]) == 1){
		trie->insert(s[n]);
		++n;
	}
	for (int i=0; i<n; ++i){
		printf("%s ", s[i]);
		trie->print(s[i]);
		putchar('\n');
	}
	delete trie;
	return 0;
}
