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

	int a, b, c, d;

    while(~scanf("%d %d %d %d\n", &a, &b, &c, &d)){
        if(!a && !b && !c && !d)
            break;
        
        int ans = 0, tmp;
        ans += 720;

        tmp = (a-b)*9;
        if(tmp < 0)
            tmp += 360;
        ans += tmp;

        ans += 360;

        tmp = (c-b)*9;
        if(tmp < 0)
            tmp += 360;
        ans += tmp;

        tmp = (c-d)*9;
        if(tmp < 0)
            tmp += 360;
        ans += tmp;

        cout << ans << '\n';
    }

	return 0;
}