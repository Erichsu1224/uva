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
#define maxn 100000
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n, q, x, y;
string str;
int st[maxn*4];
int st_val[maxn*4];

void build(int now, int l, int r){
    if(l == r)
        st[now] = st_val[l];

    else{
        build(now*2, l, (l+r)/2);
        build(now*2+1, (l+r)/2+1, r);
        st[now] = min(st[now*2], st[now*2+1]);
    }
}

int query(int now, int l, int r, int t_l, int t_r){
    
    if(t_l <= l && r <= t_r)
        return st[now];

    int tmp = 1e9;

    if(t_l <= (l+r)/2)
        tmp = min(tmp, query(now*2, l, (l+r)/2, t_l, t_r));
    if(t_r > (l+r)/2)
        tmp = min(tmp, query(now*2+1, (l+r)/2+1, r, t_l, t_r));

    return tmp;
}

int update(int now, int l, int r, int t){
    if(l == r){
        return st[now] = st_val[l];
    }

    if(t <= (l+r)/2)
        st[now] = min(st[now*2+1], update(now*2, l, (l+r)/2, t));
    else
        st[now] = min(st[now*2], update(now*2+1, (l+r)/2+1, r, t));

    return st[now];
}

void shift(vector<int> v){
    int tmp = st_val[v[0]];
    for(int i = 0; i < v.size()-1; i++){
        st_val[v[i]] = st_val[v[i+1]];
    }

    st_val[v.back()] = tmp;

    for(int i = 0; i < v.size(); i++){
        update(1, 1, n, v[i]);
    }
}

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(cin >> n >> q){
        REP(i, 1, n)
            cin >> st_val[i];

        build(1, 1, n);

        REP(i, 1, q){
            cin >> str;
            string tmp = "";
            vector<int> v;

            for(int i = 0; i < str.size(); i++){
                if(isdigit(str[i]))
                    tmp += str[i];
                else{
                    if(tmp != "")
                        v.EB(stoi(tmp));
                    tmp = "";
                }
            }

            if(str[0] == 'q'){
                cout << query(1, 1, n, v[0], v[1]) << '\n';
            }

            else{
                shift(v);
            }
        }
    }

	return 0;
}