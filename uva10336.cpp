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
#define maxn 1000
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int T, n, m;
char fig[1000][1000];
int dir[4][2] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1} };
bool vis[maxn][maxn];
map<char, int> mp;
//functions

void dfs(int x, int y){
	vis[x][y] = true;

	for(int i = 0; i < 4; i++){
		if(x+dir[i][0] > 0 && x+dir[i][0] <= n && y+dir[i][1] > 0 && y+dir[i][1] <= m){
			if(fig[x][y] == fig[x+dir[i][0]][y+dir[i][1]] && !vis[x+dir[i][0]][y+dir[i][1]]){
				dfs(x+dir[i][0], y+dir[i][1]);
			}
		}
	}
}

bool cmp(pair<char, int> a, pair<char, int> b){
	if(a.S == b.S)
		return a.F < b.F;
	else
		return a.S > b.S;
}

int main(void)
{
	cin >> T;

	int cases = 1;

	while(T--){
		scanf("%d %d\n", &n, &m);
		mp.clear();

		REP(i, 1, n){
			REP(j, 1, m){
				cin >> fig[i][j];
			}
		}

		MSET(vis, false);

		REP(i, 1, n){
			REP(j, 1, m){
				if(!vis[i][j]){
					mp[fig[i][j]]++;
					dfs(i, j);
				}
			}
		}

		vector<pair<char, int>> v;

		for(auto i : mp){
			v.EB(MP(i.F, i.S));
		}

		sort(v.begin(), v.end(), cmp);

		cout << "World #" << cases++ << '\n';

		for(auto i : v){
			cout << i.F << ": " << i.S << '\n';
		}
	}

	return 0;
}