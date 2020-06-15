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

//structure

//declaration

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    string str;

    while(getline(cin, str)){
        stringstream ss(str);
        int x;
        map<int, int> mp;
        vector<pair<int, int>> v;
        int cnt = 1;

        while(ss >> x){
            if(!mp[x]){
                mp[x] = cnt++;
                v.emplace_back(MP(x, 1));
            } 

            else
                v[mp[x]-1].S++;
        }

        for(auto i : v){
            printf("%d %d\n", i.F, i.S);
        }
    }

	return 0;
}