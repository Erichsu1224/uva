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
#define maxn 100000+5

struct Item
{
    int x, y, weight, dist;
    Item()
    {
        x = y = weight = dist = 0;
    }
};

Item point[maxn];
int sumd[maxn];
int sumw[maxn];
int dp[maxn];

int dis(Item a, Item b)
{
    return abs(a.x-b.x)+abs(a.y)-b.y;
}

int func(int j)
{
    return point[j+1].dist-sumd[j+1]+dp[j];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T;

    cin >> T;

    while(T--)
    {
        int c, n;

        cin >> c >> n;

        for(int i = 1; i <= n; i++)
        {
            cin >> point[i].x >> point[i].y >> point[i].weight;
            point[i].dist = dis(point[i], point[0]);

            sumd[i] = sumd[i-1]+dis(point[i], point[i-1]);
            sumw[i] = sumw[i-1]+point[i].weight;
        }

        deque<int> Q;
        Q.PB(0);

        for(int i = 1; i <= n; i++)
        {
            while(!Q.empty() && sumw[i] - sumw[Q.front()] > c)
            {
                Q.pop_front();
            }
            dp[i] = func(Q.front())+sumd[i]+point[i].dist;

            while(!Q.empty() && func(i) <= func(Q.back()))
            {
                Q.pop_back();
            }
            Q.PB(i);
        }

        cout << dp[n] << '\n';

        if(T)   cout << '\n';
    }

	return 0;
}