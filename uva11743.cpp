#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	while(T--)
	{
		int odd = 0;
		int even = 0;
		for(int i = 0; i < 4; i++)
		{
			string tmp;

			cin >> tmp;

			for(int j = 0; j < 4; j++)
			{
				if(j%2 == 1)
				{
					odd += (tmp[j]-'0');
				}

				else
				{
					int hold = (tmp[j]-'0')*2;
					while(hold >= 1)
					{
						even += hold%10;
						hold /= 10;
					}
				}
			}
		}

		if((odd+even)%10 == 0)
			cout << "Valid\n";
		else
			cout << "Invalid\n";
	}

	return 0;
}