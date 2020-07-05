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
#define maxn 10000+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int infix[maxn];
int postfix[maxn];
int ans, ans_total, n;
//functions

void dfs(int in_l, int in_r, int post_l, int post_r, int weight){
    // printf("%d %d %d %d %d\n", in_l, in_r, post_l, post_r, weight);

    if(in_l > in_r)
        return;

    if(in_r-in_l+1 == 1){
        if(ans_total > weight+infix[in_l]){
            ans_total = weight+infix[in_l];
            ans = infix[in_l];
        }

        return;
    }

    int root = postfix[post_r];
    int in = in_l;

    while(infix[in] != root)
        in++;

    int left_cnt = in-in_l;
    

    dfs(in_l, in-1, post_l, post_l+(left_cnt-1), weight+infix[in]);
    dfs(in+1, in_r, post_l+left_cnt, post_r-1, weight+infix[in]);

    return;
}

bool read(int* a){
    string str;
    if(!getline(cin, str))
        return false;
    n = 0;
    int x;
    stringstream ss(str);

    while(ss >> x){
        a[n++] = x;
    }
    return n>0;
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	string tmp;
    int x;

    while(read(infix)){

        read(postfix);
        ans_total = 1e9;

        dfs(0, n-1, 0, n-1, 0);

        cout << ans << endl;
    }

	return 0;
}