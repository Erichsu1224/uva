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
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int cases;
int n, x;
vector<int> v;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	cin >> cases;

    while(cases--)
    {
        v.clear();
        cin >> n;

        REP(i, 1, n)
        {
            cin >> x;
            v.EB(x);
        }

        int ans = 1;

        int now = 0;

        for(int i = 0; i < v.size()-1; i++)
        {
            if(now+v[i] < v[i+1])
            {
                ans++;
                now += v[i];
            }
                
        }

        cout << ans << '\n';
    }

	return 0;
}