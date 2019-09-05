#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	string in;
	char a, b, c;
	int num;

	int T;

	cin >> T;

	while(T--)
	{
		cin >> in;
		a = in[0];
		b = in[1];
		c = in[2];

		num = (in[4]-'0')*1000 + (in[5]-'0')*100 + (in[6]-'0')*10 + (in[7]-'0');

		int ans = int(a-'A')*676+int(b-'A')*26+int(c-'A');

		if(abs(ans-num) <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";

	}
	return 0;
}