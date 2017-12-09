#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<int> minHeap;
int sz;

void siftDown(int x){
	int y = x<<1;
	while (y <= sz){
		if (y < sz && minHeap[y+1] < minHeap[y]) ++y;
		if (minHeap[x] > minHeap[y]){
			swap(minHeap[x], minHeap[y]);
			x = y; y = x<<1;
		}else return ;
	}
	return ;
}

vector<int> initRun(const vector<int> &initSeq, const vector<int> &initHeap){
	vector<int> ans;	
	
	minHeap = initHeap;
	sz = minHeap.size()-1;

	for (int ele:initSeq){
		if (sz == 0) return ans;
		ans.push_back(minHeap[1]);
		if (ele < minHeap[1]){
			minHeap[1] = minHeap[sz];
			minHeap[sz] = ele;
			--sz;
		}else{
			minHeap[1] = ele;
		}
		siftDown(1);
	}
	return ans;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> initSeq(n);
	vector<int> initHeap(m+1);
	for (int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		initSeq[i] = x;
	}
	for (int i=1;i<=m;++i){
		int x;
		scanf("%d",&x);
		initHeap[i] = x;
	}
	vector<int> ans = initRun(initSeq, initHeap);
	for (int i=0;i<ans.size()-1; ++i){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[ans.size()-1]);
	return 0;
}

