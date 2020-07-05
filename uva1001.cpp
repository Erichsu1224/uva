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
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure
struct Point{
    double x, y, z, r;
};

//declaration
int n;
vector<Point> v;
double x, y, z, r;
double dis[maxn][maxn];
//functions
double getdis(int a, int b){
    double x = (v[a].x-v[b].x)*(v[a].x-v[b].x);
    double y = (v[a].y-v[b].y)*(v[a].y-v[b].y);
    double z = (v[a].z-v[b].z)*(v[a].z-v[b].z);

    return max(0.0, sqrt(x+y+z)-v[a].r-v[b].r);
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T = 1;
    
	while(~scanf("%d", &n)){
        if(n == -1)
            break;

        v.clear();


        REP(i, 1, n){
            scanf("%lf %lf %lf %lf", &x, &y, &z, &r);
            v.EB((Point){x, y, z, r});
        }

        REP(i, 1, 2){
            scanf("%lf %lf %lf", &x, &y, &z);
            v.EB((Point){x, y, z, 0});
        }

        for(int i = 0; i < v.size(); i++){
            for(int j = i; j < v.size(); j++){
                dis[i][j] = dis[j][i] = getdis(i, j);
            }
        }

        for(int k = 0; k < v.size(); k++){
            for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v.size(); j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        printf("Cheese %d: Travel time = %.0lf sec\n", T++, (dis[v.size()-2][v.size()-1])*10);
    }

	return 0;
}