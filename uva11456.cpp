//LIS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 2100

int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int cases;

	cin >> cases;

	while(cases--)
	{
		int n;
		vector<int> lis;
		vector<int> lis2;
		vector<int> in;

		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)
		{
			int a;

			scanf("%d", &a);
			in.pb(a);
		}


	 
		for(int i = 0; i < n; i++)
		{
			if(lis.size() == 0 || in[i] > lis.back())
				lis.pb(in[i]);
			else
				*lower_bound(lis.begin(), lis.end(), in[i]) = in[i];
		}

		for(int i = 0; i < n; i++)
		{
			if(lis2.size() == 0 || in[i] < lis2.back())
				lis2.pb(in[i]);
			else
				*lower_bound(lis.begin(), lis2.end(), in[i]) = in[i];
		}

	    printf("%lu\n", lis.size()+lis2.size()-1);
	}
}