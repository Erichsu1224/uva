#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define N 8

int queen[N], counter;
bool mx[N];
bool s1[15];
bool s2[15];

void init(int row, int col)
{
	memset(queen, -1, sizeof(queen));
	memset(mx, true, sizeof(mx));
	memset(s1, true, sizeof(s1));
	memset(s2, true, sizeof(s2));
	counter = 0;

	row--;
	col--;
	queen[col] = row;
	s1[row+col] = false;
	s2[row-col+7] = false;
	mx[row] = false;

	backtracking(0, 0); 

}

void backtracking(int row, int col)
{
	if(row == N)
	{
		printf("%2d     ", ++kind);
        for (int i = 0; i < N; i++)
            printf(" %d", ans[i] + 1);
        printf("\n");
        return;
    }

    
}


int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;

	scanf("%d", &C);

	for(int l = 0; l < C; l++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		init(x, y);
	}

	return 0;
}