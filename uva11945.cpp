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

int main(void)
{
	IOS; 
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int T;

	scanf("%d", &T);

	for(int j = 1; j <= T; j++)
	{
		double total = 0.0;

		for(int i = 0; i < 12; i++)
		{
			double tmp;
			scanf("%lf", &tmp);

			total += tmp;
		}

		total /= 12;
		double b = total-(int)total;
		int a = (int)total;

		vector<int> v;

		while(a >= 1)
		{
			v.PB(a%1000);
			a /= 1000;
		}

		printf("%d $", j);

		for(int i = v.size()-1; i >= 0; i--)
		{
			if(i)
				printf("%d,", v[i]);
			else
			{
				double tmp = v[i]+b;
				printf("%.2lf\n", tmp);
			}
		}
	}
	return 0;
}