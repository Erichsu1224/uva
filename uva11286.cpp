#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn

//structure

//declaration

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int n;
    int maxx, ans;

    while(~scanf("%d", &n) && n)
    {
        maxx = 0;

        map<set<int>, int> mp;
        REP(i, 1, n)
        {
            set<int> ss;
            int tmp;

            REP(j, 1, 5)
            {
                scanf("%d", &tmp);
                ss.emplace(tmp);
            }

            mp[ss]++;

            maxx = max(maxx, mp[ss]);
        }

        ans = 0;

        for(auto i : mp)
        {
            if(i.S == maxx)
                ans++;
        }

        printf("%d\n", ans*maxx);
    }

	return 0;
}