#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	while(T--)
	{
		int n;
		long long total = 0;
		cin >> n;

		for(int i = 0; i < n; i++)
		{
			int a, b, c;

			cin >> a >> b >> c;

			total += a*c;
		}

		cout << total << '\n';
	}
	return 0;
}