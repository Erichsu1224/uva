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
int sudo[maxn][maxn];
int cnt;
int ill[maxn];
//functions

bool check(int x, int y, int k){
	int n = 3;
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


bool illegal(void){
	for(int i = 0; i < 9; i++){
		memset(ill, 0, sizeof(ill));
		for(int j = 0; j < 9; j++){
			if(sudo[i][j] && ill[sudo[i][j]]){
				return false;
			}
			ill[sudo[i][j]]++;
		}
		memset(ill, 0, sizeof(ill));
		for(int j = 0; j < 9; j++){
			if(sudo[j][i] && ill[sudo[j][i]])
				return false;
			ill[sudo[j][i]]++;
		}
	}

	for(int i = 0; i < 9; i = i+3){
		for(int j = 0; j < 9; j = j+3){
			memset(ill, 0, sizeof(ill));
			for(int k = 0; k < 3; k++){
				for(int l = 0; l < 3; l++){
					if(sudo[i+k][j+l] && ill[sudo[i+k][j+l]])
						return false;
					ill[sudo[i+k][j+l]]++;
				}
			}
		}
	}
	return true;
}


bool dfs(int x, int y){

	if(cnt >= 2)
		return false;

	for(int i = x; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(sudo[i][j] == 0){
				bool flag = false;
				for(int k = 1; k <= 9; k++){
					if(check(i, j, k)){
						flag = true;
						sudo[i][j] = k;
						dfs(i, j);
						sudo[i][j] = 0;
					}
				}
				if(!flag)
					return false;
				return true;
			}
			if(i == 8 && j == 8){
				cnt++;
			}
		}
	}

	return true;
}

int main(void)
{
	int T = 1;
	while(cin >> sudo[0][0]){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(i == 0 && j == 0)
					continue;
				cin >> sudo[i][j];
			}
		}

		printf("Case %d: ", T++);

		if(!illegal()){
			printf("Illegal.\n");
			continue;
		}


		cnt = 0;
		dfs(0, 0);

		if(cnt == 0)
			printf("Impossible.\n");
		else if(cnt == 1)
			printf("Unique.\n");
		else
			printf("Ambiguous.\n");
	}

	return 0;
}