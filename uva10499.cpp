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
#define pi 3.1415926
#define r 1
//structure

//declaration

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	double origin = 4*r*r*pi;

    int n;

    while(cin >> n){
        if(n < 0){
            break;
        }
        if(n == 1)
            printf("0%%\n");
        else{
            double ans = origin+n*r*r*pi;
            printf("%.0f%%\n", (ans-origin)/origin*100);
        }
        
    }

	return 0;
}