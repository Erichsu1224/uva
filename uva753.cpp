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
#define M 100+5

//structure

//declaration
int T, n, m, k;
string type[maxn];
pair<string, string> tools[maxn];
pair<string, string> tran[maxn];
bool floyd[4*maxn][4*maxn];
map<string, int> mp;
//functions
struct Edge{
    int t,r,opp,next; // t=邊的終點，r=剩餘流量, opp=反向邊編號, next=下一條邊編號(鍊表)
    Edge () {}
    Edge (int a,int b,int c,int d) { t=a; r=b; opp=c; next=d; }
}in[M*25];
int e,st,ed; // 當前邊標號, 源點, 匯點
int first[M],arc[M],dis[M], gap[M*2]; // arc: bfs完以後，每個點找剩餘流找到哪條邊的標記
void add(int x,int y,int z) { // 加一條 x->y， 流量 z 的邊
    in[e] = Edge(y,z,e+1,first[x]);
    first[x] = e++;
    in[e] = Edge(x,0,e-1,first[y]);
    first[y] = e++;
}
void init() {
    e = 0;
    MSET(first, -1);
    MSET(dis, 0);
}
bool bfs() {
    int cur;
    queue<int> q;
    REP(i,0,n) dis[i] = 0;
    REP(i,0,n) arc[i] = first[i];
    dis[ed] = 1;
    q.push(ed);

    while (!q.empty()) {
        cout << cur << endl;
        cur = q.front();
        q.pop();
        for (int i=first[cur]; ~i; i=in[i].next)
            if (in[in[i].opp].r && !dis[in[i].t]) {
                dis[in[i].t] = dis[cur] + 1;
                q.push(in[i].t);
            }
    }
    return dis[st] > 0;
}
int dfs(int cur,int flow) {
    if (cur==ed) return flow;
    int re=0, tmp;
    for (int i=arc[cur]; ~i; i=arc[cur]=in[i].next)
        if (dis[in[i].t]==dis[cur]-1 && in[i].r>0) { //如果距離編號剛好小1，且有剩餘流量
            tmp = dfs(in[i].t, min(in[i].r, flow));
            re += tmp;
            flow -= tmp;
            in[i].r -= tmp;
            in[in[i].opp].r += tmp;
            if (!flow) return re;
        }
    return re;
}

int maxflow() {
    int res = 0;
    while(bfs()) 
    {
        int tmp = dfs(st, 1e9);
        cout << tmp << endl;
        res += tmp;
       // cout << res << endl;
    }
    return res;
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
        MSET(floyd, false);
        scanf("%d\n", &n);
        int cnt = 0;

        REP(i, 1, n)
        {
            cin >> type[i];

            if(!mp.count(type[i]))
                mp[type[i]] = cnt++;
        }

        scanf("%d\n", &m);
        REP(i, 1, m)
        {
            cin >> tools[i].F >> tools[i].S;

            if(!mp.count(tools[i].S))
                mp[tools[i].S] = cnt++;
        }

        scanf("%d\n", &k);

        REP(i, 1, k)
        {
            cin >> tran[i].F >> tran[i].S;

            if(!mp.count(tran[i].F))
                mp[tran[i].F] = cnt++;
            if(!mp.count(tran[i].S))
                mp[tran[i].S] = cnt++;

            floyd[mp[tran[i].F]][mp[tran[i].S]] = true;
        }

        //  floyd warshell algorithm

        REP(i, 0, cnt-1)
            floyd[i][i] = true;

        REP(l, 0, cnt-1)
            REP(i, 0, cnt-1)
                REP(j, 0, cnt-1)
                    floyd[i][j] |= floyd[i][l] && floyd[l][j];

        REP(i, 0, cnt-1)
        {
            REP(j, 0, cnt-1)
                cout << floyd[i][j] << ' ';
            cout << endl;
        }
        init();

        for(int i = 1; i <= m; i++) 
        {
            cout << cnt <<  ' ' << mp[tools[i].S] << endl;
            add(cnt, mp[tools[i].S], 1);
        }
        cout << endl;
        for(int i = 1; i <= n; i++) 
        {
            cout << mp[type[i]] << ' ' << cnt+1 << endl;
            add(mp[type[i]], cnt+1, 1);
        }
        cout << endl;

        for(int i = 1; i <= m; i++) 
        {
            for(int j = 1; j <= n; j++) 
            {
                if(!floyd[mp[tools[i].S]][mp[type[j]]]) continue;
                cout << mp[tools[i].S] << ' ' << mp[type[j]] << endl;
                add(mp[tools[i].S], mp[type[j]], 1);
            }
        }


        st = cnt;
        ed = cnt+1;
        cout << m-maxflow() << endl;
    }

	return 0;
}