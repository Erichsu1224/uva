#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn 35
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure
struct Item{
	int x, y, z, t;
};
//declaration
int n, m, q;
char fig[maxn][maxn][maxn];
int s_x, s_y, s_z, e_x, e_y, e_z;
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
bool vis[maxn][maxn][maxn];
//functions

int bfs(int x, int y, int z){

	queue<Item> qq;

	qq.push((Item){x, y, z, 0});

	while(!qq.empty()){
		auto now = qq.front();	qq.pop();

		if(vis[now.x][now.y][now.z])
			continue;

		// cout << now.x << ' ' << now.y << ' ' << now.z << ' ' << now.t << '\n';

		vis[now.x][now.y][now.z] = true;

		if(now.x == e_x && now.y == e_y && now.z == e_z){
			return now.t;
		}

		x = now.x;
		y = now.y;
		z = now.z;

		for(int i = 0; i < 6; i++){
			if(fig[x+dir[i][0]][y+dir[i][1]][z+dir[i][2]] != '#' && !vis[x+dir[i][0]][y+dir[i][1]][z+dir[i][2]]){
				qq.push((Item){x+dir[i][0], y+dir[i][1], z+dir[i][2], now.t+1}); 				
			}

		}
	}

	return -1;
}

int main(void)
{
	while(~scanf("%d %d %d\n", &n, &m, &q)){
		if(n == 0 && m == 0 && q == 0)
			break;

		MSET(fig, '#');

		REP(i, 1, n){
			REP(j, 1, m){
				REP(k, 1, q){
					cin >> fig[i][j][k];
					if(fig[i][j][k] == 'S'){
						s_x = i;
						s_y = j;
						s_z = k;
					}
					if(fig[i][j][k] == 'E'){
						e_x = i;
						e_y = j;
						e_z = k;
					}
				}
			}
		}

		MSET(vis, false);
		int ans = bfs(s_x, s_y, s_z);

		if(ans == -1)
			cout << "Trapped!\n";
		else{
			cout << "Escaped in " << ans << " minute(s).\n";
		}
	}

	return 0;
}