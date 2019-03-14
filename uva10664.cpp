#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ll long long
#define C cases
#define pb push_back

int lug[25];
int dp[30][5000];

bool cmp(int a, int b)
{
	return a > b;
}


int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;

	scanf("%d", &C);
	getchar();

	while(C--)
	{
		int k = 1;
		int total = 0;
		int carA = 0, carB = 0;

		while(~scanf("%d", &lug[k++]))
		{
			total += lug[k-1];
			if(getchar() == '\n')
				break;
		}

		sort(lug, lug+k);

		for(int i = 1; i < k; i++)
		{
			cout << lug[i] << ' ';
		}
		cout << endl;
		cout << total << endl;

		if(total % 2 == 1)
		{
			printf("NO\n");
			continue;
		}

		total /= 2;

		for(int i = 0; i < k+5; i++)
		{
			dp[i][0] = 1;
		}
		for(int i = 0; i < total+5; i++)
		{
			dp[0][i] = 1;
		}

		for(int i = 0; i < total; i++)
		{
			for(int n = 0; n < k; n++)
			{
				dp[n][i] = max(dp[n - 1][i], dp[n - 1][i - lug[n]]+lug[i]);
			}
		}

		if(dp[k-1][total])
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}