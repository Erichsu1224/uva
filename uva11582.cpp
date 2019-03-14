#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int fibo[1000];

int main(void)
{
	//fibo
	for(int i = 0; i < 50; i++)
	{
		if(i == 0)	fibo[i] = 0;
		if(i == 1)	fibo[i] = 1;

		else	fibo[i] = fibo[i-1] + fibo[i-2];
	}

	int cases;

	scanf("%d", &cases);

	while(cases--)
	{
		unsigned long long a, b;
		int mod;
		vector<int> lis;

		scanf("%lld %lld %d", &a, &b, &mod);

		for(int i = 0; i < 50; i++)
		{
			lis.push_back(fibo[i] % mod);

			if(lis[i] == 0 && lis[i-1] == 1)
				break;
		}

		cout << lis[pow(a%mod, b) % mod] << endl;
	}
	return 0;
}