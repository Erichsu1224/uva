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
#define EB emplace_back

string v[maxn];


int main(void)
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d\n", &n))
	{
		int max = 0;


		//O(n)
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];

			if(v[i].size() > max)
				max = v[i].size();
		}

		int k = (60-max)/(max+2) + 1;
		int l;

		if(n%k == 0)
			l = n/k;
		else
			l = n/k+1;

		sort(v, v+n);

		for(int i = 0; i < 60; i++)
		{
			printf("-");
		}
		printf("\n");

		int cnt = 0;

		vector<string> ans[maxn];

		//O(n^2)
		for(int i = 0; i < k; i++)
		{
			for(int j = 0; j < l; j++)
			{
				ans[j].EB(v[cnt++]);
				if(cnt >= n)
					break;
			}
				

			if(cnt >= n)
				break;
		}

		for(int i = 0; i < l; i++)
		{
			for(int j = 0; j < ans[i].size(); j++)
			{
				if(j < k-1)
				{
					cout << ans[i][j];
					for(int o = ans[i][j].size()+1; o <= max+2; o++)
						printf(" ");
				}
					
				else
				{
					cout << ans[i][j];
					for(int o = ans[i][j].size()+1; o <= max; o++)
						printf(" ");
				}
					
			}
			cout << '\n';
		}
	}

	return 0;
}