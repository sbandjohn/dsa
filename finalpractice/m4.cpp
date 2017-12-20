#include <iostream>
#include <string>

using namespace std;

int print(char s[], int l, int r){
	if (l == r){
		if (s[l] == '1'){
			putchar('I');
			return 1;
		}
		if (s[l] == '0'){
			putchar('B');
			return 2;
		}
	}
	int mid = (l+r)>>1;
	int lc = print(s, l, mid);
	int rc = print(s, mid+1, r);
	if (lc == 3 || rc == 3 || lc != rc){
		putchar('F');
		return 3;
	}
	if (lc == 1){
		putchar('I');
		return 1;
	}
	putchar('B');
	return 2;
}

int main(){
	int n;
	char s[1025];
	cin>>n;
	cin>>s;
	print(s, 0, (1<<n)-1);
	cout<<endl;
}