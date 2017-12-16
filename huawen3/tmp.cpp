#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;


int priority(char c) {
	switch (c) {
	case '(': return 1; break;
	case '+': case '-': return 3; break;
	case '*': case '/': case '%':return 5; break;
	case '^': return 7; break;
	case ')': return 100; break;
	case '0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':case'.':
		return 0;
		break;
	default: return -100; break;
	}
}


struct Texp {                        //???????????
	static const int maxn = 10010;
	static const int maxm = 30;

	char s[maxn];
	char ori[maxn];
	char des[maxn][maxm];
	int len;

	void read() {
		gets(ori);
	}

	void write() {
		for (int i = 0; i < len; i++) {
			for (int j = 0; des[i][j]; j++) putchar(des[i][j]);
			putchar(' ');
		}
		printf("\n");
	}

	void write(char *s) {
		printf("%s", s);
	}

	char stk[maxn], stkTop;

	int transform() {
		stkTop = 0;
		len = 0;
		int i = 0, j = 0;
		s[j++] = '(';
		for (; ori[i]; i++) {
			if ((ori[i] == '+' || ori[i] == '-') && s[j - 1] == '(')
				s[j++] = '0';
			s[j++] = ori[i];
		}
		s[j++] = ')';
		s[j] = '\0';
		i = 0;
		while (s[i]) {
			if (priority(s[i]) == -100) {
				i++;
				continue;
			}
			if (s[i] == '(') {
				stk[stkTop++] = s[i];
				i++;
				continue;
			}
			else
				if (s[i] == ')') {
					while (stk[stkTop - 1] != '(') {
						des[len][0] = stk[stkTop - 1];
						des[len][1] = '\0';
						len++;
						stkTop--;
					}
					stkTop--;
					i++;
					continue;
				}
				else
					if (priority(s[i]) != 0) {
						while (stkTop && priority(stk[stkTop - 1]) >= priority(s[i])) {
							des[len][0] = stk[stkTop - 1];
							des[len][1] = '\0';
							len++;
							stkTop--;
						}
						stk[stkTop++] = s[i];
						i++;
						continue;
					}
					else {
						char num[maxm];
						int numlen = 0;
						while (s[i] && priority(s[i]) <= 0) {
							if (priority(s[i]) == 0) num[numlen++] = s[i];
							i++;
						}
						for (int i = 0; i < numlen; i++) des[len][i] = num[i];
						des[len][numlen] = '\0';
						len++;
						continue;
					}
		}
		return len;
	}

	int stkInt[maxm];

	int evaluateFromDes_int() {
		int top = 0;
		for (int i = 0; i < len; i++) {
			switch (des[i][0]) {
			case '+': {
				int a = stkInt[top - 2];
				int b = stkInt[top - 1];
				stkInt[top - 2] = a + b;
				top--;
			}break;
			case '-': {
				int a = stkInt[top - 2];
				int b = stkInt[top - 1];
				stkInt[top - 2] = a - b;
				top--;
			}break;
			case '*': {
				int a = stkInt[top - 2];
				int b = stkInt[top - 1];
				stkInt[top - 2] = a * b;
				top--;
			}break;
			case '/': {
				int a = stkInt[top - 2];
				int b = stkInt[top - 1];
				stkInt[top - 2] = a / b;
				top--;
			}break;
			case '%': {
				int a = stkInt[top - 2];
				int b = stkInt[top - 1];
				stkInt[top - 2] = a%b;
				top--;
			}break;
			default: {
				int a = atoi(des[i]);
				stkInt[top++] = a;
			}break;
			}
		}
		return top == 0 ? 0 : stkInt[--top];
	}


	int evaluate(const string &s) {

		//cout << "dealing with : " << s << endl;

		int len = s.length();
		if (len == 0) return 0;

		int loc = -1, pri = 2147483647;
		int i = len - 1;
		while (i >= 0) {
			if (s[i] == ')') {
				int cnt = 1;
				int j = i - 1;
				while (1) {
					if (s[j] == ')') cnt++;
					if (s[j] == '(') cnt--;
					if (cnt == 0) break;
					j--;
				}
				i = j - 1;
				continue;
			}
			int p = priority(s[i]);
			if (p > 0) {
				if (p < pri) {
					pri = p;
					loc = i;
				}
			}
			i--;
		}

		if (loc == -1) {        // no symbol    is a number or inside bracket
			if (s[0] == '(') return evaluate(s.substr(1, len - 2));
			int a;
			stringstream iss(s);
			iss >> a;
			return a;
		}
		// has a symbol
		int a = evaluate(s.substr(0, loc));
		int b = evaluate(s.substr(loc + 1, len - loc - 1));

		switch (s[loc]) {
		case'+':return a + b; break;
		case'-':return a - b; break;
		case'*':return a * b; break;
		case'/':return a / b; break;
		case'%':return a % b; break;
		case'^':return (int)pow((double)a, (double)b); break;
		}

	}

}a;


template <typename T>
T evaluate(const string &s, T tellType) {

	//cout << "dealing with : " << s << endl;

	int len = s.length();
	if (len == 0) return (T)0;

	int loc = -1, pri = 2147483647;
	int i = len - 1;
	while (i >= 0) {
		if (s[i] == ')') {
			int cnt = 1;
			int j = i - 1;
			while (1) {
				if (s[j] == ')') cnt++;
				if (s[j] == '(') cnt--;
				if (cnt == 0) break;
				j--;
			}
			i = j - 1;
			continue;
		}
		int p = priority(s[i]);
		if (p > 0) {
			if (p < pri) {
				pri = p;
				loc = i;
			}
		}
		i--;
	}

	if (loc == -1) {        // no symbol    is a number or inside bracket
		if (s[0] == '(') return evaluate(s.substr(1, len - 2), tellType);
		T a;
		stringstream iss(s);
		iss >> a;
		return a;
	}
	// has a symbol
	T a = evaluate(s.substr(0, loc), tellType);
	T b = evaluate(s.substr(loc + 1, len - loc - 1), tellType);

	switch (s[loc]) {
	case'+':return a + b; break;
	case'-':return a - b; break;
	case'*':return a * b; break;
	case'/':return a / b; break;
	case'%':return (T)((int)a % (int)b); break;
	case'^':return (T)pow((double)a, (double)b); break;
	}

}

string another;

int main() {
    
  //  freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);

	int T;
	cin>>T;
	while (T--){
		cin>>another;
		printf("%d\n", evaluate(another, (int)(1)) );
	}
		
	//	system("pause");

	return 0;
}