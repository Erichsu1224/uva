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
#define maxn 1000+5

//structure

//declaration
int n, m, tmp;
string str;
int cases;
//functions
map<int, int> mp;


int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	cases = 1;

	while(~scanf("%d", &n) && n)
	{
		printf("Scenario #%d\n", cases++);
		mp.clear();
		queue<int> q[maxn];
		queue<int> q_t;

		REP(i, 1, n)
		{
			scanf("%d", &m);
			REP(j, 1, m)
			{
				scanf("%d", &tmp);
				mp[tmp] = i;
			}
		}

		while(cin >> str)
		{
			if(str[0] == 'S')
				break;
			
			if(str[0] == 'E')
			{
				scanf("%d", &tmp);

				if(!q[mp[tmp]].size())
				{
					q_t.emplace(mp[tmp]);
				}
				q[mp[tmp]].emplace(tmp);
			}

			if(str[0] == 'D')
			{
				tmp = q[q_t.front()].front();	q[q_t.front()].pop();
				if(q[q_t.front()].size() == 0)
					q_t.pop();
				printf("%d\n", tmp);

			}
		}

		puts("");
	}

	return 0;
}

