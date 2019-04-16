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
#define maxn 100+5

struct point
{
	int x, y;

	point(int x, int y) : x(x), y(y) {}

	bool operator< (const point& rs) const
	{
		return x < rs.x;
	}
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

	while(~scanf("%d", &n) && n != 0)
	{
		vector<point> star;
		int y[maxn];
		int m;

		for(int i = 0; i < n; i++)
		{
			int _x, _y;
			scanf("%d %d", &_x, &_y);
			star.PB(point(_x, _y));
			y[i] = _y;
		}

		sort(star.begin(), star.end());
		sort(y, y+n);

		m = unique(y, y+n)-y;

		cout << m << endl;


	}

	return 0;
}
