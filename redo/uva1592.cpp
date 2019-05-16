#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 10000+5
#define maxm 10+5

string s[maxn][maxm];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int col, row;

	while(~scanf("%d %d", &row, &col))
	{
		set<int> st;
		map<int,int> m;
		map<int,vector<int> > m2;
		getchar();
		for(int i = 0; i < row; i++)
		{
			string tmp;
			getline(cin, tmp);
			int cur = 0, next;
			for(int j = 0; j < col; j++)
			{
				next = tmp.find_first_of(",", cur);
				s[i][j] = tmp.substr(cur, next-cur);
				cur = next+1;
			}
		}

		//test
		/*
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				cout << s[i][j] << '|';
			}
			cout << endl;
		}
		*/

		bool check = false;
		
		for(int j = 0; j < row; j++)
		{
			for(int k = j+1; k < row; k++)
			{
				for(int i = 0; i < col; i++)
				{
					//cout << s[j][i] << "  " << s[k][i] << endl;
					if(s[j][i] == s[k][i])
					{
						int hold = j*10000+k;
						//cout << st.count(hold) << endl;
						
						if(st.count(hold))
						{
							//m[hold]++;
							check = true;
							
							printf("NO\n");
							printf("%d %d\n", hold/10000+1, hold%10000+1);
							printf("%d %d\n", m[hold]+1, i+1);
							
							break;
							//m2[hold].PB(i);
						}
						else
						{
							st.insert(hold);
							m[hold] = i;
							//m2[hold].PB(i);
						}
					}
				}
				if(check)
					break;
			}
			if(check)
				break;
		}

/*
		set<int>::iterator it;
		for(it = st.begin(); it != st.end(); it++)
		{
			if(m[*it] == 2)
			{
				check = true;
				cout << "NO\n";
				cout << *it/10000+1 << ' ' << *it%10000+1 << endl;
				cout << m2[*it][0]+1 << ' ' << m2[*it][1]+1 << endl;
				break;
			}
		}
*/
		if(!check)
			cout << "YES\n";
	}
	return 0;
}