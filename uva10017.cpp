#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define A 0
#define B 1
#define C 2

vector<int> towel[3];
int step;
int in_n, in_m;

void print_status(void)
{
	if(step > in_m)	return;
	for(int i = A; i <= C; i++)
	{
		printf("%c=>", (char)('A' + i));
		if(towel[i].empty())
		{
			printf("\n");
			continue;
		}
		printf("   ");
		for(int n = 0; n < towel[i].size(); n++)
		{
			if(n < towel[i].size()-1)
				printf("%d ", towel[i][n]);
			else
				printf("%d\n", towel[i][n]);
		}
	}
	printf("\n");
	step++;
}

void move(int n, int from, int tmp, int to)
{
	towel[to].PB(towel[from].back());
	towel[from].pop_back();
	print_status();
}

void hanoi(int n, int from, int tmp, int to)
{
	if(step > in_m)	return;
	if(n == 1)
	{
		move(n, from, tmp, to);
		return;
	}
	else
	{
		hanoi(n-1, from, to, tmp);
		move(n, from, tmp, to);
		hanoi(n-1, tmp, from, to);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int cases = 1;

	while(~scanf("%d %d", &in_n, &in_m) && (in_n||in_m))
	{
		step = 0;
		towel[A].clear();
		towel[B].clear();
		towel[C].clear();

		for(int i = in_n; i >= 1; i--)
		{
			towel[A].PB(i);
		}

		printf("Problem #%d\n\n", cases++);
		print_status();
		hanoi(in_n, A, B, C);
	}
	return 0;
}
