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
#define maxn 100000+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n, x, ans;
int lt[maxn], rt[maxn];
vector<int> v;
//functions

bool solve(int a)
{
    int x = v[0], y = a-v[0];
    lt[0] = x;
    rt[0] = 0;

    REP(i, 1, n-1)
    {
        if(i%2 == 0)
        {
            rt[i]=min(y-rt[i-1], v[i]);
            lt[i] = v[i]-rt[i];
        }

        else
        {
            lt[i] = min(x-lt[i-1], v[i]);
            rt[i] = v[i]-lt[i];
        }
        
    }

    return lt[n-1]==0;
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	while(cin >> n && n)
    {
        v.clear();
        ans = 0;

        REP(i, 1, n)
        {
            cin >> x;
            v.EB(x);
        }

        if(n == 1)
        {
            cout << v[0] << '\n';
            continue;
        }

        ans = 0;
        REP(i, 0, n-1)
            ans = max(v[i]+v[(i+1)%n], ans);
             
        if(n%2 == 0)
        {
            cout << ans << '\n';
            continue;
        }

        else
        {
            int l = 0, r = ans*3;

            while(l < r)
            {
                if(solve((r+l)/2))
                    r = (r+l)/2;
                else
                    l = (r+l)/2+1;
            }

            cout << r << '\n';
        }
        
    }

	return 0;
}