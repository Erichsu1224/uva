#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 105

int morning[maxn];
int evening[maxn];


int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n, d, r;
	int total;

	while(~scanf("%d %d %d", &n, &d, &r) && (n != 0 || d != 0 || r != 0))
	{
		total = 0;

		for(int i = 0; i < n; i++)
			scanf("%d", &morning[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &evening[i]);

		sort(morning, morning+n);
		sort(evening, evening+n);

		for(int i = 0; i < n; i++)
		{
			if(morning[i] + evening[n-i-1] > d)
				total += (morning[i]+evening[n-i-1]-d);
		}

		printf("%d\n", total*r);
	}

	return 0;
}