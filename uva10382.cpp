#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include 
using namespace std;

struct Item
{
	float start, end;

	Item(float start, float end) : start(start), end(end) {}

	bool operator < (const Item &rs) const
	{
		return start < rs.start;
	}
};

struct Circle
{
	int O, r;

	Circle(int O, int r) : O(O), r(r) {}
};

int main(void)
{
	int n, l, w;

	while(scanf("%d %d %d", &n, &l, &w))
	{
		vector<Circle> circle;
		vector<Item> item;
		vector<Item> ls;
		int counter = 1;

		for(int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			circle.push_back(Circle(a, b));
		}

		for(int i = 0; i < n; i++)
		{
			float up, down;
			float r = w;
			float tmp = sqrt((circle[i].r)*(circle[i].r)-(r/2)*(r/2));
			if(circle[i].O-tmp < 0)	up = 0;
			else up = circle[i].O-tmp;

			if(circle[i].O+tmp > l)	down = l;
			else down = circle[i].O+tmp;

			item.push_back(Item(up, down));
		}

		sort(item.begin(), item.end());

		if(item[0].start != 0)
		{
			printf("-1\n");
			continue;
		}

		bool found = false;

		for(int i = 0; i <= item.size();)
		{
			int tmp = -1;
			
			for(int n = i+1; n < item.size(); n++)
			{
				if(item[n].start <= item[i].end)
				{
					if(tmp == -1)
					{
						tmp = n;
						found = true;
						continue;
					}
					if(item[n].end > item[tmp].end)
						tmp = n;
				}

				else break;
			}
			if(!found)	break;
			
			counter++;

			if(item[tmp].end == l)	break;
			i = tmp;
		}

		if(!found)
		{
			printf("-1\n");
			continue;
		}

		if(found)
		{
			printf("%d\n", counter);
		}
	}
	return 0;
}