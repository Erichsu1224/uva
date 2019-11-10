#include <stdio.h>
#include <math.h>


int T, ans;
unsigned long long n;

int main(void)
{
	scanf("%d", &T);

	while(T--)
	{
		scanf("%llu", &n);

		unsigned long long l = 0, r = sqrt(n);

		while(l < r)
		{
			unsigned long long mid = (l+r+1)/2;

			if((1+mid)*mid/2 > n)
			{
				r = mid-1;
			}

			else
				l = mid;
		}

		printf("%llu\n", l);
	}
}