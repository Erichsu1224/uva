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
#define maxn 300+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure
struct Edge
{
    int v, a, b, t;
    Edge(int v, int a, int b, int t):v(v),a(a),b(b),t(t){}
};

struct Item
{
    int cost, now;

    Item(int cost, int now):cost(cost), now(now){}

    bool operator<(const Item& rs) const
    {
        return cost > rs.cost;
    }
};
//declaration
int n, m ,s, t;
vector<Edge> G[maxn];
bool vis[maxn];
//functions
int Dijkstra(void)
{
    MSET(vis, false);
    int time = 0;

    priority_queue<Item> q;

    q.push(Item(time, s));

    while(!q.empty())
    {
        Item tmp = q.top(); q.pop();
        time = tmp.cost;

        // cout << tmp.now << ' ' << tmp.cost << endl;

        if(vis[tmp.now])
            continue;

        if(tmp.now == t)
        {
            return tmp.cost;
        }

        vis[tmp.now] = true;
            

        for(int i = 0; i < G[tmp.now].size(); i++)
        {
            Edge ee = G[tmp.now][i];
            int cnt = time/(ee.a+ee.b);

            if(ee.a < ee.t)
                continue;
            if(time+ee.t > cnt*(ee.a+ee.b)+ee.a)
                cnt = (cnt+1)*(ee.a+ee.b)+ee.t;
            else
                cnt = time+ee.t;
            // if((time%(ee.a+ee.b))+ee.t <= ee.a)
            // {
            //     cnt = time+ee.t;
            // }
                
            // else
            // {
            //     // if(ee.t > time+(ee.a+ee.b)-time%(ee.a+ee.b)+ee.t)
            //     cnt = time+(ee.a+ee.b)-(time%(ee.a+ee.b))+ee.t;

            // }

            q.push(Item(cnt, ee.v));
        }
    }

    return -1;
}
int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;
    int cases = 1;

    while(cin >> n >> m >> s >> t)
    {
        //init
        REP(i, 0, n)
            G[i].clear();
        int a, b, c, d, e;

        REP(i, 1, m)
        {
            cin >> a >> b >> c >> d >> e;
            G[a].EB(Edge(b, c, d, e));
        }

        cout << "Case " << cases++ << ": " << Dijkstra() << '\n';
    }

	return 0;
}