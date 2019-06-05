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
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	IOS; 
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d", &n))
	{
		vector<int> v;
		vector<int> a;
		vector<int> b;
		int total_a = 0, total_b = 0;

		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);

			v.PB(tmp);
		}

		sort(v.begin(), v.end(), cmp);

		for(int i = 0; i < v.size(); i++)
		{
			if(total_a <= total_b)
				total_a += v[i];
			else
				total_b += v[i];
		}

		if(total_a == total_b)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}