#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> a(-1,10);
	for (auto x:a) cout<<x<<' ';
	cout<<endl;
	return 0;
}

