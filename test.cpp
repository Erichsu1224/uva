#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 25+5

int ans;
int adj[maxn][maxn];
int n, edge;

void dfs(int node, int dist)
{
    if(ans < dist)
        ans = dist;
    for(int i = 0; i < n; i++)
    {
        if(adj[node][i])
        {
            adj[node][i] = adj[i][node] = 0;
            dfs(i, dist+1);
            adj[node][i] = adj[i][node] = 1;
        }
    }
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef file
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    #endif

    while(~scanf("%d %d", &n, &edge) && (n!=0 || edge!=0))
    {
        memset(adj, 0, sizeof(adj));
        ans = 0;

        for(int i = 0; i < edge; i++)
        {
            int from, to;
            scanf("%d %d", &from, &to);

            adj[from][to] = 1;
            adj[to][from] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            dfs(i, 0);
        }

        printf("%d\n", ans);
    }
    return 0;
}