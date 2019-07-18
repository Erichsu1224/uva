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
#define C cases
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn
#define mod 100000007
//structure

//declaration

//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    ll s, tmp, ans;
    bool flag;

    while(cin >> s && s)
    {
        flag = false;

        for(ll i = 1; i * i * 6 < s; i++)
        {
            tmp = (s-6*i*i);

            if(tmp%(7*i) == 0)
            {
                ans = tmp/(7*i)%mod;

                cout << "Possible Missing Soldiers = " << ans*ans*2%mod << '\n';
                flag = true;
            }
        }

        if(!flag)
            cout << "No Solution Possible\n";
        cout << '\n';
    }

	return 0;
}