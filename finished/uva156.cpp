#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>

vector<string> str;
map<string, int> m;

string standard(string s)
{
	for(int i = 0; i < s.size(); i++)
	{
		if(isupper(s[i]))
			s[i] = tolower(s[i]);
	}

	sort(s.begin(), s.end());

	return s;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	string tmp;

	while(cin >> tmp)
	{
		if(tmp == "#")
			break;
		str.PB(tmp);

		string st = standard(tmp);

		if(!m.count(st))
			//m.insert(pair<string, int>(st, 1));
			m[st] = 0;
		m[st]++;
	}

	vector<string> ans;
	for(int i = 0; i < str.size(); i++)
	{
		if(m[standard(str[i])] == 1)
			ans.PB(str[i]);
	}

	sort(ans.begin(), ans.end());

	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}

	return 0;
}