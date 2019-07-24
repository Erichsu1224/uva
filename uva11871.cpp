#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn 2000+5

//structure
struct Item
{
    int w, loc;
};

//declaration
int T;
int max_total;
int r, c;
bool graph[maxn][maxn];
int g[maxn][maxn];
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;

    for(int cases = 1; cases <= T; cases++)
    {
        //init
        max_total = 0;
        memset(g, 0, sizeof(g));
        cin >> r >> c;

        for(int i = 1; i <= r; i++)
        {
            int k, flag, num;
            int counter = 1;

            cin >> k >> flag;

            for(int j = 0; j < k; j++)
            {
                int p;  cin >> p;

                for(int l = 0; l < p; l++)
                {
                    graph[i][counter++] = flag;
                }

                if(flag) flag = 0;
                else if(!flag)  flag = 1;    
            } 
        }

        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                if(graph[i][j])
                    g[i][j] = 0;
                else
                    g[i][j] = g[i][j-1]+1;
            }
        }
        
        //test
        
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                cout << graph[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                cout << g[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        

       
        for(int i = 1; i <= c; i++)
        {
            stack<Item> S;
            
            for(int j = 1; j <= r; j++)
            {   
                if(S.empty())
                {
                    S.push((Item){g[j][i], j});
                    continue;
                }

                while(!S.empty())
                {
                    Item tmp = S.top();
                    if(tmp.w < g[j][i])
                    {
                        S.push((Item){g[j][i], j});
                        break;
                    }

                    else if(tmp.w == g[j][i])
                        break;
                        
                    else if(tmp.w > g[j][i])
                    {
                        S.pop();
                        int hold = tmp.w*(j-tmp.loc);
                        //test
                        cout << hold << ' ' << tmp.w << ' ' << j << ' ' << tmp.loc << endl;
                        max_total = max(max_total, hold);
                    }
                } 
            }
            cout << endl;
        }
        cout << "Case " << cases << ": " << max_total << '\n';
        //printf("Case %d: %d\n", cases, max_total);
    }

	return 0;
}