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

/*
struct Item
{
	int x0, y0, z0;
	int x1, y1, z1;
};
*/

int n;
int nx, ny, nz;
int x0[maxn], y0[maxn], z0[maxn], x1[maxn], y1[maxn], z1[maxn];
//被離散化座標
int x_d[maxn*2], y_d[maxn*2], z_d[maxn*2];
//Item graph[1000];

//1.離散化
//2.floodfill (dfs or bfs). 在外面加一個虛擬的牆

void discretization(int* d, int& n)
{
	sort(d, d+n);
	n = (int)(unique(d, d+n) - d);
	cout << n << endl;
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

		for(int i = 0; i < (n+1)*2; i++)
		{
			printf("%d %d %d\n", x_d[i], y_d[i], z_d[i]);
		}
		cout << endl;

		discretization(x_d, nx);
		discretization(y_d, ny);
		discretization(z_d, nz);

		for(int i = 0; i < n+2; i++)
		{
			printf("%d %d %d\n", x_d[i], y_d[i], z_d[i]);
		}
		cout << endl;
	}

	return 0;
}