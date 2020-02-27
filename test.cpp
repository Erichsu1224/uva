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
#define maxn 100000
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n;
char c;
int st[maxn];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	while(cin >> n)
	{
		bool ans = false;
		int total = 0, dep = 0;
		// stack<int> st;
		string num;
		bool flag = false;
		char c1, c2, c3;

		while(cin >> c)
		{
			if(c == ' ' || c == '\n')
				continue;
			
			if(c >= '0' && c <= '9' || c == '-')
			{
				flag = true;
				num += c;
			}

			if(c == '(')
			{
				if(flag)
				{
					// st.push(stoi(num));
					// total += st.top();
					st[dep] = stoi(num);

					num = "";
					// cout << "IN: " << st.top() << ' ' << total << '\n';
					flag = false;
				}
				dep++;
			}

			if(c == ')')
			{
				dep--;
				if(c1 == '(' && c2 == ')' && c3 == '(')
				{
					total = 0;
					REP(i, 1, dep)
						total += st[i];
					if(total == n)
						ans = true;
					// total -= st.top();
					// st.pop();
				}
				else if(c2 == '(' && c3 == ')')
				{
					// total -= st.top();
					// st.pop();
				}
			}
				

			c1 = c2;
			c2 = c3;
			c3 = c;

			if(dep == 0)
				break;
		}

		if(ans)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	

	return 0;
}