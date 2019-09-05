#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int n;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		float a, b;

		cin >> a >> b;

		printf("Case %d: %.2f\n", i, a+(b*5/9));	
	}
	return 0;
}