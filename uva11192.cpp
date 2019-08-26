#include <iostream>
using namespace std;

int main(void)
{
	int n;
	string str;

	while(cin >> n && n)
	{
		cin >> str;

		n = str.size()/n;

		for(int i = 0; i < str.size(); i += n)
		{
			for(int j = 0; j < (n/2); j++)
			{
				swap(str[i+j], str[i-1+n-j]);
			}
		}

		cout << str << '\n';
	}
	return 0;
}