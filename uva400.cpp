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


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(cin >> n)
	{
		string v[maxn];
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
		if(n % k == 0)
		{
			l = n/k;
		}
		else
			l = n/k+1;

		//printf("%d %d\n", k ,l);

		sort(v, v+n);

/*
		vector<string>::iterator it;

		for(it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}
*/
		for(int i = 0; i < 60; i++)
		{
			printf("-");
		}
		printf("\n");


		//O(n^2)
		for(int i = 0; i < l; i++)
		{
			for(int o = 0; o < k && i+o*l < n; o++)
			{
				cout << v[i+o*l];
				if(o == k-1 || (i+(o+1)*l >= n))
				{
					for(int j = v[i+o*l].size(); j < max; j++)
					{
						printf(" ");
					}
				}
				else
				{
					for(int j = v[i+o*l].size(); j < max+2; j++)
					{
						printf(" ");
					}
				}
			}
			printf("\n");
		}


	}

	return 0;
}