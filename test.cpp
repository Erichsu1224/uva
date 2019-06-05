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
#define maxn 1000+5

int stick[maxn];
bool used[maxn];
int n, total;

bool cmp(int a, int b)
{
    return a > b;
}

bool dfs(int index, int counter, int now, int t)
{
    if(now == t)
    {
        if(counter == n)
        {
            return true;
        }

        else
            now = 0;
    }

    if(!now)
    {
        for(index = 0; used[index]; index++);
        used[index] = true;
        if(dfs(index+1, counter+1, now+stick[index], t))
            return true;
        used[index] = false;
    }

    else
    {
        for(int i = index; i < n ; i++)
        {
            if(used[i] || (i && stick[i] == stick[i-1] && !used[i-1]))
                continue;
            if(now + stick[i] <= t)
            {
                used[i] = true;
                if(dfs(i+1, counter+1, now+stick[i], t))
                {
                    return true;
                }

                used[i] = false;
            }
        }
    }

    return false;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(~scanf("%d", &n) && n)
    {
        total = 0;

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &stick[i]);
            total += stick[i];
        }

        //memset(used, 0, sizeof(used));

        sort(stick, stick+n, cmp);
        fill(used, used+n, false);
        //test
        for(int i = stick[0]; i <= total; i++)
        {
            if(total % i == 0)
            {
                if(dfs(0, 0, 0, i))
                {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
	return 0;
}