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
#define pi 2.0*acos(0.0)

//structure

//declaration
double n, a, b, c;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(cin >> n){
        c = n*n-(n*n*pi/6.0)-(n*(n/2*sqrt(3.0))/2.0);
        b = n*n-(n*n*pi/4.0)-2.0*c;
        a = n*n-4.0*b-4.0*c;
        printf("%.3llf %.3llf %.3llf\n", a, 4.0*b, 4.0*c);
    }

	return 0;
}