#include <bits/stdc++.h>
using namespace std;

#define maxn 250+5

char fig[maxn][maxn];

int main(void){
	int n, m;
	int x, x_, y, y_;
	string name;
	char type, tmp;

	string str;

	while(getline(cin, str)){
		stringstream ss(str);

		ss >> type;

		if(type == 'X')
			break;
		if(type == 'I'){
			ss >> n >> m;
			for(int i = 1; i <= m; i++){
				for(int j = 1; j <= n; j++)
					fig[i][j] = 'O';
			}
		}
		if(type == 'C'){
			for(int i = 1; i <= m; i++){
				for(int j = 1; j <= n; j++)
					fig[i][j] = 'O';
			}
		}
		if(type == 'L'){
			ss >> x >> y >> tmp;
			fig[x][y] = tmp;
		}
		if(type == 'V'){
			ss >> x >> y >> y_ >> tmp;

			for(int i = min(y, y_); i <= max(y, y_); i++)
				fig[i][x] = tmp;
		}
		if(type == 'H'){
			ss >> x >> x_ >> y >> tmp;

			for(int i = min(x, x_); i <= max(x, x_); i++)
				fig[y][i] = tmp;
		}
		if(type == 'K'){
			ss >> x >> x_ >> y >> y_ >> tmp;

			for(int i = min(x, y); i <= max(x, y); i++)
				for(int j = min(x_, y_); j <= max(x_, y_); j++)
					fig[j][i] = tmp;
		}
		if(type == 'F'){
			ss >> x >> y >> tmp;
			char hold = fig[x][y];

			for(int i = 1; i <= m; i++){
				for(int j = 1; j <= n; j++)
					if(fig[i][j] == hold)
						fig[i][j] = tmp;
			}
		}
		if(type == 'S'){
			ss >> name;

			cout << name << '\n';

			// cout << n << ' ' << m << '\n';

			for(int i = 1; i <= m; i++){
				for(int j = 1; j <= n; j++)
					cout << fig[i][j];
				cout << '\n';
			}
		}

	}
}