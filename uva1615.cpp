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

int L, D, n;

struct Item
{
	double left, right;

	bool operator< (const Item& rs) const
	{
		return right < rs.right;
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
	

	while(~scanf("%d %d", &L, &D))
	{
		vector<Item> v;
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			double left = (double)(x - sqrt(D*D-y*y));
			double right = (double)(x + sqrt(D*D-y*y));

			v.PB((Item){left, right});
		}

		sort(v.begin(), v.end());

		double now = v[0].right;
		int counter = 1;

		for(int i = 1; i < n; i++)
		{
			if(now < v[i].left)
			{
				counter++;
				now = v[i].right;
			}
		}

		printf("%d\n", counter);
	}
	return 0;
}