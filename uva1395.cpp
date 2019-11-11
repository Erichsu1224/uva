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
#define maxn 100+5

//structure

//declaration

//functions

struct Edge
{
	int from, to, cost;

	Edge(int _from, int _to, int _cost) 
	{
		from = _from;
		to = _to;
		cost = _cost;
	}

	bool operator< (const Edge &r) const
	{
		return cost < r.cost;
	}
};

int parent_arr[maxn];
int n, m, ans;
vector<Edge> edges;

int find(int x)
{ 
	return parent_arr[x] < 0 ? x : (parent_arr[x] = find(parent_arr[x]));
}

void conn(int x,int y)
{
    parent_arr[find(y)]=find(x);
}

void kruskal_algorithm(void)
{
	sort(edges.begin(), edges.end());

    for(int j = 0; j+n-2 < m; j++)
    {
        memset(parent_arr, -1, sizeof(parent_arr));
        int minn = edges[j].cost;
        int maxx = 0;
        int cnt = 0;

        for(int i = j; i < m; i++)
        {
            Edge tmp = edges[i];

            if(find(tmp.to) == find(tmp.from))
            {
                //不能形成環的邊
                continue;
            }

            else
            {
                cnt++;
                maxx = tmp.cost;
                conn(tmp.from, tmp.to);   
            }
        }

        // cout << cnt << endl;

        if(cnt == n-1)
            ans = min(ans, maxx-minn);
    }
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(~scanf("%d %d", &n, &m))
    {
        if(n == 0 && m == 0)
            break;
        edges.clear();
        ans = 1e9;

		for(int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back(Edge(a, b, c));
		}

        kruskal_algorithm();

        if(ans == 1e9)
            puts("-1");
        else
            printf("%d\n", ans);
    }

	return 0;
}