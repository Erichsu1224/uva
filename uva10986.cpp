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
#define maxn 20000+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration

//functions
int n, m, s, t;
int x, y, z;
int dis[maxn]; // 預設都是 INF
vector<PII > e[maxn]; // (連到的點， 邊的距離)

void dijk(int cur) // dijk(起點)
{ 
  int d;
  priority_queue<PII,vector<PII>,greater<PII>> q; // 放 (距離, 點編號)，每次會拿距離最小的點出來
  q.push( MP(0, cur) );
    
  while (!q.empty()) 
  {
    tie(d, cur) = q.top();
    q.pop();
    if (dis[cur] != 1e9) 
        continue; // 如果之前就拜訪過，無視

    dis[cur] = d;

    for (auto i: e[cur])
        if (dis[i.first] == 1e9) 
        {
            q.push( MP(d+i.second, i.first) );
        }
    }
}

void init(void)
{
    fill(dis, dis+maxn, 1e9);

    for(int i = 0; i < maxn; i++)
    {
        e[i].clear();
    }
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

    int cases;

    cin >> cases;

    for(int T = 1; T <= cases; T++)
    {
        init();
        cin >> n >> m >> s >> t;

        REP(i, 1, m)
        {
            cin >> x >> y >> z;
            e[x].EB(MP(y, z));
            e[y].EB(MP(x, z));
        }

        dijk(s);


        if(dis[t] == 1e9)
            cout << "Case #" << T << ": unreachable\n";
        else
            cout << "Case #" << T << ": " << dis[t] << "\n";
    }

	return 0;
}