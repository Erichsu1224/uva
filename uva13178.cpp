#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define all(x) x.begin(), x.end()
#define maxn

//structure

//declaration
int dp[1000000005];
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    dp[0] = 0;

    for(ll i = 1; i <= 1000000000; i++)
    {
        dp[i] = dp[i-1]+(i%3);
    }

    int T;

    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;
        if((dp[n]%3) == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

	return 0;
}