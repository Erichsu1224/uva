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
#define maxn 10000+5

//structure

//declaration
int n, m, k, cnt;
string str;
string hold[maxn][15];
map<string, int> mp;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(~scanf("%d %d\n", &n, &m))
	{
		mp.clear();
		cnt = 0;

		REP(i, 1, n)
		{
			getline(cin, str);

			string tmp = "";
			k = 0;
			REP(j, 0, str.size()-1)
			{
				if(str[j] == ',')
				{
					hold[i][k++] = tmp;
					mp[tmp] = cnt++;
					tmp = "";
				}

				else
					tmp += str[j];
			}

			hold[i][k++] = tmp;
			mp[tmp] = cnt++;
		}

		bool flag = false;

		REP(i, 0, m-1)
		{
			REP(j, i+1, m-1)
			{
				map<PII, int> ck;
				REP(l, 1, n)
				{
					PII ss = MP(mp[hold[l][i]], mp[hold[l][j]]);

					if(!ck[ss])
					{
						ck[ss] = l;
					}

					else
					{
						flag = true;
						printf("NO\n");
						printf("%d %d\n", ck[ss], l);
						printf("%d %d\n", i+1, j+1);
						break;
					}
				}

				if(flag)
					break;
			}
			if(flag)
				break;
		}

		if(!flag)
			printf("YES\n");
	}

	return 0;
}