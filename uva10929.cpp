#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	string str;

	while(cin >> str)
	{
		if(str[0] == '0' && str.size() == 1)
			break;
		int odd = 0, even = 0;

		for(int i = 0; i < str.size(); i++)
		{
			if(i%2 == 0)
				even += str[i]-'0';
			else
				odd += str[i]-'0';
		}

		if(abs(even-odd)%11 == 0)
			cout << str << " is a multiple of 11.\n";
		else
			cout << str << " is not a multiple of 11.\n";
	}
	return 0;
}