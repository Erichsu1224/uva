#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn 50+5

//structure

//declaration
int c, r;
int gold;
int start_c, start_r;
char map[maxn][maxn];
bool visit[maxn][maxn];
//functions
void dfs(int r, int c)
{
    visit[r][c] = true;
    if(map[r][c] == 'G')
        gold++;
    
    if(map[r+1][c] == 'T' || map[r][c+1] == 'T' || map[r-1][c] == 'T' || map[r][c-1] == 'T')
        return;
    
    if((map[r+1][c] != 'T' && map[r+1][c] != '#') && !visit[r+1][c])    dfs(r+1, c);
    if((map[r][c+1] != 'T' && map[r][c+1] != '#') && !visit[r][c+1])    dfs(r, c+1);
    if((map[r-1][c] != 'T' && map[r-1][c] != '#') && !visit[r-1][c])    dfs(r-1, c);
    if((map[r][c-1] != 'T' && map[r][c-1] != '#') && !visit[r][c-1])    dfs(r, c-1);

    return;
}

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> c >> r)
    {
        memset(visit, false, sizeof(visit));
        gold = 0;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == 'P')
                {
                    start_c = i;
                    start_r = j;
                }
            }
        }

        dfs(start_c, start_r);
        
        cout << gold << endl;
    }

	return 0;
}