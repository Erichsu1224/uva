//dynamic programing
//divided and conquer
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//0.05 0.1 0.2 0.5 1 2 5 10 20 50 100
int dollar[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
int dp[6010][10];

int main(void)
{
	float in;

	while(cin >> in)
	{
		if(in == 0) break;

		int money = in*20;
		memset(dp, 0, sizeof(dp));

		for(int i = 0; i < money; i++)
		{
			dp[i][0] = 1;
		}

		int bound;

		for(int i = 0; i < 11; i++)
		{
			if(dollar[i] > money)
			{
				bound = i-1;
				break;
			}
		}

		cout << bound << endl;
		
		for(int i = 0; i <= bound; i++)
		{
			dp[0][i] = 1;
		}

		for(int i = 0; i <= bound; i++)
		{
			for(int j = 1; j <= money; j++)
			{
				if(j >= dollar[i])
				{
					dp[j][i] = dp[j][i-1] + dp[j-dollar[i]][i];
				}
				else
					dp[j][i] = dp[j][i-1];
			}
		}

		printf("%6.2f%17d\n", in, dp[money][bound]);
	
	}
	return 0;
}