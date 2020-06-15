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
#define maxn
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure
struct Item{
    string name;
    int l, h;
};
//declaration
int T, n, m;
string name;
int x, y;
vector<Item> v;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d", &T);

    int counter = 0;
    while(T--){
        if(counter++){
            cout << '\n';
        }
        scanf("%d", &n);
        v.clear();

        REP(i, 1, n){
            cin >> name;
            scanf("%d %d", &x, &y);

            v.EB((Item){name, x, y});
        }

        scanf("%d", &m);

        REP(i, 1, m){
            scanf("%d", &x);

            string ans;
            int cnt = 0;

            for(auto i : v){
                if(i.l <= x && x <= i.h){
                    cnt++;
                    ans = i.name;
                }
            }

            if(!cnt || cnt >= 2){
                printf("UNDETERMINED\n");
            }
            else
                cout << ans << '\n';
        }
        
    }
	

	return 0;
}