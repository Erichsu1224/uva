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
int prime[maxn];
bool check[maxn];
int dp[maxn];
int cnt, ans;
//declaration

//functions
void getprime(void){
    MSET(check, true);
    cnt = 0;

    for(int i = 2; i <= 1e4; i++){
        if(check[i]){
            prime[cnt++] = i;
            for(int j = i*i; j <= 1e4; j+=i)
                check[j] = false;
        }
    }
}

void solve(int n){
    for(int i = 0; prime[i] <= n; i++){
        int tmp = 0;
        for(int j = i; j < cnt && tmp < n; j++){
            tmp += prime[j];
        }
        if(tmp == n)
            ans++;
    }
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	getprime();

    int n;

    while(cin >> n && n){
        ans = 0;
        solve(n);

        cout << ans << '\n';
    }

	return 0;
}