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

//functions
ll poww(ll x, ll y){
    if (y == 0) 
        return 1;
    ll tmp = poww(x, y/2);
    if (y%2)
        return x * tmp * tmp;
    else
        return tmp * tmp;
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	string str;
    ll n;
    ll x;

    while(~scanf("%lld\n", &n)){
        vector<ll> v;

        getline(cin, str);
        stringstream ss(str);

        while(ss >> x){
            v.EB(x);
        }
        ll ans = 0;

        for(int i = 0; i < v.size()-1; i++){
            ans += (v.size()-i-1)*v[i]*poww(n, v.size()-i-2);
        }

        cout << ans << '\n';
    }

	return 0;
}