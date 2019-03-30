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


struct Item
{
	string country;
	int num;

	bool operator< (const Item&rs) const
	{
		return country < rs.country;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;
	vector<Item> v;

	scanf("%d", &C);

	for(int i = 0; i < C; i++)
	{
		string tmp;
		string trash;
		bool found = false;

		cin >> tmp;
		getline(cin, trash);

		for(int k = 0; k < v.size(); k++)
		{
			if(v[k].country == tmp)
			{
				v[k].num++;
				found = true;
				break;
			}
		}

		if(!found)
			v.PB((Item){tmp, 1});
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i].country << ' ' << v[i].num << endl;
	}

	return 0;
}