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
#define maxn 1120+5

//structure

//declaration
int k, n, m;
int prime[maxn];
bool isprime[maxn];
int dp[maxn][20];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    //prime
    k = 0;
    MSET(isprime, true);

    REP(i, 2, 1120)
    {
        if(isprime[i])
        {
            prime[k++] = i;
            for(int j = i*i; j < 1120; j+=i)
            {
                isprime[j] = false;
            }
        }
    }

    dp[0][0] = 1;

    REP(i, 0, k-1)
    {
        REPP(j, 1120, prime[i])
        {
            REP(l, 1, 14)
            {
                dp[j][l] = dp[j][l] + dp[j-prime[i]][l-1];
            }
        }
    }

    while(~scanf("%d %d", &n, &m) && n && m)
    {
        printf("%d\n", dp[n][m]);
    }
	return 0;
}