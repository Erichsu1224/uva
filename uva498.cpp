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
ll pow(ll a, ll b){
    if(b == 0)
        return 0;
    
    ll tmp = 1;
    
    REP(i, 1, b)
        tmp *= a;
    return tmp;
}
int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	string str;
    string x;

    while(getline(cin, str)){
        vector<ll> v;
        stringstream ss(str);
        while(ss >> x){
            v.PB(stoi(x));
        }

        getline(cin, str);
        stringstream sss(str);

        ll cnt = 0;
        while(sss >> x){
            ll ans = 0;
            ll num = stoi(x);
            for(ll i = 0; i < v.size(); i++){
                ans += v[i]*pow(num, v.size()-i-1);
            }

            if(cnt++)
                cout << ' ';
            cout << ans;
        }
        cout << '\n';
    }

	return 0;
}