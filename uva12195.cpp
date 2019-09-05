#include <iostream>
using namespace std;

float change(char a)
{
	if(a == 'W')
		return 1;
	if(a == 'H')
		return 0.5;
	if(a == 'Q')
		return 0.25;
	if(a == 'E')
		return 0.125;
	if(a == 'S')
		return 0.0625;
	if(a == 'T')
		return 0.03125;
	if(a == 'X')
		return 0.015625;
	else
		return 0;	
}

int main(void)
{
	string in;

	while(cin >> in)
	{
		int counter = 0;
		float tmp = 0.0;
		if(in[0] == '*')
			break;

		for(int i = 1; i < in.size(); i++)
		{
			if(in[i] == '/')
			{
				if(tmp == 1)
					counter++;
				tmp = 0;
				continue;
			}
			tmp += change(in[i]);
		}

		cout << counter << '\n';
	}
	return 0;
}