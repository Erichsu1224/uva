#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 105

struct job
{
	int priority;
	int num;

	job(int num, int priority) : num(num), priority(priority) {}
};



bool overload (int i, int j)
{
	return i > j;
}

int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;

	scanf("%d", &C);

	while(C--)
	{
		int n, m;
		int list_pri[maxn];
		int k = 0;
		int counter = 0;
		queue<job> q;

		scanf("%d %d", &n, &m);

		for(int i = 0 ; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			list_pri[i] = tmp;
			q.push(job(i,tmp));
		}

		sort(list_pri, list_pri+n, overload);

		while(!q.empty())
		{
			if(q.front().priority == list_pri[k])
			{
				counter++;
				if(q.front().num == m)
					break;
				else
				{
					q.pop();
					k++;
				}

			}
			else
			{
				job tmp = q.front();
				q.pop();
				q.push(tmp);
			}
		}

		printf("%d\n", counter);	
	}

	return 0;
}