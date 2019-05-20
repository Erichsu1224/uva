#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
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

	ll n;

	clock_t time;

	time = clock();
	cout << time << endl;

	while(~scanf("%lld", &n) && n)
	{
		ll c1, c2, n1, n2;
		ll min = 9999999999999;
		ll ans1, ans2;
		bool found = false;

		scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
		
		ll hold = n/n1;
		for(ll i = 0; i <= hold; i++)
		{
			ll tmp = (n-n1*i)/n2;
			if((n-n1*i)%n2 == 0 && tmp >= 0)
			{
				found = true;
				ll tmp2 = c1*i + c2*tmp;
				if(min > tmp2)
				{
					min = tmp2;
					ans1 = i;
					ans2 = tmp;
				}
			}
			
		}
		
		if(found)
			printf("%lld %lld\n", ans1, ans2);
		if(!found)
			printf("failed\n");


	}

	time = clock()-time;
	cout << time << endl;
	cout << (float)time/CLOCKS_PER_SEC << endl;

	return 0;
}