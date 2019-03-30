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
		if(n==0 & m==0)
			break;

		vector<int> a;
		vector<int> b;

		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);

			if(!a.empty() && a.back() == tmp)
				continue;
			else
				a.PB(tmp);
		}

		for(int i = 0; i < m; i++)
		{
			int tmp;
			scanf("%d", &tmp);

			if(!b.empty() && b.back() == tmp)
				continue;
			else
				b.PB(tmp);
		}

		int total_a = 0;
		int total_b = 0;

		for(int i = 0; i < a.size(); i++)
		{
			bool found = false;
			for(int k = 0; k < b.size(); k++)
			{
				if(a[i] == b[k])
				{
					found = true;
					break;
				}
			}

			if(!found)
				total_a++;
		}

		for(int i = 0; i < b.size(); i++)
		{
			bool found = false;
			for(int k = 0; k < a.size(); k++)
			{
				if(b[i] == a[k])
				{
					found = true;
					break;
				}
			}

			if(!found)
				total_b++;
		}

		printf("%d\n", min(total_a, total_b));
	}

	return 0;
}