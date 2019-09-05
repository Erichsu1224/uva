#include <iostream>
using namespace std;

int main(void)
{
	cout << "Lumberjacks:\n";

	int n; cin >> n;

	while(n--)
	{
		bool check_up = true, check_down = true;
		int tmp, beer;

		cin >> beer;

		tmp = beer;
		for(int i = 1; i < 10; i++)
		{
			cin >> beer;

			if(beer - tmp < 0)
			{
				check_up = false;
			}

			if(beer - tmp > 0)
			{
				check_down = false;
			}

			tmp = beer;
		}

		if(check_up || check_down)
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
	}
	return 0;
}