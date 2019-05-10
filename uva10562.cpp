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
#define maxn 200+10

char str[maxn][maxn];
int n;

void dfs(int row, int col)
{
	int i = col;

	printf("%c(", str[row][col]);

	if(row+1 < n && str[row+1][col] == '|')
	{
		while(str[row+2][i-1] == '-' && i-1 >= 0)
			i--;


		for(; str[row+2][i] == '-' && str[row+3][i] != '\0'; i++)
		{
			if(!isspace(str[row+3][i]) && str[row+3][i] != '#')
			{
				//cout << l << ' ' << str[row+3][l] << endl;
				dfs(row+3, i);
			}
		}

	}
	printf(")");
	
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int T;
	scanf("%d", &T);
	getchar();

	while(T--)
	{
		n = 0;

		while(gets(str[n]))
		{
			if(str[n][0] == '#')
				break;

			n++;
		}

		if(n == 0)
		{
			printf("()\n");
			continue;
		}

		//test
		
		/*
		for(int i = 0; i < n; i++)
		{
			cout << str[i] << endl;
		}
		*/

		printf("(");
		

		
		for(int i = 0; i < strlen(str[0]); i++)
		{
			if(str[0][i] != ' ')
			{
				dfs(0, i);
				break;
			}
		}
		
		printf(")\n");
		

	}

	return 0;
}