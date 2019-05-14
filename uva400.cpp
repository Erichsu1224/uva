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

	int n;

	while(~scanf("%d", &n))
	{
		vector<string> v;
		int max = 0;

		for(int i = 0; i < n; i++)
		{
			string tmp;
			cin >> tmp;
			v.PB(tmp);

			if(tmp.size() > v[max].size())
				max = i;
		}

		int k = (60-v[max].size())/(v[max].size()+2) + 1;
		k = v.size()/k;
		max = v[max].size();


		sort(v.begin(), v.end());

		vector<string>::iterator it;

		for(it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}

		for(int i = 0; i < 60; i++)
		{
			printf("-");
		}
		printf("\n");

		for(int i = 0; i < )


	}

	return 0;
}