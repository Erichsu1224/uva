#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	string str, x, y;
	
	while(cin >> str)
	{
		set<string> ss;

		REP(i, 0, str.size()-1)
		{
			REP(j, 1, str.size())
			{
				x = y = str.substr(i, j);
				reverse(all(y));
				if(x == y)
					ss.emplace(x);
			}
		}
		cout << "The string '" << str << "' contains " << ss.size() << " palindromes.\n";
	}

	

	return 0;
}