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

//structure
struct Item
{
    int node, oils, cost;

    bool operator< (const Item& rs) const
    {
        return cost > rs.cost;
    }
};
//declaration
int n, m, T, tank, s, e;
int oil[maxn];
vector<PII > edges[maxn];
int dp[maxn][maxn];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(~scanf("%d %d", &n, &m))
    {
        REP(i, 0, n-1)
        {
            scanf("%d", &oil[i]);
            edges[i].clear();
        }
            
        
        int x, y, z;
        REP(i, 1, m)
        {
            scanf("%d %d %d", &x, &y, &z);

            edges[x].PB(MP(y, z));
            edges[y].PB(MP(x, z));
        }

        scanf("%d", &T);

        while(T--)
        {
            int ans = 1e9;
            scanf("%d %d %d", &tank, &s, &e);
            priority_queue<Item> q;
            
            REP(i, 0, n)
            {
                REP(j, 0, tank+2)
                {
                    dp[i][j] = 1e9;
                }
            }

            q.push((Item){s, 0, 0});
            while(!q.empty())
            {
                Item tmp = q.top();
                q.pop();

                // printf("Item: %d %d %d\n", tmp.node, tmp.oils, tmp.cost);
                if(tmp.node == e)
                {
                    ans = min(ans, tmp.cost);
                    break;
                }

                for(auto i : edges[tmp.node])
                {
                    Item hold = tmp;

                    // printf("%d %d\n", i.F, i.S);
                    if(hold.oils < i.S)
                    {
                        hold.cost += (i.S-hold.oils)*oil[hold.node];
                        hold.oils = i.S;
                    }

                    for(int j = 0; hold.oils+j <= tank; j++)
                    {
                        // printf("%d %d %d\n", i.F, hold.oils+j, hold.cost+j*oil[hold.node]);
                        if(dp[i.F][hold.oils-i.S+j] > hold.cost+j*oil[hold.node])
                        {
                            dp[i.F][hold.oils-i.S+j] = hold.cost+j*oil[hold.node];
                            q.push((Item){i.F, hold.oils-i.S+j, hold.cost+j*oil[hold.node]});
                        }   
                    }   
                }
            }
            if(ans == 1e9)
                puts("impossible");
            else
                printf("%d\n", ans);
        }
    }

	return 0;
}