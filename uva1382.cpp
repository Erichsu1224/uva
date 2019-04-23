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
		int left[maxn], on[maxn], on2[maxn];

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

		if(m <= 2)
		{
			cout << n << endl;
			continue;
		}

		for(int i = 0; i < n-1; i++)
		{
			for(int l = i+1; l < n; l++)
			{
				int ymin = y[i], ymax = y[l];
				int p = 0;

				for(int k = 0; k < m; k++)
				{
					if(k == 0 || star[k].x != star[k-1].x)
					{
						p++;
						on[p] = on2[p] = 0;
						left[p] = p == 0 ? left[p-1]+on2[p-1]-on[p-1];
					}

					if(star[k].y > ymin && star[k].y < ymax)	on[p]++;
					if(star[k].y >= ymin && star[k].y <= ymax) on2[p]++;
				}
				if(p <= 2)	return p;
				int M = 0;
				for(int j = 0; j <= p; j++)
				{
					ans = max(ans, left[j]+on2[j]+M);
					M = max(M, on[j]-left[j]);
				}
			}
		}


	}

	return 0;
}
