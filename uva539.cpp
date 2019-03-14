//do dfs to every node
//backtracking
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 25+5

int matrix[maxn][maxn];
int n, m;
int h;
int maxh = 0;

void dfs(int a, int h)
{
	for(int i = 0; i < n; i++)
	{
		if(matrix[a][i] == 1)
		{
			matrix[a][i] = matrix[i][a] = 0;
			dfs(i, h+1);
			matrix[a][i] = matrix[i][a] = 1;
		}
	}

	if(maxh < h)	maxh = h;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(~scanf("%d %d", &n, &m))
	{
		if(n == 0 && m == 0)
			break;
		maxh = 0;

		memset(matrix, 0, sizeof(matrix));

		for(int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);

			matrix[a][b] = matrix[b][a] = 1;
		}

		for(int i = 0; i < n; i++)
		{
			h = 0;
			dfs(i, h);
		}

		printf("%d\n",maxh);
	}

	return 0;
}