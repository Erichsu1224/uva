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
int n;
bool prime[100];
bool vis[20];
vector<int> ans;
//functions

void getprime(int a){
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = true;
	for(int i = 2; i <= a; i++){
		if(prime[i] == true){
			for(int j = i*i; j <= a; j += i)
				prime[j] = false;		
		}	
	}
}

bool dfs(int pre, int num){

	// cout << pre << ' ' << num << '\n';

	if(num == n){
		if(prime[1+ans.back()]){
			cout << '1';
			for(int i = 0; i < ans.size(); i++){
				cout << ' ';
				cout << ans[i];
			}
			cout << '\n';
			return true;
		}
		else
			return false;
	}

	for(int i = 2; i <= n; i++){
		if(!vis[i] && prime[i+pre]){
			vis[i] = true;
			ans.EB(i);
			dfs(i, num+1);
			ans.pop_back();
			vis[i] = false;
		}
	}

	return false;
}

int main(void)
{
	getprime(100);
	int T = 0;

	while(cin >> n) {
		if(T)
			cout << '\n';
		cout << "Case " << ++T << ":\n";

		if(n == 1){
			cout << "1\n";
			continue;
		}

		memset(vis, false, sizeof(vis));
		vis[1] = true;
		dfs(1, 1);
	}

	return 0;
}