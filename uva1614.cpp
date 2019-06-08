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
		int list[100005];
		//int total_a = 0, total_b = 0;
		ll total = 0;

		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);

			v.PB((Item){i, tmp});
			total += tmp;
		}

		sort(v.begin(), v.end());

		if(total%2 != 0)
		{
			printf("No\n");
			continue;
		}

		else
		{		
			printf("Yes\n");

			total /= 2;
			
			for(int i = 0; i < v.size(); i++)
			{
				if (v[i].value <= total)
				{
					list[v[i].id] = 1;
					total -= v[i].value;
				}
         		else 
					list[v[i].id] = -1;
			}

			for(int i = 0; i < n; i++)
			{
				if(i)
					printf(" %d", list[i]);
				else
					printf("%d", list[i]);

			}
			printf("\n");
		}
		
	}

	return 0;
}