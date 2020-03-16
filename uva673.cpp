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
int cases;
string str;

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	cin >> cases;
	getline(cin, str);
	while(cases--)
	{
		getline(cin, str);
		stack<char> ss;

		bool flag = true;

		for(auto i : str)
		{
			if(i == '(' || i == '[' || i == '{')
			{
				ss.push(i);
			}

			else
			{
				if(ss.empty())
				{
					flag = false;
					break;
				}

				if(i == ')')
				{
					if(ss.top() == '(')
						ss.pop();
					else
					{
						flag = false;
						break;
					}
				}

				if(i == '}')
				{
					if(ss.top() == '{')
						ss.pop();
					else
					{
						flag = false;
						break;
					}
				}

				if(i == ']')
				{
					if(ss.top() == '[')
						ss.pop();
					else
					{
						flag = false;
						break;
					}
				}
			}
		}

		if(!ss.empty())
			flag = false;
		
		if(flag)
			cout << "Yes\n";
		if(!flag)
			cout << "No\n";
	}

	return 0;
}