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
	int id;
	int value;

	bool operator< (const Item& rs)const
	{
		return value > rs.value;
	}
};

int main(void)
{
	IOS; 
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d", &n))
	{
		vector<Item> v;
		int list[10000];
		int total_a = 0, total_b = 0;

		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);

			v.PB((Item){i, tmp});
		}

		sort(v.begin(), v.end());

		for(int i = 0; i < v.size(); i++)
		{
			if(total_a <= total_b)
			{
				total_a += v[i].value;
				list[v[i].id] = 1;
			}
			else
			{
				total_b += v[i].value;
				list[v[i].id] = -1;
			}
		}

		if(total_a == total_b)
		{
			cout << "Yes" << endl;
			for(int i = 0; i < n; i++)
			{
				if(i)
					printf(" %d", list[i]);
				else
					printf("%d", list[i]);
			}
			printf("\n");
		}
		else
			cout << "No" << endl;
	}

	return 0;
}