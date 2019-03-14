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
#define maxn 100000+5

int num[maxn];
int prefix[maxn];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
	

	int N, S;

	while(~scanf("%d %d", &N, &S))
	{
		memset(prefix, 0, sizeof(prefix));

		for(int i = 1; i <= N; i++)
		{
			scanf("%d", &num[i]);

			prefix[i] = prefix[i-1]+num[i];
		}

		bool ok = false;
		int length;

		for(int i = 1; i <= N; i++)
		{
			for(int n = 0; n <= N-i; n++)
			{
				if(prefix[n+i] - prefix[n] >= S)
				{
					ok = true;
					length = i;
					break;
				}
			}

			if(ok)
				break;
		}
		if(ok)
			printf("%d\n", length);
		if(!ok)
			printf("0\n");
	}

	return 0;
}