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


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	vector<int> v;

	int n;
	while(~scanf("%d", &n))
	{
		v.PB(n);
	}

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;

	int top = 1;
	int lis[v.size()+5];
	fill(lis, lis+(v.size()+5), -1);

	for(int i = 0; i < v.size(); i++)
	{
		//if(v[i]>)
	}
	return 0;
}