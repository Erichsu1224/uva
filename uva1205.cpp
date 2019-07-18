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
#define maxn 1000+5

//structure
struct Item
{
    double w;
    int t;
};

//declaration
int n, root, ans;
int A[maxn];
int father[maxn];
bool visit[maxn];
Item items[maxn];
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> n >> root && n && root)
    {
        ans = 0;
        memset(father, 0, sizeof(father));
        memset(visit, false, sizeof(visit));
        priority_queue< pair<double, int> > Q;

        for(int i = 1; i <= n; i++)
        {
            cin >> A[i];

            items[i].t = 1;
            items[i].w = (double)A[i];
            ans += A[i];

            if(i == root)
                continue;
            Q.push(make_pair(items[i].w, i));
        }

        for(int i = 1; i <= n-1; i++)
        {
            int a, b;
            cin >> a >> b;

            father[b] = a;
        }

        for(int i = 1; i < n; i++)
        {
            int x = Q.top().second;
            Q.pop();

            while((visit[x] || x == root))
            {
                x = Q.top().second;
                Q.pop();
            }

            visit[x] = 1;

            ans += A[x]*items[father[x]].t;

            for(int j = 1; j <= n; j++)
            {
                if(father[j] == x)
                    father[j] = father[x];
            }

            items[father[x]].t += items[x].t;
            A[father[x]] += A[x];
            items[father[x]].w = (double)A[father[x]]/items[father[x]].t;
            Q.push(make_pair(items[father[x]].w, father[x]));
        }

        cout << ans << '\n';
    }

	return 0;
}v