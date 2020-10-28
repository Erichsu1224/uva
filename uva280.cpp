#include <bits/stdc++.h>
using namespace std;

#define maxn 105

bool g[maxn][maxn];


int main(void){

	int n, q;
	int x, y;

	while(cin >> n && n){

		memset(g, false, sizeof(g));

		while(cin >> x && x){
			while(cin >> y && y){
				g[x][y] = true;
			}
		}

		//bellman

		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(g[i][k] & g[k][j] == true)
						g[i][j] = g[i][k] & g[k][j];
				}
			}
		}


		cin >> q;
		vector<int> ans;

		for(int i = 0; i < q; i++){
			cin >> x;

			ans.clear();

			for(int j = 1; j <= n; j++){
				if(!g[x][j])
					ans.emplace_back(j);
			}

			cout << ans.size();
			for(auto j : ans)
				cout << ' ' << j;
			cout << endl;
		}

	}
	return 0;
}