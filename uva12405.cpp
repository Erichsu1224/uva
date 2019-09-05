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
#define maxn 100+5

//structure

//declaration
int T;
int n;
char gr[maxn];
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;

    for(int cases = 1; cases <= T; cases++)
    {
        int ans = 0;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> gr[i];
        }

        for(int i = 0; i < n; i++)
        {
            if(gr[i] == '.')
            {
                ans++;
                i += 2;
            }
                
        }

        cout << "Case " << cases << ": " << ans << '\n';
    }

	return 0;
}