#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 10005

struct Item
{
	int give, time;

	Item(int give, int time) : give(give), time(time) {}

	bool operator < (const Item& rs) const
	{
		return time > rs.time;
	}
};

vector<Item> worker;

int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int N;
	int k = 0;

	while(~scanf("%d", &N) && N != 0)
	{
		worker.clear();

		for(int i = 0; i < N; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			worker.pb(Item(a, b));
		}

		sort(worker.begin(), worker.end());

		int start_time = 0, end_time = 0;

		for(int i = 0; i < N; i++)
		{
			start_time += worker[i].give;
			
			if(start_time + worker[i].time > end_time)
				end_time = start_time+worker[i].time;
		}

		printf("Case %d: %d\n", ++k, end_time);
	}

	return 0;
}