#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define ll long long
#define C cases
#define pb push_back


int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int N;
	int k = 1;

	while(~scanf("%d", &N))
	{
		vector<int> lis;
		ll max = 0;

		for(int i = 0; i < N; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			lis.pb(tmp);
		}

		for(int i = 1; i <= N; i++) //區間有幾個
		{
			for(int n = 0; n <= N-i; n++) //從第幾個開始
			{
				ll tmp = 1;
				for(int l = 0; l < i; l++)
				{
					tmp *= lis[n+l];
				}
				if(tmp > max)
					max = tmp;
			}
		}

		printf("Case #%d: The maximum product is %lld.\n\n", k++, max);
	}

	return 0;
}