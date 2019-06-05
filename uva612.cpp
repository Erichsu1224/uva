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
#define PP pair<int, int> z

struct Item
{
	int id;
	int weight;
	string str;

	bool operator<(const Item& rs)const
	{
		if(weight == rs.weight)
			return id < rs.id;
		return weight < rs.weight;
	}
};

int change(char a)
{
	if(a == 'A')
		return 1;
	else if(a == 'C')
		return 2;
	else if(a == 'G')
		return 3;
	else if(a == 'T')
		return 4;

	return 0;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;
	scanf("%d", &C);

	for(int T = 0; T < C; T++)
	{
		if(T)
			printf("\n");

		int n, m;
		vector<Item> v;

		scanf("%d %d\n", &n, &m);

		for(int i = 0; i < m; i++)
		{
			int total = 0;
			string tmp;

			getline(cin, tmp);

			for(int j = 0; j < n-1; j++)
			{
				for(int k = j+1; k < n; k++)
				{
					//cout << tmp[j] << tmp[k] << endl;
					if(change(tmp[j]) > change(tmp[k]))
						total++;
				}
			}

			v.PB((Item){i, total, tmp});
		}

		sort(v.begin(), v.end());

		for(int i = 0; i < m; i++)
		{
			cout << v[i].str << endl;
		}

	}

	return 0;
}