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
int T, n, x;
vector<int> v;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d", &T);

    while(T--){
        v.clear();
        scanf("%d", &n);

        REP(i, 1, n){
            scanf("%d", &x);
            v.EB(x);
        }

        set<ll> s;

        for(int i = 1; i < (1<<n); i++){
            ll tmp = 0;
            for(int j = 0; j < n; j++){
                if((1<<j)&i)
                    tmp += v[j];
            }
            cout << tmp << '\n';
            if(sqrt(tmp) == int(sqrt(tmp)))
                s.insert(tmp);
        }

        printf("%d\n", s.size());
        printf("\n");
    }

	return 0;
}