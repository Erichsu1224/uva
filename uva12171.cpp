#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxm 1000+1
#define maxn 50+5


struct Item
{
	int x, y, z;

	Item(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

int n;
int counter;
int nx, ny, nz;
int x0[maxn], y0[maxn], z0[maxn], x1[maxn], y1[maxn], z1[maxn];
//被離散化座標
int x_d[maxn*2], y_d[maxn*2], z_d[maxn*2];
int color[maxn*2][maxn*2][maxn*2];
//Item graph[1000];

//1.離散化
//2.floodfill (dfs or bfs). 在外面加一個虛擬的牆

void discretization(int* d, int& n)
{
	sort(d, d+n);
	n = (int)(unique(d, d+n) - d);
}

void floodfill(void)
{
	//bfs
	counter = 0;

	queue<Item> q;
	q.push(Item(x_d[1], y_d[1], z_d[1]));

	while(!q.empty())
	{
		Item tmp = q.front();
		q.pop();
		color[tmp.x][tmp.y][tmp.z] = 2;
		counter++;

		//檢查 上下左右前後
		if(color[tmp.x+1][tmp.y][tmp.z] == 1)
			q.push(color[tmp.x+1][tmp.y][tmp.z]);
		if(color[tmp.x][tmp.y+1][tmp.z] == 1)
			q.push(color[tmp.x][tmp.y+1][tmp.z]);
		if(color[tmp.x][tmp.y][tmp.z+1] == 1)
			q.push(color[tmp.x][tmp.y][tmp.z+1]);
		if(color[tmp.x-1][tmp.y][tmp.z] == 1)
			q.push(color[tmp.x-1][tmp.y][tmp.z]);
		if(color[tmp.x][tmp.y-1][tmp.z] == 1)
			q.push(color[tmp.x][tmp.y-1][tmp.z]);
		if(color[tmp.x][tmp.y][tmp.z-1] == 1)
			q.push(color[tmp.x][tmp.y][tmp.z-1]);

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

	int C;
	scanf("%d", &C);

	while(C--)
	{
		scanf("%d", &n);

		//先存入邊界座標
		x_d[0] = y_d[0] = z_d[0] = 0;
		x_d[1] = y_d[1] = z_d[1] = maxm;
		nx = ny = nz = 2;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &x0[i], &y0[i], &z0[i]);
			scanf("%d %d %d", &x1[i], &y1[i], &z1[i]);
			x1[i] += x0[i];
			y1[i] += y0[i];
			z1[i] += z0[i];

			x_d[nx++] = x0[i];	x_d[nx++] = x1[i];
			y_d[ny++] = y0[i];	y_d[ny++] = y1[i];
			z_d[nz++] = z0[i]; 	z_d[nz++] = z1[i];
		}

		discretization(x_d, nx),
		discretization(y_d, ny),
		discretization(z_d, nz);

		memset(color, 0, sizeof(color));

		//開始染色
		for(int i = 0; i < n; i++)
		{
			int X1 = (int)(lower_bound(x_d, x_d+nx, x0[i]) - x_d);
			int Y1 = (int)(lower_bound(y_d, y_d+ny, y0[i]) - y_d);
			int Z1 = (int)(lower_bound(z_d, z_d+nz, z0[i]) - z_d);
			int X2 = (int)(lower_bound(x_d, x_d+nx, x1[i]) - x_d);
			int Y2 = (int)(lower_bound(y_d, y_d+ny, y1[i]) - y_d);
			int Z2 = (int)(lower_bound(z_d, z_d+nz, z1[i]) - z_d);

			for(int a = X1; a < X2; a++)
			{
				for(int b = Y1; b < Y2; b++)
				{
					for(int c = Z1; c < Z2; c++)
					{
						printf("%d %d %d\n", a, b, c);
						color[a][b][c] = 1;
					}
				}
			}
		}

		//test
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				for(int l = 0; l < 10; l++)
				{
					cout << color[i][j][l] << ' ';
				}
				cout << endl;
			}

			cout << endl;
		}

		floodfill();
		cout << counter << endl;
	}

	return 0;
}