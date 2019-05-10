#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	set<string> str;
	string tmp, hold;

	while(cin >> tmp)
	{
		for(int i = 0; i < tmp.size(); i++)
		{
			if(isalpha(tmp[i]))
			{
				if(isupper(tmp[i]))
					tmp[i] = tolower(tmp[i]);
			}
			else
				tmp[i] = ' ';
		}

		stringstream ss(tmp);

		while(ss >> hold)
		{
			str.insert(hold);
		}
	}

	for(set<string>::iterator it = str.begin(); it != str.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}