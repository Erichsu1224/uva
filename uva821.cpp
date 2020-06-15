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
int x, y;
map<int, int> mp;
int dis[maxn][maxn];
int cnt;
//functions
int get_idx(int a){
    if(!mp[a])
        return mp[a] = cnt++;
    return mp[a];
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T = 1;

    while(cin >> x >> y){
        if(!x && !y)
            break;

        cnt = 1;
        mp.clear();
        for(int i = 0; i < maxn; i++){
            for(int j = 0; j < maxn; j++){
                if(i == j)
                    dis[i][j] = 0;
                else
                    dis[i][j] = 1e9;
            }
        }

        dis[get_idx(x)][get_idx(y)] = 1;

        while(cin >> x >> y){
            if(!x && !y)
                break;
            dis[get_idx(x)][get_idx(y)] = 1;
        }

        for (int k = 1; k < cnt; k++)
            for (int i = 1; i < cnt; i++)
                for (int j = 1; j < cnt; j++)
                    if (dis[i][j] > dis[i][k] + dis[k][j]) 
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }

        double ans = 0.0;
        for(int i = 1; i < cnt; i++){
            for(int j = 1; j < cnt; j++){ 
                ans += dis[i][j];
            }
        }     

        printf("Case %d: average length between pages = %.3f clicks\n", T++, ans/((cnt-1)*(cnt-2)));
    }

	return 0;
}