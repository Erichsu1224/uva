#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

//using set

set <string> dictionary;

int main(void)
{
	string str;

	while(cin >> str)	dictionary.insert(str);

	set <string>::iterator it;

	for(it = dictionary.begin(); it != dictionary.end(); it++)
	{
		str = *it;
		for(int i = 0; i < str.size(); i++)
		{
			string sub1 = str.substr(0, i+1);
			string sub2 = str.substr(i+1, str.size()-(i+1));
			if(dictionary.find(sub1) != dictionary.end() && dictionary.find(sub2) != dictionary.end())
			{
				cout << str.c_str() << endl;
			}
		}
	}
	return 0;
}