#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long LL;

const int maxn = 100100;

class Node{
public:
	Node *ch[2];
	LL add;
	int rev;
	LL mi;
};
