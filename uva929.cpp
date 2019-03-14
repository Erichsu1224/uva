#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define maxn 1000

int map[maxn][maxn];
int visit[maxn][maxn];

struct Item
{
	int row, col, dist;
	Item() {}
	Item(int row, int col, int dist) : row(row), col(col), dist(dist) {}

	bool operator < (const Item& rs) const
	{
		return dist > rs.dist;
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

	scanf("%d", &C);

	while(C--)
	{
		int col, row;
		priority_queue<Item> pq;

		memset(visit, -1, sizeof(visit));

		scanf("%d %d", &row, &col);

		for(int i = 1; i <= row; i++)
			for(int n = 1; n <= col; n++)
				scanf("%d", &map[i][n]);

		pq.push(Item(1, 1, map[1][1]));
		Item tmp;

		while(!pq.empty())
		{
			tmp = pq.top();
			pq.pop();

			if(visit[tmp.row][tmp.col] == 1)
				continue;

			visit[tmp.row][tmp.col] = 1;

			if(tmp.row == row && tmp.col == col)
				break;

			if(visit[tmp.row+1][tmp.col] != 1 && tmp.row+1 <= row)
				pq.push(Item(tmp.row+1, tmp.col, tmp.dist+map[tmp.row+1][tmp.col]));
			if(visit[tmp.row][tmp.col+1] != 1 && tmp.col+1 <= col)
				pq.push(Item(tmp.row, tmp.col+1, tmp.dist+map[tmp.row][tmp.col+1]));
			if(visit[tmp.row-1][tmp.col] != 1 && tmp.row-1 >= 1)
				pq.push(Item(tmp.row-1, tmp.col, tmp.dist+map[tmp.row-1][tmp.col]));
			if(visit[tmp.row][tmp.col-1] != 1 && tmp.col-1 >= 1)
				pq.push(Item(tmp.row, tmp.col-1, tmp.dist+map[tmp.row][tmp.col-1]));
		}

		printf("%d\n", tmp.dist);
	}

	return 0;
}