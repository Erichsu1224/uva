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
#define maxn 1024
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure
struct Node{
    char pixel;
    int a, b, c, d;
};
//declaration
Node tree_a[maxn*4];
Node tree_b[maxn*4];
int cnt;
int total_pixel;
string str;
//functions

void build(int now, Node* tree){
    char tmp = str[cnt++];
    tree[now].pixel = tmp;
    if(tmp == 'f' || tmp == 'e'){
        return;
    }
    
    build(now*4-2, tree);
    build(now*4-2+1, tree);
    build(now*4-2+2, tree);
    build(now*4-2+3, tree);
}

void solve(int now, int p){
    
    if(tree_a[now].pixel == 'f' || tree_b[now].pixel == 'f'){
        total_pixel += p;
        return;
    }
    if(tree_a[now].pixel == 'e' && tree_b[now].pixel == 'e'){
        return;
    }

    solve(now*4-2, p/4);
    solve(now*4-2+1, p/4);
    solve(now*4-2+2, p/4);
    solve(now*4-2+3, p/4);
    return;
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T;
    scanf("%d\n", &T);

    while(T--){
        Node tmp = (Node){'e', 0, 0, 0, 0};
        for(int i = 0; i < maxn*4; i++){
            tree_a[i] = tree_b[i] = tmp;
        }

        getline(cin, str);
        cnt = 0;
        build(1, tree_a);
        getline(cin, str);
        cnt = 0;
        build(1, tree_b);

        total_pixel = 0;
        solve(1, 1024);

        printf("There are %d black pixels.\n", total_pixel);
    }

	return 0;
}