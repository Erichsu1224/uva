#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
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

struct st
{
	ll a;

	bool operator< (const st &rs) const
	{
		return a > rs.a;
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

	set<ll> s;
	priority_queue<st> q;

	int num[3] = {2, 3, 5};

	s.insert(1);
	q.push((st){1});

	for(int i = 1; ; i++)
	{

		ll tmp = q.top().a;
		q.pop();

		if(i == 1500)
		{
			printf("The 1500'th ugly number is %lld.\n", tmp);
			break;
		}

		for(int k = 0; k < 3; k++)
		{
			if(!s.count(tmp*num[k]))
			{
				q.push((st){tmp*num[k]});
				s.insert(tmp*num[k]);
			}
		}
	}

	return 0;
}