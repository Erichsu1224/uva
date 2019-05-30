#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
/*
1 X Y : move box X to the left to Y (ignore this if X is already the left of Y )
• 2 X Y : move box X to the right to Y (ignore this if X is already the right of Y )
• 3 X Y : swap box X and Y
• 4: reverse the whole line.
*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n, m;

	while(~scanf("%d %d", &n, &m))
	{
		list<int> l;
		for(int i = 1; i <= n; i++)
		{
			l.PB(i);
		}

		for(int i = 0; i < m; i++)
		{
			int type;
			int x, y;
			scanf("%d", &type);

			if(type == 1)
			{
				scanf("%d %d", &x, &y);
				for(list<int>::iterator it = l.begin(); it != l.end(); it++)
				{
					if(*it == y)
					{
						it--;
						l.insert(it, x);
					}
					break;
				}
			}

			if(type == 2)
			{
				scanf("%d %d", &x, &y);
			}

			if(type == 3)
			{
				scanf("%d %d", &x, &y);

			}

			if(type == 4)
			{

			}
		}

		ll total = 0;
		int counter = 1;

		for(list<int>::iterator it = l.begin(); it != l.end(); it++)
		{
			if(counter % 2 == 1)
				total += *it;
			counter++;
		}
		cout << total << endl;
	}

	return 0;
}