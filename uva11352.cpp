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
#define maxn 105
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int T, n, m;
char fig[maxn][maxn];
int s_x, s_y, e_x, e_y;
bool vis[maxn][maxn];
bool visible[maxn][maxn];
int dir[8][2] = {{-1, -1}, {1, 1}, {-1, 1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}};
int dir_k[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
//functions

void check(int x, int y){
	
	visible[x][y] = false;

	for(int i = 0; i < 8; i++){
		visible[x+dir_k[i][0]][y+dir_k[i][1]] = false;
	}
}

int bfs(int x, int y){

	queue<pair<pair<int, int>, int>> q;

	q.push(MP(MP(x, y), 0));

	while(!q.empty()){
		auto now = q.front();	q.pop();

		// cout << now.F.F << ' ' << now.F.S << '\n';
		
		vis[now.F.F][now.F.S] = true;

		if(now.F.F == e_x && now.F.S == e_y){
			return now.S;
		}

		x = now.F.F;
		y = now.F.S;

		for(int i = 0; i < 8; i++){
			if(visible[x+dir[i][0]][y+dir[i][1]] && !vis[x+dir[i][0]][y+dir[i][1]]){
				q.push(MP(MP(x+dir[i][0], y+dir[i][1]), now.S+1)); 				
			}

		}
	}

	return -1;
}


int main(void)
{
	cin >> T;

	while(T--){
		cin >> n >> m;

		MSET(fig, '.');
		MSET(visible, false);
		REP(i, 2, n+1)
			REP(j, 2, m+1)
				visible[i][j] = true;

		REP(i, 2, n+1)
			REP(j, 2, m+1){
				cin >> fig[i][j];
				
				if(fig[i][j] == 'A'){
					s_x = i;
					s_y = j;
				}
				if(fig[i][j] == 'B'){
					e_x = i;
					e_y = j;
				}
				if(fig[i][j] == 'Z')
					check(i, j);
			}

		visible[e_x][e_y] = true;

		MSET(vis, false);

		int ans = bfs(s_x, s_y);

		if(ans == -1)
			cout << "King Peter, you can't go now!\n";
		else
			cout << "Minimal possible length of a trip is " << ans << '\n'; 

	}

	return 0;
}