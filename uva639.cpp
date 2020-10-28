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
#define maxn 9
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n;
char maz[maxn][maxn];
int ans;
string str;

bool check(int x, int y){

	for(int i = x-1; i >= 0; i--){
		if(maz[i][y] == 'X')
			break;
		if(maz[i][y] == 'C')
			return false;
	}
	for(int i = y-1; i >= 0; i--){
		if(maz[x][i] == 'X')
			break;
		if(maz[x][i] == 'C')
			return false;
	}
	for(int i = x+1; i < n; i++){
		if(maz[i][y] == 'X')
			break;
		if(maz[i][y] == 'C')
			return false;
	}
	for(int i = y+1; i < n; i++){
		if(maz[x][i] == 'X')
			break;
		if(maz[x][i] == 'C')
			return false;
	}

	return true;
}


//functions
void dfs(int x, int y, int cast){

	ans = max(ans, cast);

	for(int i = x; i < n; i++){
		for(int j = 0; j < n; j++){
			if(maz[i][j] == '.' && check(i, j)){
				maz[i][j] = 'C';
				dfs(i, j, cast+1);
				maz[i][j] = '.';
			}
		}
	}
}

int main(void)
{
	while(~scanf("%d\n", &n) && n){
		REP(i, 0, n-1){
			cin >> str;
			REP(j, 0, n-1)
				maz[i][j] = str[j];
		}

		// MSET(vis, 0);
		ans = 0;

		dfs(0, 0, 0);

		cout << ans << '\n';
	}
	return 0;
}