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

int x, y;

int gcd(int a, int b)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	else
	{
		int ans = gcd(b, a%b);
		int tmp = y;
		y = x-a/b*y;
		x = tmp;
		return ans;
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int a, b;

	while(cin >> a >> b)
	{
		int ans = gcd(a, b);
		printf("%d %d %d\n", x, y, ans);
	}

	return 0;
}