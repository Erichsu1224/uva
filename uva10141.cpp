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
int n, m;
double x;
int y;
string str, ans;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T = 1;

    while(~scanf("%d %d\n", &n, &m)){
        if(!n && !m)
            break;

        REP(i, 1, n)
            getline(cin, str);

        double price;
        int num = -1e9;

        REP(i, 1, m){
            getline(cin, str);
            scanf("%llf %d\n", &x, &y);

            if(y > num){
                num = y;
                price = x;
                ans = str;
            }

            else if(y == num){
                if(price > x){
                    price = x;
                    ans = str;
                }      
            }

            REP(j, 1, y)
                getline(cin, str);
        }

        if(T > 1)
            cout << '\n';

        cout << "RFP #" << T++ << '\n';
        cout << ans << '\n';
        
    }

	return 0;
}