// dynamic programming

#include <iostream>
#include <cstring>
using namespace std;

#define maxn 1000
#define INF 1e9

int main(void)
{
	int cases, n, m;
	int coin[maxn+5];
	int dp[maxn+5][maxn+5];

	cin >> cases;

	while(cases--)
	{
        // input
		cin >> n >> m;

		for(int i = 1; i <= n; i++)
			cin >> coin[i];

		// init
		for(int i = 1; i <= n; i++)
			dp[i][0] = 0;
		for(int i = 1; i <= m; i++)
			dp[0][i] = INF;
        
        // dp
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(j < coin[i])
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = min(dp[i-1][j], dp[i][j-coin[i]]+1);
			}
		}
        if(dp[n][m] == INF)
            cout << "-1\n";
        else
		    cout << dp[n][m] << '\n';
	}
    return 0;
}