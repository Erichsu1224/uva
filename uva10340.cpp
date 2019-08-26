#include <iostream>
using namespace std;

int main(void)
{
	string a, b;

	while(cin >> a >> b)
	{
		int tmp = 0;
		for(int i = 0; i < b.size(); i++)
		{
			if(b[i] == a[tmp])
				tmp++;
			if(tmp == a.size())		break;
		}

		if(tmp == a.size())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}