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
#define maxn 10000+5

struct ant
{
	int id;
	int locate;
	int face;

	ant() {}
	ant(int id, int locate, int face) : id(id), locate(locate), face(face){}

	bool operator< (const ant& rs) const
	{
		return locate < rs.locate;
	}
};

ant before[maxn];
ant after[maxn];
int order[maxn];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int cases;
	scanf("%d", &cases);

	for(int o = 1; o <= cases; o++)
	{
		printf("Case #%d:\n", o);

		int L, T, n;

		scanf("%d %d %d", &L, &T, &n);

		int locate;
		char face;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %c", &locate, &face);
			int f;
			f = (face == 'R' ? 1 : -1);
			before[i] = ant(i, locate, f);
			after[i] = ant(0, locate+f*T, f);
		}

		sort(before, before+n);
		for(int i = 0; i < n; i++)
		{
			order[before[i].id] = i;
		}

		sort(after, after+n);
		for(int i = 0; i < n-1; i++)
		{
			if(after[i].locate == after[i+1].locate)
			{
				after[i].face = after[i+1].face = 0;
			}
		}

		for(int i = 0; i < n; i++)
		{
			int tmp = order[i];
			if(after[tmp].locate > L || after[tmp].locate < 0)
				printf("Fell off\n");
			else
			{
				printf("%d ", after[tmp].locate);
				if(after[tmp].face == 1)
					printf("R\n");
				else if(after[tmp].face == -1)
					printf("L\n");
				else
					printf("Turning\n");
			}
		}
		printf("\n");
	}

	return 0;
}