#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000100;

int a[2*maxn];
int n;
int front,tail;
int len;

int add(int x){
	a[--front]=x;
	return x;
}

int pop(){
	int x = a[front++];
	return x;
}


int copy(){
	if (tail == 2*maxn) return 0;
	int len = min(tail-front, 2*maxn-tail);
	for (int i=0; i<len; ++i)
		a[tail+i] = a[front+i];
	tail+=len;
	return 1;
}

int check(){
	cout<<"queue:"<<front<<"   "<<tail<<endl<<"    ";
	for (int i=front;i<tail;++i) cout<<a[i]<<' ';
	cout<<endl;
}

int get(){
	scanf("%d",&n);
	front = tail = maxn;
	while (n--){
		int x;
		scanf("%d",&x);
		if (x>0) add(x);
		if (x==0) copy();
		if (x==-1){
			if (front<tail)
				printf("%d\n",pop());
		}
		//check();
	}
	return 1;
}

int main(){
	freopen("F.in","r",stdin);
	
	get();
	
	return 0;
}