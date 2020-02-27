#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn

//structure

//declaration
int T;
int n, id;
string str;
map<set<int> , int> mp;
vector<set<int> > v;

//functions
int findId(set<int> a)
{
	if(mp[a])
		return mp[a];
	else
	{
		mp[a] = id++;
		v.EB(a);
		return mp[a];
	}
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	scanf("%d", &T);

	while(T--)
	{
		v.clear();
		mp.clear();
		stack<int> St;
		id = 0;
		scanf("%d", &n);

		while(n--)
		{
			cin >> str;
			// cout << str << endl;

			if(str[0] == 'P')
			{
				set<int> hold;
				St.push(findId(hold));
			}

			else if(str[0] == 'D')
			{
				St.push(St.top());
			}

			else
			{
				set<int> A = v[St.top()]; St.pop();
				set<int> B = v[St.top()]; St.pop();
				set<int> tmp;

				if(str[0] == 'A')
				{
					tmp = B;
					tmp.insert(findId(A));
					St.push(findId(tmp));
				}

				if(str[0] == 'U')
				{
					set_union(all(A), all(B), inserter(tmp, tmp.begin()));
					St.push(findId(tmp));
				}

				if(str[0] == 'I')
				{
					set_intersection(all(A), all(B), inserter(tmp, tmp.begin()));
					St.push(findId(tmp));
				}
			}
			printf("%d\n", v[St.top()].size());
		}
		puts("***");
	}

	return 0;
}