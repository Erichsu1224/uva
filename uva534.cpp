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
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn 200+5

//structure
struct Item
{
	int x, y;
};
//declaration
int n;
float d[maxn];
Item s[maxn];
bool visit[maxn];
int counter;
//functions
float get_dis(Item &a, Item &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	counter = 1;

	while(cin >> n && n)
	{
		queue<int> Q;
		memset(visit, false, sizeof(visit));
		d[0] = 0;
		for(int i = 1; i < n; i++)
		{
			d[i] = 1e9;
		}

		for(int i = 0; i < n; i++)
		{
			cin >> s[i].x >> s[i].y;
		}

		int min_d = get_dis(s[0], s[1]);

		Q.push(0);

		while(!Q.empty())
		{
			int idx = Q.front();
			Q.pop();

			visit[idx] = false;

			for(int i = 1; i < n; i++)
			{
				float tmp = max(d[idx], get_dis(s[i], s[idx]));

				if(tmp < d[i])
				{
					d[i] = tmp;
					if(!visit[i])
					{
						Q.push(i);
						visit[i] = true;
					}
				}
			}
		}

		printf("Scenario #%d\nFrog Distance = %.3f\n\n", counter++, d[1]);
	}

	return 0;
}