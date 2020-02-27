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
#define maxn 1005
#define M 1005
#define IOS 

//structure
struct Edge{
    int t,r,opp,next; // t=邊的終點，r=剩餘流量, opp=反向邊編號, next=下一條邊編號(鍊表)
    Edge () {}
    Edge (int a,int b,int c,int d) { t=a; r=b; opp=c; next=d; }
}in[M*25];
int e,st,ed, n, m; // 當前邊標號, 源點, 匯點
int first[M],arc[M],dis[M]; // arc: bfs完以後，每個點找剩餘流找到哪條邊的標記
void add(int x,int y,int z) { // 加一條 x->y， 流量 z 的邊
    cout << x << ' ' << y << ' ' << z << '\n';
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
    n = m;
    queue<int> q;
    REP(i,0,n) dis[i] = 0;
    REP(i,0,n) arc[i] = first[i];
    dis[ed] = 1;
    q.push(ed);

    while (!q.empty()) {
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
        res += dfs(st, 2000000000);
        cout << res << endl;
    }
    
    return res;
}
//declaration
int T, q, cases, cnt;
string str;
string str1;
int device[maxn];
string type[maxn];
map<string, int> mp;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;

    st = 0;
    ed = 1;
    cases = 0;

    while(T--)
    {
        if(cases++)
            cout << '\n';
        cin >> n;

        init();
        mp.clear();

        cnt = 2;

        for(int i = 1; i <= n; i++)
        {
            cin >> type[i];
            mp[type[i]] = cnt++;
            add(cnt-1, 1, 1);
        }

        cin >> m;

        REP(i, 1, m)
        {
            cin >> str >> str1;
            if(!mp[str1])   mp[str1] = cnt++;
            device[i] = mp[str1];
            add(0, device[i], 1);         
        }

        cin >> q;

        REP(i, 1, q)
        {
            cin >> str >> str1;
            if(!mp[str])   mp[str] = cnt++;
            if(!mp[str1])   mp[str1] = cnt++;
            add(mp[str], mp[str1], 1);
        }
        
        cout << m-maxflow() << '\n';
    }
	return 0;
}