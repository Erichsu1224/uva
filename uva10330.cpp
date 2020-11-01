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
#define M 210
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

template <typename T>
struct Dinic
{
    int n, s, t, level[M], now[M];
    struct Edge
    {
        int v;
        T rf; // rf: residual flow
        int re;
    };
    vector<Edge> e[M];
    void init(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i <= n; i++)
        {
            e[i].clear();
        }
    }
    void add_edge(int u, int v, T f)
    {
    	
        e[u].push_back({v, f, (int)e[v].size()});
        
        // e[v].push_back({u, f, (int)e[u].size() - 1});
        // for directional graph
        e[v].push_back({u, 0, (int)e[u].size() - 1});
    }
    bool bfs()
    {
        fill(level, level + n + 1, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto it : e[u])
            {
                if (it.rf > 0 && level[it.v] == -1)
                {
                    level[it.v] = level[u] + 1;
                    q.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    T dfs(int u, T limit)
    {
        if (u == t)
            return limit;
        T res = 0;

        while (now[u] < (int)e[u].size())
        {
            Edge &it = e[u][now[u]];
            if (it.rf > 0 && level[it.v] == level[u] + 1)
            {
                T f = dfs(it.v, min(limit, it.rf));
                res += f;
                limit -= f;
                it.rf -= f;
                e[it.v][it.re].rf += f;
                if (limit == 0)
                {
                    return res;
                }
            }
            else
            {
                ++now[u];
            }
        }
        if (!res)
        {
            level[u] = -1;
        }
        return res;
    }
    T flow(T res = 0)
    {
        while (bfs())
        {
            T tmp;
            memset(now, 0, sizeof(now));
            do{
                tmp = dfs(s, 1e9);
                res += tmp;
            }while(tmp);
        }
        return res;
    }
};

//declaration
int n, m, a, b, x, y, z;

int main(void)
{
	while(cin >> n){
		Dinic<int> dinic;

		dinic.init(2*n+2, 2*n+1, 2*n+2);

		REP(i, 1, n){
			cin >> x;
			dinic.add_edge(i+n, i, x);
		}

		cin >> m;

		REP(i, 1, m){
			cin >> x >> y >> z;
			dinic.add_edge(x, y+n, z);
		}

		cin >> a >> b;

		REP(i, 1, a){
			cin >> x;
			dinic.add_edge(2*n+1, x+n, 1e9);
		}
		REP(i, 1, b){
			cin >> x;
			dinic.add_edge(x, 2*n+2, 1e9);
		}

		// for(int i = 1; i <= 2*n+2; i++){
		// 	for(auto j : dinic.e[i])
		// 		cout << j.v << ' ';
		// 	cout << '\n';
		// }

		cout << dinic.flow() << '\n';
	}



	return 0;
}