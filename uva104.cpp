#include <iostream>
using namespace std;
#define maxn 

float dp[maxn][maxn];


int main(void)
{
	int n;

	while(cin >> n)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j)
					dp[i][j] = 0;
				else
					cin >> dp[i][j];
			}
		}
	}
}