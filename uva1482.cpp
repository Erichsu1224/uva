#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>

int SG(ll x)
{
	if(x%2 == 0)
		return x/2;
	else
		return SG(x/2);
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
	

	int C;

	cin >> C;

	while(C--)
	{
		ll a;

		cin >> a;

		int mex = 0;

		for(int i = 0; i < a; i++)
		{	
			ll tmp;
			cin >> tmp;

			mex ^= SG(tmp);
		}

		if(mex)
			printf("YES\n");
		if(!mex)
			printf("NO\n");
	}

	return 0;
}