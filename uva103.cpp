#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 1000000

struct Item
{
	int num;
	vector<int> ve;
};
int n, m;
Item v[maxn];

bool cmp(Item a, Item b)
{
	if(a.ve.back() == b.ve.back())
		return a.ve[0] < b.ve[0];
	return a.ve.back() < b.ve.back();
}

bool check(int a, int b) //前大後小
{
	for(int i = 0; i < m; i++)
	{
		if(v[b].ve[i] > v[a].ve[i])
			return false;
	}
	return true;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif


	while(~scanf("%d %d", &n, &m))
	{

		for(int i = 0; i < n; i++)
		{
			v[i].ve.clear();
			v[i].num = i+1;

			for(int k = 0; k < m; k++)
			{
				int tmp;
				scanf("%d", &tmp);
				v[i].ve.PB(tmp);
			}
			sort(v[i].ve.begin(), v[i].ve.end());
		}

		sort(v, v+n, cmp);


		for(int i = 0; i < n; i++)
		{
			cout << v[i].num << ": ";
			for(int k = 0; k < m; k++)
			{
				cout << v[i].ve[k] << ' ';
			}
			cout << endl;
		}
		cout << endl;


		int lis[maxn];
		fill(lis, lis+n, -1);

		int top = 0;

		lis[top] = 0;


			for(int i = 1; i < n; i++)
			{
				int left = 0, right = top;
				bool found = false;

				for(int l = 0; l <= top; l++)
				{
					if(check(lis[l],i))
					{
						if(l <= top)
						{
							if(!check(i, lis[l-1]))
								continue;
						}
						lis[l] = i;
						found = true;
						break;
					}
				}

				if(!found)
				{
					if(check(i, lis[top]))
					{
						top++;
						lis[top] = i;
					}
				}
				for(int i = 0; i <= top; i++)
				{
					cout << v[lis[i]].num << ' ';
				}
				cout << endl;
			}
		

		cout << top+1 << endl;
		for(int i = 0; i <= top; i++)
		{
			cout << v[lis[i]].num << ' ';
		}
		cout << endl;
	}

	return 0;
}