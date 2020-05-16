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
string in;
ll n, d;
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
        map<string, int> mp;
        ll ans = 0;
        cin >> n >> in;

        while(true)
        {
            // cout << in << endl;
            string tmp = "";

            for(int i = 0; i < in.size() && i < n; i++)
                tmp += in[i];
            
            // cout << tmp << endl;

            d = stoi(tmp);

            ans = max(ans, d);

            d = d*d;

            in = to_string(d);

            if(mp[in])
                break;

            mp[in]++;
        }

        cout << ans << '\n';
    }

	return 0;
}