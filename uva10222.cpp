#include <iostream>
#include <map>
using namespace std;

string code = "1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./";
map<char, char> m;
int main(void)
{
	for(int i = 2; i < code.size(); i++)
	{
		m[code[i]] = m[code[i-2]];
	}
	m[' '] = ' ';

	string str;

	while(getline(cin, str))
	{
		cout << str << endl;
		
		for(int i = 0; i < str.size(); i++)
		{
			cout << m[str[i]];
		}
		cout << '\n';
	}
	return 0;
}