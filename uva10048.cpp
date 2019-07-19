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
#define maxn 100+5

//structure

//declaration
int n, s, q;
int counter;
int graph[maxn][maxn];
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    counter = 1;

    while(cin >> n >> s >> q && n)
    {
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = 1e9;
            }
        }

        for(int i = 0; i < s; i++)
        {
            int from, to, w;
            cin >> from >> to >> w;

            graph[from][to] = graph[to][from] = w;
        }

        for(int k = 1; k <= n; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    if(i == j)  continue;
                    
                    int tmp = max(graph[i][k], graph[k][j]);
                    if(graph[i][j] > tmp)
                        graph[i][j] = graph[j][i] = tmp;
                    
                }
            }
        }

        if(counter != 1)
            cout << '\n';

        cout << "Case #" << counter++ << '\n';
        for(int i = 0; i < q; i++)
        {
            int from, to;
            cin >> from >> to;

            if(graph[from][to] == 1e9)
                cout << "no path\n";
            else
                cout << graph[from][to] << '\n';
        }
    }

	return 0;
}