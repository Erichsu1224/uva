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

struct point
{
	int x, y;

	point(int x, int y) : x(x), y(y) {}
};

struct line
{
	point to, from;	
};
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d", &n) && n)
	{
		vector<line> v;
		for(int i = 0; i < n; i++)
		{
			int to_x, to_y, from_x, from_y;
			scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
			v.PB((line){point(from_x, from_y), point(to_x, to_y)}`);
		}

		int o_x, o_y;
		scanf("%d %d", &o_x, &o_y);

		for(int i = 0; i < n; i++)
		{
			double l = atan2()
		}
	}

	return 0;
}