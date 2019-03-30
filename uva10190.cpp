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

#define ll unsigned long long
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

	ll n, m;

	while(~scanf("%lld %lld", &n, &m))
	{
		if(m == 1 || m == 0 || m > n)
		{
			printf("Boring!\n");
			continue;
		}
		vector<ll> v;
		v.PB(n);

		while(n >= 1 && n % m == 0)
		{
			n /= m;
			v.PB(n);
		}

		if(v.back() != 1)
			printf("Boring!\n");
		else
		{
			for(int i = 0; i < v.size(); i++)
			{
				if(i == 0)
					printf("%lld", v[i]);
				else
					printf(" %lld", v[i]);
			}
			printf("\n");
		}
	}

	return 0;
}