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
int n, q, x, cases;
vector<int> v;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;
    cases = 1;

	while(cin >> n >> q)
    {
        if(!n && !q)
            break;
        cout << "CASE# " << cases++ << ":\n";
        v.clear();

        REP(i, 1, n)
        {
            cin >> x;
            v.EB(x);
        }

        sort(all(v));

        REP(i, 1, q)
        {
            cin >> x;
            bool flag = false;

            REP(j, 0, v.size()-1)
            {
                if(v[j] == x)
                {
                    cout << x << " found at " << j+1 << '\n';
                    flag = true;
                    break;
                }
            }

            if(!flag)
                cout << x << " not found\n";
        }
    }

	return 0;
}