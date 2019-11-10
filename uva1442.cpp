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
#define maxn 1000000+5

//structure

//declaration
int T;
int n;
int top[maxn];
int bot[maxn];
int high[maxn];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &n);

        REP(i, 1, n)
            scanf("%d", &bot[i]);
        REP(i, 1, n)
            scanf("%d", &top[i]);

        int tmp = top[1];
        REP(i, 1, n)
        {
            tmp = min(tmp, top[i]);
            tmp = max(tmp, bot[i]);
            high[i] = tmp;
        }

        tmp = top[n];
        int ans = 0;

        REPP(i, n, 1)
        {
            tmp = min(tmp, top[i]);
            tmp = max(tmp, bot[i]);

            ans += (min(tmp, high[i])-bot[i]);
        }

        printf("%d\n", ans);
    }

	return 0;
}