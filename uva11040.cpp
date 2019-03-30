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


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;

	scanf("%d", &C);

	while(C--)
	{
		int brick[10][10];

		//memset
		for(int i = 0; i < 9; i++)
		{
			for(int n = 0; n <= i; n++)
			{
				if(n % 2 == 0 && i % 2 == 0)
					scanf("%d", &brick[i][n]);
				else
					brick[i][n] = 0;
			}
		}
		
		for(int i = 8; i >= 0; i--)
		{
			for(int n = 0; n <= i; n++)
			{
				if(n % 2 == 1 && i % 2 == 0 && i != 0)
					brick[i][n] = (brick[i-2][n-1] - (brick[i][n-1]+brick[i][n+1]))/2;
				if(i % 2 == 1)
					brick[i][n] = brick[i+1][n] + brick[i+1][n+1];

			}
		}
		
		for(int i = 0; i < 9; i++)
		{
			for(int n = 0; n <= i; n++)
			{
				if(n == 0)
					printf("%d", brick[i][n]);
				else
					printf(" %d", brick[i][n]);
			}
			printf("\n");
		}
	}

	return 0;
}