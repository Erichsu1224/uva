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
#define maxn 30
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
vector<int> g[maxn];
map<char, int> mp;
int Node[maxn];
int cnt, ans;
//functions
int get_idx(char c){
    if(!mp[c])
        mp[c] = cnt++;
    return mp[c];
}

void dfs(int now, int depth){
    ans = max(ans, depth+Node[now]);

    for(auto i : g[now])
        dfs(i, depth+Node[now]);
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T;
    string str;
    int start;

    scanf("%d\n", &T);

    while(T--){
        mp.clear();
        cnt = 1;
        ans = 0;
        for(int i = 0; i < maxn; i++)
            g[i].clear();

        while(getline(cin, str)){
            if(str == "")
                break;

            char x, y;
            bool flag = true;

            stringstream ss(str);

            ss >> x;
            ss >> Node[get_idx(x)];

            while(ss >> y){
                flag = false;
                g[get_idx(y)].EB(get_idx(x));
            }

            if(flag)
                start = get_idx(x);
        }

        dfs(start, 0);

        printf("%d\n", ans);

        if(T)
            puts("");
    }
	

	return 0;
}