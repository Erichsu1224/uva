#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= (z); x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define maxn 1000+5

//structure
struct City
{
    int x, y, w;

    City(){}

    City(int x, int y, int w): x(x), y(y), w(w){}

};

struct Edge
{
    int from, to;
    double dis;

    Edge(int from, int to, double dis): from(from), to(to), dis(dis){}

    //operator overloading
    bool operator< (const Edge& rs) const
    {
        return dis < rs.dis;
    }
};
//declaration
int T, n;
double sumPath, ans;
int parent_arr[maxn];
double MaxD[maxn][maxn];
vector<Edge> edges;
vector<pair<int, double> > MST[maxn];
City cities[maxn];
//functions
double getDis(City a, City b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

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
	MSET(parent_arr, -1);
	sort(all(edges));

	REP(i, 0, edges.size()-1)
    {
		Edge tmp = edges[i];

		if(find(tmp.to) != find(tmp.from))
		{
            sumPath += tmp.dis;
			conn(tmp.from, tmp.to);
            MST[tmp.to].PB(MP(tmp.from, tmp.dis));
            MST[tmp.from].PB(MP(tmp.to, tmp.dis));
		}
	}
}

void dfs(int fa, int st, int now, double maxDis)
{
    MaxD[st][now] = max(MaxD[st][now], maxDis);

    for(auto i : MST[now])
    {
        if(i.F == fa)   continue;

        double tmp = max(maxDis, i.S);

        dfs(now, st, i.F, tmp);
    }
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
        //initialize
        sumPath = 0;
        ans = 0;
        edges.clear();
        MSET(MaxD, 0);
        REP(i, 1, n)
        {
            MST[i].clear();
        }

        scanf("%d", &n);

        REP(i, 1, n)
        {
            scanf("%d %d %d", &cities[i].x, &cities[i].y, &cities[i].w);
        }

        // add edges
        REP(i, 1, n)
        {
            REP(j, 1, n)
            {
                if(i >= j)
                    continue;
                edges.PB(Edge(i, j, getDis(cities[i], cities[j])));
            }
        }

        // kruskal algorithm
        kruskal_algorithm();

        //dfs
        REP(i, 1, n)
        {
            dfs(i, i, i, 0);
        }

        REP(i, 1, n)
        {
            REP(j, i+1, n)
            {
                ans = max((cities[i].w+cities[j].w)/(sumPath-MaxD[i][j]), ans);
            }
        }

        printf("%.2lf\n", ans);
    }

	return 0;
}