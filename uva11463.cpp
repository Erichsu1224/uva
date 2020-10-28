#include <bits/stdc++.h>
using namespace std;

#define maxn 105
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
int g[maxn][maxn];


int main(void){
	int T;
	int n, m, cases = 1;
	int x, y;
	cin >> T;

	while(T--){
		cin >> n >> m;

		REP(i, 0, n){
			REP(j, 0, n){
				if(i == j)
					g[i][j] = 0;
				else
					g[i][j] = 1e9;
			}
		}


		for(int i = 0; i < m; i++){
			cin >> x >> y;
			g[x][y] = g[y][x] = 1;
		}

		REP(k, 0, n-1)
			REP(i, 0, n-1)
				REP(j, 0, n-1)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

		int ans = 0;
		cin >> x >> y;

		REP(i, 0, n-1)
			ans = max(ans, g[x][i]+g[i][y]);

		cout << "Case " << cases++ << ": " << ans << '\n';
	}
}