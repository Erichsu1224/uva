#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn 50005

//structure
struct Edge
{
    int t, f, w;

    bool operator< (const Edge& rs)const
    {
        return w < rs.w;
    }
};
//declaration
int n, m, q;
vector<Edge> edges;
int parent_arr[maxn];
int maxx;
bool vis[maxn];
vector<pair<int, int> > g[maxn];
//functions
int find(int x)
{
    return parent_arr[x] < 0 ? x : (parent_arr[x] = find(parent_arr[x]));
}

void conn(int x, int y)
{
    parent_arr[find(y)] = find(x);
}

void dfs(int now, int ed, int dis)
{
    vis[now] = true;

    for(auto i : g[now])
    {
        if(!vis[i.F])
        {
            if(i.F == ed)
                maxx = max(maxx, max(dis, i.S));
            else
                dfs(i.F, ed, max(dis, i.S));
        }
    }
}
int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int cases = 0;

    while(~scanf("%d %d", &n, &m))
    {
        if(cases++)
            printf("\n");
        
        edges.clear();

        int x, y, z;
        REP(i, 1, m)
        {
            scanf("%d %d %d", &x, &y, &z);
            edges.EB((Edge{x, y, z}));
        }

        sort(all(edges));

        MSET(parent_arr, -1);

        REP(i, 1, n)
            g[i].clear();

        for(int i = 0; i < edges.size(); i++)
        {
            Edge tmp = edges[i];

            if(find(tmp.t) != find(tmp.f))
            {
                g[tmp.t].EB(MP(tmp.f, tmp.w));
                g[tmp.f].EB(MP(tmp.t, tmp.w));
                conn(tmp.f, tmp.t);
            }
        }

        scanf("%d", &q);

        REP(i, 1, q)
        {
            scanf("%d %d", &x, &y);
            MSET(vis, false);

            maxx = -1e9;
            dfs(x, y, -1e9);

            printf("%d\n", maxx);
        }
    }

	return 0;
}