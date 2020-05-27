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
#define IOS 

//structure
template <typename T>
struct Dinic
{
    int n, s, t, level[maxn], now[maxn];
    struct Edge
    {
        int v;
        T rf; // rf: residual flow
        int re;
    };
    vector<Edge> e[maxn];
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
        e[v].push_back({u, f, (int)e[u].size() - 1});
        // for directional graph
        // e[v].push_back({u, 0, (int)e[u].size() - 1});
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
                tmp = dfs(s, 0x3f3f3f3f);
                res += tmp;
            }while(tmp);
        }
        return res;
    }
};

int cases, n, m, k, cnt;
string x, y;
map<string, int> mp;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	cin >> cases;

	while(cases--){
		cin >> n;
		cnt = 0;
		mp.clear();
		Dinic<int> dinic;
		dinic.init(505, 500, 501);		

		REP(i, 1, n){
			cin >> x;
			if(!mp[x])
				mp[x] = cnt++;
			
			dinic.add_edge(mp[x], 501, 1);
		}

		cin >> m;

		REP(i, 1, m){
			cin >> x >> y;

			if(!mp[x])
				mp[x] = cnt++;
			if(!mp[y])
				mp[y] = cnt++;

			dinic.add_edge(500, mp[y], 1);
			// dinic.add_edge(mp[x], mp[y], 1);
		}

		cin >> k;

		REP(i, 1, k){
			cin >> x >> y;
			if(!mp[x])
				mp[x] = cnt++;
			if(!mp[y])
				mp[y] = cnt++;
			dinic.add_edge(mp[x], mp[y], 1e9);
		}

		cout << m-dinic.flow() << '\n';
		if(cases)
			cout << '\n';
	}

	return 0;
}