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
#define maxn 100+5

int stick[maxn];
bool used[maxn];
int n;

bool cmp(int& a, int& b)
{
	return a > b;
}

bool dfs(int index, int counter, int len_n, int len_t)
{
	if(len_n == len_t)
	{
		if(counter == n)
		{
			return true;
		}

		else
		{
			len_n = 0;
		}
	}

	if(!len_n)
	{
		for(index = 0; used[index]; index++);
		used[index] = true;
		if(dfs(index+1, counter+1, len_n+stick[index], len_t))
			return true;
		used[index] = false;
	}

	else
	{
		for(int i = index; i < n; i++)
		{
			if (used[i] || (i&&stick[i] == stick[i - 1] && !used[i - 1]))
                continue;
			if(stick[i] + len_n <= len_t)
			{
				used[i] = true;
				if(dfs(i+1, counter+1, len_n+stick[i], len_t))
					return true;
				used[i] = false;

			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(~scanf("%d", &n) && n!=0)
	{
		int total = 0;

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &stick[i]);
			total += stick[i];
		}

		sort(stick, stick+n, cmp);
		fill(used, used+n, false);

		for(int i = stick[0]; i <= total; i++)
		{
			if(total%i)
				continue;

			if(dfs(0, 0, 0, i))
			{
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}