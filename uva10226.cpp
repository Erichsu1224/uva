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

	// IOS;

	int n, total;
	string str;

	while(cin >> n)
	{
		getline(cin, str);
		getline(cin, str);

		REP(i, 1, n)
		{
			if(i > 1)
				cout << '\n';
			map<string, int> mp;
			total = 0;

			while(getline(cin, str))
			{
				if(str == "")
					break;

				mp[str]++;
				total++;
			}

			for(auto i : mp)
			{
				cout << i.F;
				printf(" %.4f\n", float(i.S)/total*100);
			}
		}
			
	}

	return 0;
}