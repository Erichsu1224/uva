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

//declaration
vector<int> v;
int cnt, counter;
map<int, int> idx;
vector<int> weight;
int minn;
int maxx;
//functions
int getidx(int x){
    if(!idx[x]){
        idx[x] = counter++;
        weight.EB(0);
    }
        
    return idx[x];
}   

void build(int now_idx){
    minn = min(minn, now_idx);
    maxx = max(maxx, now_idx);
    int tmp = v[cnt++];

    if(tmp == -1)
        return;

    weight[getidx(now_idx)] += tmp;

    // printf("LEFT\n");
    build(now_idx-1);
    // printf("RIGHT\n");
    build(now_idx+1);
} 



int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    string str;
    int T = 1;

    while(getline(cin, str)){
        if(str[0] == '-')
            continue;
        v.clear();
        weight.clear();
        weight.EB(0);
        idx.clear();
        counter = 1;
        cnt = 0;

        stringstream ss(str);
        int x;

        while(ss >> x)
            v.EB(x);

        build(1);

        printf("Case %d:\n", T++);
        cnt = 0;
        for(int i = minn; i <= maxx; i++){
            if(weight[getidx(i)] != 0){
                if(cnt)
                    printf(" ");
                printf("%d", weight[getidx(i)]);
                cnt++;
            }
            
        }
        puts("\n");
    }

	return 0;
}