#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 1500


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int T;
	int counter = 1;

	while(~scanf("%d", &T) && T)
	{

		//if(counter != 1)
		//	printf("\n");

		printf("Scenario #%d\n", counter++);

		int n;
		queue<int> q;
		queue<int> qt[maxn];
		map<int, int> m;

		for(int k = 0; k < T; k++)
		{
			scanf("%d", &n);

			for(int i = 0; i < n; i++)
			{
				int tmp;
				scanf("%d", &tmp);
				m[tmp] = k;
			}
		}

		string type;

		while(cin >> type)
		{
			if(type[0] == 'S')
				break;

			else if(type[0] == 'D')
			{
				int team = q.front();
				printf("%d\n", qt[team].front());
				qt[team].pop();
				if(qt[team].empty())
				{
					q.pop();
				}
			}

			else if(type[0] == 'E')
			{
				int p;
				scanf("%d", &p);
				getchar();

				int team = m[p];
				if(qt[team].empty())
				{
					q.push(team);
					qt[team].push(p);
				}
				else
				{
					qt[team].push(p);
				}
			}
		}

		printf("\n");
	}

	return 0;
}