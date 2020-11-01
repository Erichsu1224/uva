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
string name;
int r, c;
int maxx;
int fig[maxn][maxn];
vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
//functions

void dfs(int x, int y, int depth){
	maxx = max(maxx, depth);

	for(int i = 0; i < 4; i++){
		if(fig[x+dir[i][0]][y+dir[i][1]] < fig[x][y]){
			dfs(x+dir[i][0], y+dir[i][1], depth+1);
		}
	}
}

int main(void)
{
	int T;
	cin >> T;

	while(T--){
		cin >> name >> r >> c;

		maxx = 0;

		REP(i, 0, r+1)
			REP(j, 0, c+1)
				fig[i][j] = 1e9;

		REP(i, 1, r)
			REP(j, 1, c)
				cin >> fig[i][j];
		REP(i, 1, r)
			REP(j, 1, c)
				dfs(i, j, 1);

		cout << name << ": " << maxx << '\n';
	}

	return 0;
}