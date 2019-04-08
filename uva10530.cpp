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

	/*
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
	*/
	
	int down = 1, up = 10;

	int n;

	while(~scanf("%d", &n))
	{
		if(n == 0)	break;

		getchar();

		string type;

		getline(cin, type);

		if(type == "too high")
		{
				up = min(n,up);
		}

		if(type == "too low")
		{
				down = max(n,down);
		}

		if(type == "right on")
		{
			if(down <= n && n <= up)
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			up = 10;
			down = 1;
		}
	}

	return 0;
}