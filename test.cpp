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
#define maxn 100000+5

//structure

//declaration
int n, a, b;
int dis[2][maxn];
vector<int> g[maxn];
//functions

void dfs(int now, int fa, int t)
{
    dis[t][now] = dis[t][fa]+1;

    for(auto i : g[now])
    {
        if(i != fa)
        {
            dfs(i, now, t);
        }
    }
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	scanf("%d", &n);
	scanf("%d %d", &a, &b);

	//init
	REP(i, 0, n)
		g[i].clear();

	int x, y;

	for(int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &x, &y);

		g[x].EB(y);
		g[y].EB(x);
	}	

    dis[0][0] = dis[1][0] = -1;

	dfs(a, 0, 0);
    dfs(b, 0, 1);

    int ans = 0;

    REP(i, 1, n)
    {
        cout << dis[0][i] << ' ';
    }
    cout << endl;

    REP(i, 1, n)
    {
        cout << dis[1][i] << ' ';
    }
    cout << endl;

    REP(i, 1, n)
    {
        if(dis[0][i] < dis[1][i])
            ans = max(ans, dis[1][i]-1);
    }

    printf("%d\n", ans);

	// return 0;
}