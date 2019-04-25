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
#define maxn 500+5


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	string vac_f;
	string vac_m;
	int count = 1;

	while(getline(cin, vac_f) && vac_f != "#")
	{
		getline(cin, vac_m);
		int dp[maxn][maxn];

		for(int i = 0; i < maxn; i++)
		{
			dp[i][0] = dp[0][i] = 0;
		}

		for(int i = 1; i <= vac_f.size(); i++)
		{
			for(int k = 1; k <= vac_m.size(); k++)
			{
				if(vac_f[i-1] == vac_m[k-1])
					dp[i][k] = dp[i-1][k-1]+1;
				else
					dp[i][k] = max(dp[i-1][k], dp[i][k-1]);
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n", count, dp[vac_f.size()][vac_m.size()]);
		count++;
	}

	return 0;
}