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
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)

struct Item
{
	double left, right;

	bool operator< (const Item& rs) const
	{
		if(left == rs.left)
			return right < rs.right;
		return left < rs.left;
	}
};

vector<Item> v;

bool can(double dist)
{
	double now = v[0].left+dist;

	if(now > v[0].right)
		return false;

	for(int i = 1; i < v.size(); i++)
	{
		now = max(now, v[i].left) + dist;
			
		if(now > v[i].right)
			return false;
	}

	return true;
}

int main(void)
{
	IOS; 
	
	#ifndef DEBUG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d", &n))
	{
		v.clear();

		for(int i = 0; i < n; i++)
		{
			double l, r;
			scanf("%lf %lf", &l, &r);

			v.PB((Item){l, r});
		}

		sort(v.begin(), v.end());

		double left = 0, right = 1000000;
		double ans;

		while(right - left > 1e-9)
		{
			if(can((left+right)/2.0))
			{
				ans = (left+right)/2.0;
				left = (left+right)/2.0;
			}
			else
				right = (left+right)/2.0;
		}


		int rp = 0, rq = 1;

        for(int p, q = 1; q <= n; ++q){
            p = round(ans * q);
            if(fabs((double)p/q - ans) < fabs((double)rp/rq - ans)){
                rp = p;  rq = q; 
            }
        }
 
        printf("%d/%d\n", rp, rq);
	}

	return 0;
}