#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define F first
#define S second
#define maxn 100000
#define MSET(x, y) memset(x, y, sizeof(x))
//structure

//declaration
bool prime[maxn];
int n;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    //prime table
    MSET(prime, true);
    prime[0] = prime[1] = false;

    REP(i, 2, 100000-1)
    {
        if(prime[i])
        {
            for(int j = i*2; j < 100000; j+=i)
                prime[j] = false;
        }
    }

    while(~scanf("%d", &n) && n)
    {
        int cnt = 0;
        for(int i = n; i >= 1; i--)
        {
            if(i < n-i)
                break;
            if(prime[i] && prime[n-i])
            {
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }

	return 0;
}