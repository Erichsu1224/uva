//depth first search will cause time limit exceed.

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


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	//dp
	int n, k, m;

	while(~scanf("%d %d %d", &n, &k, &m))
	{
		ll dp[k+5][n+5];

		for(int i = 0; i <= k+5; i++)
		{
			dp[i][0] = 0;
		}
		for(int i = 0; i <= n+5; i++)
		{
			dp[0][i] = 0;
		}
		dp[0][0] = 1;

		for(int i = 1; i <= k; i++)
		{
			for(int l = 1; l <= n; l++)
			{
				ll tmp = 0;
				for(int o = l-m; o < l; o++)
				{
					if(o < 0)
						continue;
					tmp += dp[i-1][o];
				}
				dp[i][l] = tmp;
			}
		}
/*
		for(int i = 1; i <= k; i++)
		{
			for(int l = 1; l <= n; l++)
			{
				cout << dp[i][l] << ' ';
			}
			cout << endl;
		}
		cout << endl;
*/
		printf("%lld\n", dp[k][n]);
	}

	return 0;
}