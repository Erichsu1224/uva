#include <iostream>
using namespace std;

int main(void)
{
	int n;	cin >> n;

	while(n--)
	{
		string in;

		cin >> in;

		if(in.size() == 3)
		{
			int wrong = 0;

			if(in[0] != 'o')
				wrong++;
			if(in[1] != 'n')
				wrong++;
			if(in[2] != 'e')
				wrong++;

			if(wrong <= 1)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';

		}

		else
		{
			cout << 3 << '\n';
		}
	}
	return 0;
}