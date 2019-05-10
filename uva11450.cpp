//dynamic programming
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxC 20+5
#define maxM 200+5

bool dp[maxM][maxC];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	/*
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
	*/

	int T;

	scanf("%d", &T);

	while(T--)
	{
		int M, C;
		vector<int> v[maxC];

		scanf("%d %d", &M, &C);

		for(int i = 0; i < C; i++)
		{
			int n;
			scanf("%d", &n);
			for(int l = 0; l < n; l++)
			{
				int tmp;
				scanf("%d", &tmp);
				v[i].PB(tmp);
			}
		}

		memset(dp, false, sizeof(dp));

		for(int i = 0; i < v[0].size(); i++)
		{
			if(M-v[0][i] >= 0)
				dp[M-v[0][i]][0] = true;
		}

		for(int i = 1; i < C; i++)
		{
			for(int k = M; k >= 0; k--)
			{
				if(dp[k][i-1] == true)
				{
					for(int l = 0; l < v[i].size(); l++)
					{
						if(k-v[i][l] >= 0)
						{
							dp[k-v[i][l]][i] = true;
						}
					}
				}
			}
		}


		bool found = false;
		for(int i = 0; i <= M; i++)
		{
			if(dp[i][C-1] == true)
			{
				found = true;
				printf("%d\n", M-i);
				break;
			}
		}

		if(!found)
			printf("no solution\n");
	}

	return 0;
}