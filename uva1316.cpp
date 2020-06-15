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
struct Item{
    int a, b;

    bool operator< (const Item& rs) const{
        if(b == rs.b)
            return a > rs.a;
        return b < rs.b;
    }
};

//declaration
int n, x, y;
vector<Item> v;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    // int cnt = 0;

    while(~scanf("%d", &n)){
        v.clear();

        REP(i, 1, n){
            scanf("%d %d", &x, &y);
            v.EB((Item){x, y});
        }

        sort(all(v));

        int day = 1, ans = 0;

        for(auto i : v){
            if(i.b >= day){
                ans += i.a;
                day++;
            }
        }
        // if(cnt++)
            // printf(" ");
        printf("%d\n", ans);
    }

    // puts("");

	return 0;
}