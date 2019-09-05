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
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define all(x) x.begin(), x.end()
#define maxn 1000+5

//structure

//declaration
pair<int, int> vote[maxn];
//functions
bool cmp(PP a, PP b)
{
	return a.first > b.first;
}

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int T;	cin >> T;

	while(T--)
	{
		int n; cin >> n;
		
		//init
		for(int i = 0; i <= n; i++)
		{
			vote[i].first = 0;
			vote[i].second = i;
		}

		for(int i = 0; i < n; i++)
		{
			int tmp;	cin >> tmp;
			vote[tmp].first++;
		}

		sort(vote, vote+(n+1), cmp);

		if(vote[0].first <= n/2)
		{
			cout << -1 << '\n';
			continue;
		}
		cout << vote[0].second << '\n';
	}

	return 0;
}