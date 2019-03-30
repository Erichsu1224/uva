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

	ll M, N;

	while(~scanf("%lld %lld", &M, &N))
	{
		if(M == 0 && N == 0)
			break;

		if(N>M)
		{
			ll tmp = M;
			M = N;
			N = tmp;
		}

		printf("%lld\n", M*N*(M+N-2)+(2*N*(N-1)*(3*M-N-1)/3));
	}

	return 0;
}