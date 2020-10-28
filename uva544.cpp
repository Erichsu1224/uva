#include <bits/stdc++.h>
using namespace std;

#define maxn 205

struct Edge
{
	int v, weight;

	bool operator< (const Edge& rs) const{
		return weight < rs.weight;
	}
};

int n, m;
int cnt = 1, target, w;
string x;
string y;
map<string, int> mp;
vector<pair<int, int>> g[maxn];
bool vis[maxn];

int get_idx(string a){
	if(!mp[a])
		mp[a] = cnt++;
	return mp[a];
}

int dijk(int st){

	memset(vis, false, sizeof(vis));
	priority_queue<Edge> q;
	q.push((Edge){st, 10000000});

	while(!q.empty()){
		auto now = q.top(); q.pop();
		
		vis[now.v] = true;

		if(now.v == target){
			return now.weight;
		}

		for(auto i : g[now.v]){
			if(!vis[i.first])
				q.push((Edge){i.first, min(now.weight, i.second)});
		}
	}
}

int main(void){

	int cases = 1;

	while(cin >> n >> m){
		if(n == 0 && m == 0)
			break;
		cnt = 1;
		mp.clear();
		for(int i = 0; i <= n; i++)
			g[i].clear();

		for(int i = 0; i < m; i++){
			cin >> x >> y >> w;
			g[get_idx(x)].emplace_back(make_pair(get_idx(y), w));
			g[get_idx(y)].emplace_back(make_pair(get_idx(x), w));
		}

		cin >> x >> y;

		target = get_idx(y);

		cout << "Scenario #" << cases++ << '\n';
		cout << dijk(get_idx(x)) << " tons\n\n";
	}

	return 0;
}