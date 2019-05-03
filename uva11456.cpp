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
		int max = 0;
		vector<int> in;

		scanf("%d", &n);
		
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
		
		for(int i = 0; i < n; i++)
		{
			int a;

			scanf("%d", &a);
			in.pb(a);
		}
	 
	 	for(int k = 0; k < n; k++)
	 	{
	 		vector<int> lis;
			vector<int> lis2;

			for(int i = k; i < n; i++)
			{
				if(in[i] < in[k])
					continue;
				if(lis.size() == 0 || in[i] > lis.back())
					lis.pb(in[i]);
				else
					*lower_bound(lis.begin(), lis.end(), in[i]) = in[i];
				
			}

			for(int i = in.size()-1; i >= k; i--)
			{
				if(in[i] > in[k])
					continue;
				if(lis2.size() == 0 || in[i] > lis2.back())
					lis2.pb(in[i]);
				else
					*lower_bound(lis2.begin(), lis2.end(), in[i]) = in[i];

				
			}
			if(max < lis.size()+lis2.size()-1)
				max = lis.size()+lis2.size()-1;
		}

	    printf("%d\n", max);
	    
	}
}
