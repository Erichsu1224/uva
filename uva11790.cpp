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
#define C cases
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn 1000000

//structure
struct Item
{
    int h, w;
};
//declaration
int T, n;
int maxh, minh;
Item house[maxn];
int lis[maxn];
int lds[maxn];
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
        memset(lis, 0, sizeof(lis));
        memset(lds, 0, sizeof(lds));
        maxh = minh = 0;

        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> house[i].h;
        }

        for(int i = 0; i < n; i++)
        {
            cin >> house[i].w;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(house[j].h < house[i].h)
                {
                    lis[i] = max(lis[j], lis[i]);
                }
            }
            lis[i] += house[i].w;

            if(maxh < lis[i])
                maxh = lis[i];
        }

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = n-1; j >= i; j--)
            {
                if(house[j].h < house[i].h)
                {
                    lds[i] = max(lds[j], lds[i]);
                }
            }
            lds[i] += house[i].w;

            if(minh < lds[i])
                minh = lds[i];
        }

        if(maxh >= minh)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", cases, maxh, minh);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", cases, minh, maxh);
    }

	return 0;
}