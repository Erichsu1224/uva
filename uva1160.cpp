#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 100005

int set[maxn];

//disjoint set

void find(int x)
{
	return x:find(x);	
}	

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int a, b;
	int compounds = 0, pairs = 0;
	int error = 0;


	memset(set, 0, sizeof(set));

	while(~scanf("%d", &a))
	{
		if(a == -1)
		{
			printf("%d\n", error);
			compounds = 0, pairs = 0;
			error = 0;
			memset(set, 0, sizeof(set));
			continue;
		}

		scanf("%d", &b);

		int note_a = 0, note_b = 0;
		pairs++;
		if(set[a] == 0)
		{
			note_a = 1;
			compounds++;
		}
		if(set[b] == 0)
		{
			note_b = 1;
			compounds++;
		}

		if(pairs == compounds)
		{
			pairs--;
			if(note_a == 1)
				compounds--;
			if(note_b == 1)
				compounds--;
			error++;
			continue;
		}
		set[a] = 1;
		set[b] = 1;
	}

	return 0;
}
