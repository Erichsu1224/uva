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
#define maxn 100005

struct Point
{
    int x, y, w, d;

    Point()
    {
        x = y = w = d = 0;
    }
};

Point p[maxn];
int sumd[maxn], sumw[maxn], dp[maxn];
int T, n, w;

int dist(Point a, Point b)
{
    return abs(a.x-b.x) + abs(a.y-b.y);
}

int func(int j)
{
    return dp[j]-sumd[j+1]+p[j+1].d;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;

    while(T--)
    {
        cin >> w >> n;

        for(int i = 1; i <= n; i++)
        {
            cin >> p[i].x >> p[i].y >> p[i].w;

            p[i].d = dist(p[0], p[i]);
            sumd[i] = sumd[i-1] + dist(p[i], p[i-1]);
            sumw[i] = sumw[i-1] + p[i].w;
        }

        deque<int> Q;
        Q.PB(0);

        for(int i = 1; i <= n; i++)
        {
            while(!Q.empty() && sumw[i] - sumw[Q.front()] > w)
            {
                Q.pop_front();
            }
            dp[i] = sumd[i]+p[i].d+func(Q.front());

            while(!Q.empty() && func(i) <= func(Q.back()))
            {
                Q.pop_back();
            }
            Q.PB(i);
        }

        cout << dp[n] << '\n';
    }

	return 0;
}