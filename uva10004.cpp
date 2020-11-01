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
#define maxn 205
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n, m, x ,y;
vector<int> g[maxn];
int vis[maxn];
bool color[5];
//functions

bool check(int v, int c){
	for(auto i : g[v])
		if(vis[i] == c)
			return false;
	return true;
}

bool dfs(int now, int depth){

	// cout << "---------------\n";
	// cout << now << ' ' << depth << '\n';

	if(depth == n)
		return true;

	

	for(auto i : g[now]){
		// cout << i << '\n';
		
		if(vis[i] == 0){
			if(vis[now] == 2){
				if(!check(i, 1))
					return false;
				vis[i] = 1;
			}

			else if(vis[now] == 1){
				if(!check(i, 2))
					return false;
				vis[i] = 2;
			}

			dfs(i, depth+1); 
		}
	}
	return true;
}

int main(void)
{
	while(cin >> n && n){
		cin >> m;

		REP(i, 0, n)
			g[i].clear();

		REP(i, 1, m){
			cin >> x >> y;
			g[x].EB(y);
			g[y].EB(x);
		}

		memset(vis, 0, sizeof(vis));

		vis[0] = 1;

		if(dfs(0, 1)){
			cout << "BICOLORABLE.\n";
		}
		else{
			cout << "NOT BICOLORABLE.\n";
		}
	}

	return 0;
}