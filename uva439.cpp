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
#define maxn
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
char xx, xxx;
int s_x, s_y, e_x, e_y;
int vis[10][10];
int ans;
int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

//functions
int bfs(int x, int y){

	// cout << x << ' ' << y << '\n';

	queue<pair<pair<int, int>, int>> q;

	q.push(MP(MP(x, y), 0));

	while(!q.empty()){
		auto now = q.front();	q.pop();

		vis[now.F.F][now.F.S] = true;

		if(now.F.F == e_x && now.F.S == e_y){
			return now.S;
		}

		x = now.F.F;
		y = now.F.S;

		for(int i = 0; i < 8; i++){
			if(x+dir[i][0] > 0 && x+dir[i][0] <= 8 && y+dir[i][1] > 0 && y+dir[i][1] <= 8 && !vis[x+dir[i][0]][y+dir[i][1]]){
				q.push(MP(MP(x+dir[i][0], y+dir[i][1]), now.S+1)); 				
			}

		}
	}

	return false;
}

int main(void)
{
	while(~scanf("%c%d %c%d\n", &xx, &s_y, &xxx, &e_y)){
		s_x = xx-'a'+1;
		e_x = xxx-'a'+1;

		MSET(vis, 0);
		
		printf("To get from %c%d to %c%d takes %d knight moves.\n", xx, s_y, xxx, e_y, bfs(s_x, s_y));
	}

	return 0;
}