#include <iostream>
using namespace std;

int main(){
	int n=10;
	int s=0;
	for (int k=1;k<n-1;++k)
		for (int j=n;j>=k;--j)
			s=s+1;
	cout<<s<<endl;
}

