#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

#define ll long long
#define C cases
#define pb push_back


int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;

	scanf("%d", &C);
	getchar();

	while(C--)
	{
		string str;
		stack<char> st;
		bool check = true;

		getline(cin , str);

		if(str == "\n")
		{
			printf("Yes\n");
			continue;
		}

		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == '(' || str[i] == '[')
				st.push(str[i]);

			else if(str[i] == ')')
			{
				if(!st.empty() && st.top() == '(')
				{
					st.pop();
					continue;
				}

				else
				{
					check = false;
					break;
				}
			}

			else if(str[i] == ']')
			{
				if(!st.empty() && st.top() == '[')
				{
					st.pop();
					continue;
				}

				else
				{
					check = false;
					break;
				}
			}
		}
		if(!st.empty())
			check = false;

		if(check)
			printf("Yes\n");
		if(!check)
			printf("No\n");
	}

	return 0;
}