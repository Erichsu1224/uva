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
#define maxn 1000+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n, m, ans;
int check[maxn];
vector<int> prime[maxn];
//functions
void get_prime(void){
    for(int i = 2; i <= 1000; i++){
        if(prime[i].size() == 0){
            for(int j = i*2; j <= 1000; j += i){
                prime[j].EB(i);
            }
        }
    }
}
void dfs(int n, int depth){
    check[n] = depth;

    for(int i = prime[n].size()-1; i >= 0; i--){
        if(n+prime[n][i] <= m && (check[n+prime[n][i]] > depth+1 || check[n+prime[n][i]] == -1)){
            dfs(n+prime[n][i], depth+1);
        }
    }
}

void bfs(int n){
    queue<pair<int, int>> q;

    q.push(MP(n, 0));

    while(!q.empty()){
        auto now = q.front(); q.pop();
        check[now.F] = 1;

        if(now.F == m){
            ans = now.S;
            break;
        }

        for(int i = prime[now.F].size()-1; i >= 0; i--){
            if(now.F+prime[now.F][i] <= m && !check[now.F+prime[now.F][i]]){
                q.push(MP(now.F+prime[now.F][i], now.S+1));
            }
        }
    }
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T = 1;
    get_prime();
    
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;

        // DFS
        // MSET(check, -1);
        // dfs(n, 0);

        // printf("Case %d: %d\n", T++, check[m]);

        //BFS
        ans = -1;
        MSET(check, 0);
        bfs(n);

        printf("Case %d: %d\n", T++, ans);
    }

	return 0;
}