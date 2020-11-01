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
#define maxn 20
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
bool fig[maxn][maxn];
int row[maxn], col[maxn], sd[maxn], su[maxn];
int arr[10];
int cnt;
//function s

void dfs(int x, int y, int queen){

	if(queen == 8){

		printf("%2d     ", cnt++);

		for(int i = 1; i <= 8; i++){
			cout << ' ';
			cout << arr[i];
		}
		cout << '\n';

		return;
	}

	
	for(int j = y; j <= 8; j++){
		for(int i = 1; i <= 8; i++){
			if(!fig[i][j] && !row[i] && !col[j] && !sd[i+j] && !su[i-j+8]){
				fig[i][j] = true;
				row[i]++;
				col[j]++;
				sd[i+j]++;
				su[i-j+8]++;
				arr[j] = i;
				dfs(i, j, queen+1);
				fig[i][j] = false;
				row[i]--;
				col[j]--;
				sd[i+j]--;
				su[i-j+8]--;
			}
		}
	}
}

int main(void)
{
	int T;
	cin >> T;

	while(T--){
		int x, y;
		cin >> x >> y;
		memset(fig, false, sizeof(fig));
		memset(row, false, sizeof(row));
		memset(col, false, sizeof(col));
		memset(sd, false, sizeof(sd));
		memset(su, false, sizeof(su));


		fig[x][y] = true;
		row[x]++;
		col[y]++;
		sd[x+y]++;
		su[x-y+8]++;
		
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		cnt = 1;
		arr[y] = x;
		dfs(1, 1, 1);

		if(T)
			cout << '\n';
	}

	return 0;
}