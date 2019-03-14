#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 105

char map[maxn][maxn];
int visit[maxn][maxn];

void dfs(int row, int column)
{
	visit[row][column] = 1;

	if(visit[row+1][column] == 0)
		dfs(row+1, column);

	if(visit[row][column+1] == 0)
		dfs(row, column+1);

	if(visit[row-1][column] == 0)
		dfs(row-1, column);

	if(visit[row][column-1] == 0)
		dfs(row, column-1);

	if(visit[row+1][column+1] == 0)
		dfs(row+1, column+1);

	if(visit[row+1][column-1] == 0)
		dfs(row+1, column-1);

	if(visit[row-1][column+1] == 0)
		dfs(row-1, column+1);

	if(visit[row-1][column-1] == 0)
		dfs(row-1, column-1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int m, n;

	while(~scanf("%d %d", &m, &n) && (m != 0 || n != 0)) 
	{
		int ans = 0;

		getchar();
		memset(map, '*', sizeof(map));
		memset(visit, -1, sizeof(visit));
		
		for(int i = 1; i <= m; i++)
		{
			for(int l = 1; l <= n; l++)
			{
				scanf("%c", &map[i][l]);
				if(map[i][l] == '@')
					visit[i][l] = 0;
			}
			getchar();
		}

		for(int i = 1; i <= m; i++)
		{
			for(int l = 1; l <= n; l++)
			{
				if(visit[i][l] == 0)
				{
					ans++;
					dfs(i, l);
				}
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}