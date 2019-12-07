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
#define maxn 105

//structure

//declaration
int n;
int pre[maxn][maxn];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(~scanf("%d", &n))
    {
        MSET(pre, 0);

        REP(i, 1, n)
        {
            REP(j, 1, n)
            {
                scanf("%d", &pre[i][j]);
                pre[i][j] += (pre[i][j-1]+pre[i-1][j]);
            }
        }

        int ans = 0;

        REP(i, 1, n)
            REP(j, 1, n)
                REP(k, i, n)
                    REP(l, j, n)
                    {
                        int tmp = pre[k][l] + pre[i-1][j-1] - pre[k][j-1] - pre[i-1][l];

                        ans = max(tmp, ans);
                    }
        printf("%d\n", ans);
    }

	return 0;
}