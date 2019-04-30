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
#define maxn 1000000

int n, m;
vector<int> v[maxn];

bool cmp(vector<int> a, vector<int> b)
{
	return a.back() < b.back();
}

bool check(int a, int b)
{
	for(int i = 0; i < n; i++)
	{
		if(v[b][i]>v[a][i])
			return false;
	}
	return true;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif


	while(~scanf("%d %d", &n, &m))
	{

		for(int i = 0; i < n; i++)
		{
			v[i].clear();

			for(int k = 0; k < m; k++)
			{
				int tmp;
				scanf("%d", &tmp);
				v[i].PB(tmp);
			}
			sort(v[i].begin(), v[i].end());
		}

		sort(v, v+n, cmp);

		for(int i = 0; i < n; i++)
		{
			for(int k = 0; k < m; k++)
			{
				cout << v[i][k] << ' ';
			}
			cout << endl;
		}
		cout << endl;

		int lis[maxn];
		fill(lis, lis+n, -1);

		int top = 0;

		lis[top] = 0;

		for(int i = 1; i < n; i++)
		{
			int left = 0, right = top;
			bool found = false;

			for(int l = 0; l <= top; l++)
			{
				if(check(lis[l],i))
				{
					lis[l] = i;
					found = true;
					break;
				}
			}

			if(!found)
			{
				if(check(i, lis[top]))
				{
					top++;
					lis[top] = i;
				}
			}
		}
		//test
		for(int i = 0; i <= top; i++)
		{
			for(int k = 0; k < m; k++)
			{
				cout << v[lis[i]][k] << ' ';
			}
			cout << endl;
		}
		cout << top+1 << endl;
		cout << endl;
	}

	return 0;
}