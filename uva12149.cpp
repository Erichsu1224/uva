#include <iostream>
using namespace std;

int main(void)
{
	int n;
	long long dp[105];

	dp[0] = 0;

	for(int i = 1; i <= 100; i++)
	{
		dp[i] = dp[i-1]+(i*i);
	}

	while(cin >> n && n)
	{
		cout << dp[n] << '\n';
	}

	return 0;
}