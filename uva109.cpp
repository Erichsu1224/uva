#include <iostream>
#include <cstdio>
using namespace std;

#define maxn 105

struct point
{
	int x, y;
};

point elec;
point build[maxn];

int main(void)
{
	int N;

	while(scanf("%d", &N))
	{
		if(N == -1)
			break;

		scanf("%d %d", &elec.x, &elec.y);

		for(int i = 0; i < N-1; i++)
		{
			scanf("%d %d", &build[i].x, &build[i].y);
		}

	}
	return 0;
}