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
#define maxn 25
#define maxm 100+5

//structure
struct tool
{
    int t;
    int a1, a2, b1, b2;
};

struct Item
{
    int cost;
    int status;

    Item(int cost, int status): cost(cost), status(status){}

    bool operator< (const Item& rs)const
    {
        return cost > rs.cost;
    }
};
//declaration
int n, m;
tool tools[maxm];
bool vis[(1<<20)+10];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int cases = 1;

    while(~scanf("%d %d", &n, &m))
    {
        if(!n && !m)
            break;
            
        REP(i, 0, m)
        {
            tools[i].t = tools[i].a1 = tools[i].a2 = tools[i].b1 = tools[i].b2 = 0;
        }

        string x, y;

        REP(i, 0, m-1)
        {
            cin >> tools[i].t >> x >> y;
            REP(j, 0, n-1)
            {
                if ('+' == x[n-1-j]) { tools[i].a1 = tools[i].a1 | (1 << j); }
                if ('-' == x[n-1-j]) { tools[i].a2 = tools[i].a2 | (1 << j); }
                if ('+' == y[n-1-j]) { tools[i].b1 = tools[i].b1 | (1 << j); }
                if ('-' == y[n-1-j]) { tools[i].b2 = tools[i].b2 | (1 << j); }
            }
        }

        //dis
        priority_queue<Item> q;            

        q.push(Item(0, (1<<n)-1));

        int ans = -1;
        MSET(vis, false);

        while(!q.empty())
        {
            Item tmp = q.top();
            q.pop();

            if(tmp.status == 0)
            {
                ans = tmp.cost;
                break;
            }
            if(vis[tmp.status]) continue;     
            vis[tmp.status] = true;

            for(int i = 0; i < m; i++)
            {
                if((tmp.status & tools[i].a1) == tools[i].a1 && (~tmp.status & tools[i].a2) == tools[i].a2)
                {
                    int uu = tmp.status | tools[i].b1;
                    uu = uu & ~tools[i].b2;
                    q.push(Item(tmp.cost+tools[i].t, uu));
                }
            }
        }

        printf("Product %d\n", cases++);
        if(ans == -1)
            printf("Bugs cannot be fixed.\n");
        else
            printf("Fastest sequence takes %d seconds.\n", ans);
        puts("");
    }

	return 0;
}