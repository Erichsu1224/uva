#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 1000000+5

int prime[maxn];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	//prime
	int k = 0;

	for(int i = 3; i < maxn; i++)
	{
		bool found = true;
		for(int n = 2; n <= sqrt(i); n++)
		{
			if(i % n == 0)
			{
				found = false;
				break;
			}
		}

		if(found) prime[k++] = i;
	}

	int num;

	while(~scanf("%d", &num) && num != 0)
	{
		bool found = false;

		for(int i = 0; i <= k/2; i++)
		{
			int tmp = num-prime[i];
			//binary search
			int left = 0, right = k-1, middle;

			while(left <= right)
			{
				middle = (left+right)/2;

				if(prime[middle] == tmp)
				{
					found = true;
					break;
				}
				else if(prime[middle] > tmp)
					right = middle-1;
				else if(prime[middle] < tmp)
					left = middle+1;
			}
			if(found)
			{
				printf("%d = %d + %d\n", num, prime[i], prime[middle]);
				break;
			}
		}	
		if(!found)
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}