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
#define maxn 1000+5
#define maxm 8+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure
struct Edge
{
    int f, t;
    int w;
    Edge(int f, int t, int w):f(f), t(t), w(w){}

    bool operator< (const Edge& rs)
    {
        return w < rs.w;
    }
};

//declaration
int T;
int n, m, cnt, x, y, cases;
pair<int, int> Node[maxn];
int cost[maxm];
int c, ans;
vector<int> G[maxm];
vector<Edge> edges;
int parent_arr[maxn];
//functions
int find(int x)
{ 
	return parent_arr[x] < 0 ? x : (parent_arr[x] = find(parent_arr[x]));
}

void conn(int x,int y)
{
    if(find(x) == find(y))
        return;
    parent_arr[find(y)]=find(x);
}

int kruskal(void)
{
    c = 0;
    cnt = 0;
    for(int i = 0; i < edges.size(); i++)
    {
        Edge tmp = edges[i];

        if(cnt == n-1)
            break;

        if(find(tmp.t) != find(tmp.f))
        {
            c += tmp.w;
            conn(tmp.f, tmp.t); 
            cnt++;   
        }
    }
    return c;
}

int solve(void)
{
	sort(edges.begin(), edges.end());

    memset(parent_arr, -1, sizeof(parent_arr));
    ans = kruskal();

    //二進制枚舉
    for(int j = 0; j < 1<<m; j++)
    {
        int tmp = 0;

        memset(parent_arr, -1, sizeof(parent_arr));
        for(int i = 0; i < m; i++)
        {
            if((j >> i) &1)
            {
                for(int l = 1; l < G[i].size(); l++)
                {
                    conn(G[i][l-1], G[i][l]);
                }
                tmp += cost[i];
            }
        }

        ans = min(ans, tmp+kruskal());
    }

    return ans;
}

int getDist(pair<int, int> a, pair<int, int> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    IOS;

    cin >> T;
    cases = 0;
    
    while(T--)
    {
        if(cases++)
            cout << '\n';
        cin >> n >> m;

        //input special path
        for(int i = 0; i < m; i++)
        {
            cin >> cnt >> cost[i];
            G[i].clear();

            for(int j = 0; j < cnt; j++)
            {
                cin >> x; G[i].emplace_back(x);
            }
        }

        //  input node
        for(int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            Node[i] = make_pair(x, y);
        }

        edges.clear();
        for(int i = 1; i <= n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                edges.emplace_back(Edge(i, j, getDist(Node[i], Node[j])));
            }
        }

        cout << solve() << '\n';
    }

	return 0;
}