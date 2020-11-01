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
#define maxn 25
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n, avg;
int stick[maxn];
bool vis[maxn];
bool flag;

//functions

bool dfs(int now, int stick_num, int length){

	if(stick_num == 4)
		return true;

	if(length == avg){
		return dfs(0, stick_num+1, 0);
	}


	for(int i = now; i < n; i++){
		if(!vis[i] && length + stick[i] <= avg){
			vis[i] = true;
			if(dfs(i+1, stick_num, length+stick[i])){
				return true;
			}
			vis[i] = false;
		}
	}
	
	return false;
}

bool cmp(int a, int b){
	return a > b;
}

int main(void)
{
	int T;
	cin >> T;

	while(T--){
		cin >> n;

		int total = 0;

		for(int i = 0; i < n; i++){
			cin >> stick[i];
			total += stick[i];
		}

		avg = total/4;

		sort(stick, stick+n, cmp);

		memset(vis, false, sizeof(vis));

		if(total % 4 != 0){
			printf("no\n");
			continue;
		}
	
		if(!dfs(0, 1, 0))
			printf("no\n");
		else
			printf("yes\n");
	}

	return 0;
}