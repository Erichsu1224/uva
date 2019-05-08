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
#define maxn 80+5

int dp[maxn][maxn];
int k;
string str1, str2;

int min(int a, int b, int c)
{
	return min(min(a,b), min(b, c));
}

void backtracking(int a, int b)
{
	if(a == 0 && b == 0)
		return;

	int minn;
	if(str1[a-1] == str2[b-1])
	{
		minn = min(dp[a-1][b]+1, dp[a][b-1]+1, dp[a-1][b-1]);
		if(dp[a-1][b]+1 == minn && a-1 >= 0)
		{
			backtracking(a-1, b);
			if(dp[a-1][b] != dp[a][b])
			{
				printf("%d Delete %d", k++, dp[a][b]);
				cout << endl;
			}
		}
		else if(dp[a][b-1]+1 == minn && b-1 >= 0)
		{
			backtracking(a, b-1);
			if(dp[a][b-1] != dp[a][b])
			{
				printf("%d Insert %d,", k++, dp[a][b]);
				cout << str2[b-1] << endl;
			}
		}
		else if(dp[a-1][b-1] == minn && a-1>=0 && b-1>=0)
		{
			backtracking(a-1, b-1);
			if(dp[a-1][b-1] != dp[a][b])
			{
				printf("%d Replace %d, ", k++, dp[a][b]);
				cout << str2[b-1] << endl;
			}
		}
	}
	else
	{
		minn = min(dp[a-1][b], dp[a][b-1], dp[a-1][b-1]);
		if(dp[a-1][b] == minn && a-1 >= 0)
		{
			backtracking(a-1, b);
			if(dp[a-1][b] != dp[a][b])
			{
				printf("%d Delete %d", k++, dp[a][b]);
				cout << endl;
			}
		}
		else if(dp[a][b-1] == minn && b-1 >= 0)
		{
			backtracking(a, b-1);
			if(dp[a][b-1] != dp[a][b])
			{
				printf("%d Insert %d,", k++, dp[a][b]);
				cout << str2[b-1] << endl;
			}
		}
		else if(dp[a-1][b-1] == minn && a-1>=0 && b-1>=0)
		{
			backtracking(a-1, b-1);
			if(dp[a-1][b-1] != dp[a][b])
			{
				printf("%d Replace %d, ", k++, dp[a][b]);
				cout << str2[b-1] << endl;
			}
		}
	}
	
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	bool first = true;

	while(cin >> str1)
	{
		cin >> str2;
		getchar();
		k = 1;

		if(!first)
		{
			printf("\n");
		}

		for(int i = 0; i <= str1.size(); i++)
		{
			dp[i][0] = i;
		}

		for(int i = 0; i <= str2.size(); i++)
		{
			dp[0][i] = i;
		}

		for(int i = 1; i <= str1.size(); i++)
		{
			for(int n = 1; n <= str2.size(); n++)
			{
				if(str1[i-1] == str2[n-1])
					dp[i][n] = min(dp[i-1][n-1], dp[i-1][n]+1, dp[i][n-1]+1);
				else
					dp[i][n] = min(dp[i-1][n-1], dp[i-1][n], dp[i][n-1])+1;
			}
		}

		printf("%d\n", dp[str1.size()][str2.size()]);
		backtracking(str1.size(), str2.size());
		first = false;
	}

	return 0;
}