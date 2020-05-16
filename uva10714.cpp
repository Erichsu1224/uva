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
int cases, n, m, x, minn, maxx;
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
        minn = -1e9;
        maxx = -1e9;

        cin >> n >> m;

        REP(i, 1, m)
        {
            cin >> x;
            v.EB(x);
        }

        for(int i = 0; i < m; i++)
        {
            int tmp1 = n-v[i];
            int tmp2 = v[i];

            if(tmp1 > tmp2)
                swap(tmp1, tmp2);

            minn = max(minn, tmp1);
            maxx = max(maxx, tmp2);
        }

        cout << minn << ' ' << maxx << '\n';
    }

	return 0;
}