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
    int a, b, c, d;
};

//declaration
int T;
int w_l, w_r, d_l, d_r;
vector<Item> v;
int cnt;
bool flag;

//functions
int build(void){
    auto node = v[cnt++];

    // printf("%d %d %d %d\n", node.a, node.b, node.c, node.d);
    
    int left_weight, right_weight;

    if(node.a == 0)
        left_weight = build();
    else
        left_weight = node.a;

    if(node.c == 0)
        right_weight = build();
    else
        right_weight = node.c;

    if(left_weight*node.b != right_weight*node.d)
        flag = false;
    
    return left_weight+right_weight;
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d\n\n", &T);

    while(T--){
        string str;
        v.clear();
        cnt = 0;
        flag = true;

        while(getline(cin, str)){
            // cout << str << endl;
            if(str == "")
                break;

            stringstream ss(str);
            ss >> w_l >> w_r >> d_l >> d_r;

            v.EB((Item){w_l, w_r, d_l, d_r});
        }
        // printf("===============\n");
        build();

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
        if(T)
            puts("");
    }

	return 0;
}