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
#define maxn 1000+5
#define maxq 8+5

//structure
struct special
{
    int cost;
    vector<int> p;

    special(){}

}   S_P[maxq];

struct City
{
    int x, y;
    City(int x, int y): x(x), y(y){}

    City(){}
}   cities[maxn];

struct Edge
{
    int from, to;
    int dis;

    Edge(int from, int to, double dis): from(from), to(to), dis(dis){}

    bool operator< (const Edge& rs)const
    {
        return dis < rs.dis;
    }
};
//declaration
int T, n, q;
int cost;
int parent_arr[maxn];
vector<Edge> edges;
vector<Edge> g;
//functions

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
    cost = 0;
	memset(parent_arr, -1, sizeof(parent_arr));
	sort(edges.begin(), edges.end());

	for(int i = 0; i < edges.size(); i++)
	{
		Edge tmp = edges[i];

		if(find(tmp.to) == find(tmp.from))
		{
			//不能形成環的邊
			continue;
		}

		else
		{
            // printf("%d %d %d\n", tmp.to, tmp.from, tmp.dis);
            cost += tmp.dis;
			conn(tmp.from, tmp.to);
            g.PB(tmp);
		}
	}
}

int getdis(City a, City b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d", &n, &q);

        //init
        edges.clear();
        g.clear();

        REP(i, 1, q)
        {
            int hold, nn;

            S_P[i].p.clear();

            scanf("%d %d", &nn, &S_P[i].cost);

            REP(j, 1, nn)
            {
                scanf("%d", &hold);
                S_P[i].p.PB(hold);      
            }
        }

        REP(i, 1, n)
        {
            scanf("%d %d", &cities[i].x, &cities[i].y);
        }

        REP(i, 1, n)
        {
            REP(j, i+1, n)
            {
                edges.PB(Edge(i, j, getdis(cities[i], cities[j])));
            }
        }

        kruskal_algorithm();

        int ans = cost;
        // cout << cost << endl;

        REP(l, 1, q)
        {
            cost = S_P[l].cost;
            int k = 0;

            memset(parent_arr, -1, sizeof(parent_arr));
            sort(all(g));

            REP(j, 1, S_P[l].p.size()-1)
            {
                conn(S_P[l].p[j-1], S_P[l].p[j]);
            }

            for(int i = 0; i < g.size(); i++)
            {
                Edge tmp = g[i];

                if(find(tmp.to) == find(tmp.from))
                {
                    //不能形成環的邊
                    continue;
                }

                else
                {
                    cost += tmp.dis;
                    conn(tmp.from, tmp.to);
                    k++;
                }
            }

            if(k+S_P[l].p.size() != n)
                continue;
            
            // cout << cost << endl;
            ans = min(ans, cost);
        }
        
        printf("%d\n", ans);
    }

	return 0;
}