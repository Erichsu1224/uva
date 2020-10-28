#include <bits/stdc++.h>
using namespace std;


#define maxn 10000
#define LG 150
#define PB push_back
#define MP make_pair

vector<int> g[maxn];
int target;
int minn;
string ans;

int n ,m;
map<string, int> mp;
map<int, string> mp_re;
int cnt = 1;

int get_idx(string a){
    if(!mp[a]){
        mp[a] = cnt;
        mp_re[cnt++] = a;
    }
    return mp[a];
}

void dfs(int now, int fa, string str, int depth){
    
    str += mp_re[now][0];

    if(now == target && depth < minn){
        ans = str;
        minn = depth;
        return;
    }

    for(auto i : g[now]){
        if(i != fa)
            dfs(i, now, str, depth+1);
    }
}

int main(void)
{
    int T;
    cin >> T;

    while(T--){
        cin >> n >> m;

        //init
        cnt = 1;
        mp.clear();
        mp_re.clear();
        for(int i = 0; i < maxn; i++)
            g[i].clear();
        
        string x;
        string y;

        for(int i = 0; i < n; i++)
        {
            // if no weight
            cin >> x >> y;
            
            // cout << x << ' ' << y << '\n';

            g[get_idx(x)].PB(get_idx(y));
            g[get_idx(y)].PB(get_idx(x));
        }

        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;
            target = get_idx(y);

            minn = 1e9;
            ans = "";
            dfs(get_idx(x), -1, "", 0);

            cout << ans << '\n';
        }   
        
        if(T)
            cout << '\n';
    }    
    return 0;
}