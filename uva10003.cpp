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
#define maxl 1000+5

int l, n;
int st[maxl];
int dp[maxl][maxl];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(~scanf("%d", &l) && l)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);

		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &st[i]);
		}

		st[0] = 0;
		st[n+1] = l;

		for(int l = 2; l <= n+1; l++)
		{
			for(int i = 0, j = l; j <= n+1; i++, j++)
			{
				int min;
				for(int k = i+1; k < j; k++)
				{
					int tmp = dp[i][k] + dp[k][j];
					if(k == i+1)
						min = tmp;
					else
					{
						if(min > tmp)
							min = tmp;
					}
				}

				dp[i][j] = min + (st[j]-st[i]);
			}
		}

		printf("The minimum cutting is %d.\n", dp[0][n+1]);
	}

	return 0;
}