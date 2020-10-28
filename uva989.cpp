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
#define maxn 14
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n;
int sudo[maxn][maxn];
//functions
bool check(int x, int y, int k){
	for(int i = 0; i < n*n; i++){
		if(sudo[i][y] == k || sudo[x][i] == k)
			return false;
	}

	for(int i = x-(x%n); i < x-(x%n)+n; i++){
		for(int j = y-(y%n); j < y-(y%n)+n; j++){
			if(sudo[i][j] == k)
				return false;
		}
	}

	return true;
}

bool dfs(int x, int y){

	// for(int i = 0; i < n*n; i++){
	// 	for(int j = 0; j < n*n; j++){
	// 		cout << sudo[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// cout << "------------------------\n";

	// if(x == n*n-1 && y == n*n-1)
	// 	return true;

	for(int i = x; i < n*n; i++){
		for(int j = 0; j < n*n; j++){
			if(sudo[i][j] == 0){
				for(int k = 1; k <= n*n; k++){
					if(check(i, j, k)){
						sudo[i][j] = k;
						if(dfs(i, j))
							return true;
						sudo[i][j] = 0;
					}
				}
			}
			if(sudo[i][j] == 0)
				return false;
		}
	}

	return true;
}

int main(void)
{
	int T = 0;

	while(cin >> n){
		if(T)
			cout << '\n';

		for(int i = 0; i < n*n; i++){
			for(int j = 0; j < n*n; j++){
				cin >> sudo[i][j];
			}
		}

		if(!dfs(0, 0)){
			cout << "NO SOLUTION\n";
		}
		else{
			for(int i = 0; i < n*n; i++){
				for(int j = 0; j < n*n; j++){
					if(j)
						cout << ' ';
					cout << sudo[i][j];
				}
				cout << '\n';

			}
		}

		T = 1;
	}

	return 0;
}