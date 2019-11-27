#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define REP(x, y, z)	for(int x = y; x <= z; x++)
#define maxn 100+5
#define MSET(x, y) memset(x, y, sizeof(x))
int dis[maxn][maxn][2];
vector<PII > e[maxn];
int n, m;

struct Item
{
	int w, cur;

	Item(int w, int cur): w(w), cur(cur){}

	bool operator< (const Item& rs)const
	{
		return w > rs.w;
	}
};

void dijk(int cur)
{
	
	int d, st = cur;
	priority_queue<Item> q;

	q.push(Item(0, cur));

	while(!q.empty())
	{
		d = q.top().w; 
		cur = q.top().cur;
		q.pop();

		// cout << "curr "<< d << ' ' << cur << ":\n" ;

        if(dis[st][cur][0] == -1)
        {
            dis[st][cur][0]=d;
        }

        else
        {
            if(dis[st][cur][0]>d)
            {
                dis[st][cur][1]=dis[st][cur][0];
                dis[st][cur][0]=d;
            }
            else if(dis[st][cur][0]==d)continue;
            else if(dis[st][cur][1]==-1||dis[st][cur][1]>d)
            {
                dis[st][cur][1]=d;
            }
            else continue;
        }

        // cout << cur << ' ' << d << ' ' << dis[st][cur][1] << endl;

		for(auto i : e[cur])
		{
			// cout << "EDGE: ";
			// cout << i.first << ' ' << i.second << endl;
			// if(dis[st][i.first] == 1e9 && flag[cur] <= 2)
			// {
				// printf("%d %d\n", d+i.second, i.first);
				q.push(Item(d+i.second, i.first));
			// }
		}
	}
}

void init(void)
{
	MSET(dis, -1);

	for(int i = 0; i < maxn; i++)
		e[i].clear();
}

int main(void)
{
    #ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int cases = 1;
	while(~scanf("%d %d", &n, &m))
	{
		printf("Set #%d\n", cases++);
		init();
		int x, y, z;

		REP(i, 1, m)
		{
			scanf("%d %d %d", &x, &y, &z);

			e[x].PB(MP(y,z));
			e[y].PB(MP(x,z));
		}

		REP(i, 0, n-1)
		{
			dijk(i);
		}

        // REP(i, 0, n-1)
        // {
        //     REP(j, 0, n-1)
        //     {
        //         cout << dis[i][j][0] << ' ';
        //     }
        //     cout << endl;
        // }

        // printf("Testing\n");
		int t;
		scanf("%d", &t);



		REP(i, 1, t)
		{
			scanf("%d %d", &x, &y);

			if(dis[x][y][1] == -1)
				printf("?\n");
			else
				printf("%d\n", dis[x][y][1]);
		}
	}
}