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
bool cmp(pair<char, int> a, pair<char, int> b){
    if(a.S == b.S){
        return a.F > b.F;
    }

    else{
        return a.S < b.S;
    }
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

    string str;
    int T = 0;

    while(getline(cin, str)){
        map<char, int> mp;
        vector<pair<char, int>> v;

        for(int i = 0; i < str.size(); i++){
            mp[str[i]]++;
        }

        for(auto i : mp){
            v.EB(MP(i.F, i.S));
        }

        sort(all(v), cmp);


        if(T++)
            cout << '\n';
        for(auto i : v){
            cout << int(i.F) << ' ' << i.S << '\n';
        }
    }

	return 0;
}