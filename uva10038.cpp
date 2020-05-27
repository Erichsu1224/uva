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

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

    int n;

    while(cin >> n){
        int now, x;
        bool flag = true;
        map<int, int> mp;

        REP(i, 1, n){
            if(i == 1){
                cin >> now;
                continue;
            }

            cin >> x;
            if(abs(x-now) >= n || mp[abs(x-now)]){
                flag = false;
            }

            mp[abs(x-now)] = 1;
            now = x;
        }

        if(!flag)
            cout << "Not jolly\n";
        else
            cout << "Jolly\n";
    }

	return 0;
}