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
#define all(x) x.begin(), x.end()
#define maxn 22+5

//structure

//declaration
int n, m;
int T;
string name[maxn];
int dp[maxn][maxn];
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    T = 1;

    while(cin >> n >> m && n && m)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1e9;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> name[i];
        }

        for(int i = 0; i < m; i++)
        {
            int f, t, w;
            cin >> f >> t >> w;

            dp[f][t] = dp[t][f] = w;
        }

        int target, tmp = 1e9;

        for(int k = 1; k <= n; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                int hold = 0;
                for(int j = 1; j <= n; j++)
                {
                    dp[i][j] = min(dp[i][k]+dp[k][j], dp[i][j]);
                    hold += dp[i][j];
                }

                if(hold <= tmp)
                {
                    if(hold < tmp)
                    {
                        tmp = hold;
                        target = i;
                    }
                    
                    // else if(hold == tmp)
                    // {
                    //     if(target < i)
                    //     {
                    //         target = i;
                    //     }
                    // }
                }
            }
        }

        printf("Case #%d : ", T++);
        cout << name[target] << '\n';
    }

	return 0;
}