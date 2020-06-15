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
#define maxn 105

//structure

//declaration
int n, m;
int x, y, top, vis[maxn];
vector<int> g[maxn];
int order[maxn];
//functions
bool dfs(int now){
    vis[now] = -1;

    for(auto i : g[now]){
        if(vis[i] < 0)
            return false;
        else if(!vis[i] && !dfs(i))
            return false;
    }

    vis[now] = 1;
    order[top--] = now;
    return true;
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(~scanf("%d %d", &n, &m)){
        if(!n && !m)    break;

        REP(i, 0, n){
            g[i].clear();
        }

        REP(i, 1, m){
            cin >> x >> y;
            g[x].EB(y);
        }

        MSET(vis, 0);
        top = n;
        
        REP(i, 1, n){
            if(!vis[i]){
                dfs(i);
            }
        }

        REP(i, 1, n){
            if(i > 1)
                printf(" ");
            printf("%d", order[i]);
        }

        puts("");
    }
	return 0;
}