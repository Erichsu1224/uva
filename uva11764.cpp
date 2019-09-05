#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for(int k = 1; k <= T; k++)
	{
		int n;
		int tmp;
		int high = 0, low = 0;

		cin >> n;

		for(int i = 0; i < n; i++)
		{
			int hold;

			cin >> hold;

			if(!i)
			{
				tmp = hold;
				continue;
			}

			if(hold-tmp > 0)
				high++;
			else if(hold-tmp < 0)
				low++;
			tmp = hold;
		}

		cout << "Case " << k << ": " << high << " " << low << "\n";
	}
	return 0;
}