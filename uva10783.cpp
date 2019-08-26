#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for(int j = 1; j <= T; j++)
	{
		int a, b;	cin >> a >> b;
		int total = 0;

		for(int i = a; i <= b; i++)
		{
			if(i%2 == 1)
				total += i;
		}

		cout << "Case " << j <<": " << total << '\n';
	}
	return 0;
}