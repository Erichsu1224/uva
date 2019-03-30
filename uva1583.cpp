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

int list[110000] = {0};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	for(int i = 1; i <= 100000; i++)
	{
		int tmp = i;
		vector<int> digit;

		while(tmp >= 1)
		{
			digit.PB(tmp%10);
			tmp /= 10;
		}

		tmp = i;

		for(int k = 0; k < digit.size(); k++)
		{
			tmp += digit[k];
		}
		if(list[tmp] == 0)
			list[tmp] = i;
	}

	int C;

	scanf("%d", &C);

	while(C--)
	{
		int n;

		scanf("%d", &n);

		printf("%d\n", list[n]);
	}

	return 0;
}