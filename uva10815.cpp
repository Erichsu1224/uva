#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure

//declaration
string in;
int next_s;
string tmp;
set<string> S;
vector<string> v;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(getline(cin, tmp))
	{
		for(int i = 0; i < tmp.size(); i++)
		{
			if(isalpha(tmp[i]))
			{
				if(isupper(tmp[i]))
				{
					tmp[i] = tolower(tmp[i]);
				}
			}

			else
				tmp[i] = ' ';
		}
		int current = 0;
		while (1)
		{
			next_s = tmp.find_first_of(" ", current);
			if (next_s != current)
			{
				string hold = tmp.substr(current, next_s - current);
				if (hold.size() != 0)
				{
					S.insert(hold);
				}
			}
			if (next_s == string::npos) break;
			current = next_s + 1;
		}
	}

	for(set<string>::iterator it = S.begin(); it != S.end(); it++)
	{
		v.PB(*it);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}