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
#define maxn 10
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int fig[maxn][maxn];
//functions



int main(void)
{
	int T;
	cin >> T;

	while(T--){
		int x, y;
		cin >> x >> y;
		// memset(fig, 0, sizeof(fig));

		
		dfs(x, y);

	}

	return 0;
}