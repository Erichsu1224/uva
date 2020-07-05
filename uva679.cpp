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

    int T, n, m;

    while(cin >> T){
        if(T == -1)
            break;

        REP(i, 1, T){
            cin >> n >> m;

            int dep = 1, now = 1;

            while(dep < n){
                if(m % 2 == 0){
                    now = now*2+1;
                    m /= 2;
                }
                else{
                    now = now*2;
                    m = (m+1)/2;
                }

                dep++;
            }

            cout << now << '\n';
        }
        
        
    }

	return 0;
}