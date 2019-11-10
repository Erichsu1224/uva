#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define maxn 

//structure

//declaration
int T;
ll n;
ll arr[100000];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
    
    arr[0] = 0;

    REP(i, 1, 9)
        arr[i] = 1;
    REP(i, 10, 99)
        arr[i] = 2;
    REP(i, 100, 999)
        arr[i] = 3;
    REP(i, 1000, 9999)
        arr[i] = 4;
    REP(i, 10000, 99999)
        arr[i] = 5;

    REP(i, 1, 99999)
        arr[i] = arr[i]+arr[i-1];
    REP(i, 1, 99999)
        arr[i] = arr[i]+arr[i-1];




    scanf("%d", &T);

    while(T--)
    {
        scanf("%lld", &n);

        int l = 1, r = 99999;
        while(l <= r)
        {
            int mid = (l+r)/2;
            // printf("%d %lld\n", mid, arr[mid]);

            if(arr[mid] > n)
                r = mid-1;
            else
                l = mid+1;
        }

        // printf("%d ", l-1);

        if(n-arr[l-1] == 0)
            printf("%lld\n", (l-1)%10);
        else
        {
            ll tar = n-arr[l-1];

            for(int i = 1; ; i++)
            {
                int tmp = i;
                int k= 0 ;
                int hold[10];

                while(tmp >= 1)
                {
                    hold[k++] = tmp%10;
                    tmp /= 10;
                }

                if(tar <= k)
                {
                    printf("%d\n", hold[k-tar]);
                    break;
                }
                else
                    tar -= k;
            }
        }
    }   

	return 0;
}