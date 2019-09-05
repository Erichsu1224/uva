#include <iostream>
using namespace std;

#define ll long long

int main(void)
{
	int n;

	while(cin >> n && n)
	{
		unsigned ll male = 1, female = 0;

		for(int i = 1; i <= n; i++)
		{
			ll a = male, b = female;

			male = b;
			female = a+b;
		}

		cout << male+female << '\n';
	}
	return 0;
}