#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>

/*
PUSH:裝一個空集合進去stack
DUP:複製stack 最頂端的set再push進去stack
UNION:拿stack最頂端兩個set做聯集再push進去stack
INTERSERT:拿stack最頂端兩個set做交集再push進去stack
ADD:將stack最頂端的set拿出來後insert進去stack最頂端的set
*/

set<string> s;
map<int, set<string> > m;
stack<int> st;
int k;


void PUSH(void)
{
	st.push(0);
}

void DUP(void)
{
	st.push(st.top());
}

void UNION(void)
{
	int tmp1, tmp2;
	tmp1 = st.top();
	st.pop();
	tmp2 = st.top();
	st.pop();
}

void INTERSERT(void)
{
	set<string> a = m[st.top()];	st.pop();
	set<string> b = m[st.top()];	st.pop();
	set<string> tmp;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(tmp, tmp.begin()));
}

void ADD(void)
{
	int tmp = st.top();
	st.pop();
	int now = st.top();
	st.pop();

	set<string> ss;
	s = m[now];
	ss = m[tmp];
	for(set<string>::iterator it = ss.begin(); it != ss.end(); it++)
	{
		ss.insert(*it);
	}

	m[k++] = ss;
	st.push(k-1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	s.insert("{}");
	m[0] = s;

	int T;
	scanf("%d", &T);

	while(T--)
	{
		int n;

		scanf("%d", &n);

		while(n--)
		{
			k = 1;
		}
	}

	return 0;
}