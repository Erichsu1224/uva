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
#define maxn (250*250)+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int cases, n, p, q, x;
int dp[maxn];
int l1[maxn];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	cin >> cases;
        
    REP(T, 1, cases)
    {
        cin >> n >> p >> q;

        MSET(l1, 0);
        REP(i, 0, maxn-5)
            dp[i] = 1e9;

        REP(i, 1, p+1)
        {
            cin >> x;
            l1[x] = i;
        }
        
        REP(i, 1, q+1)
        {
            cin >> x;

            if(l1[x] == 0)
                continue;
            
            *lower_bound(dp, dp+n*n, l1[x]) = l1[x];
        }
            
        
        cout << "Case " << T << ": " << lower_bound(dp, dp+n*n, 1e9)-dp << '\n';
    }

	return 0;
}