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
#define maxn 1000000+5
#define maxm 1000+5

//structure

//declaration
int T, n, m, k;
int arr[maxn];
int cnt[maxm];
int cnt_num;
int cases;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d", &T);
    cases = 1;

    while(T--)
    {
        printf("Case %d: ", cases++);
        scanf("%d %d %d", &n, &m, &k);

        arr[1] = 1; arr[2] = 2; arr[3] = 3;

        REP(i, 4, n)
        {
            arr[i] = ((arr[i-3]+arr[i-2]+arr[i-1])%m)+1;
        }

        int l = 1, r = 1;
        cnt_num = 0;
        int ans = 1e9;
        MSET(cnt, 0);

        // REP(i, 1, n)
        //     cout << arr[i] << ' ';
        // cout << endl;


        while(r <= n && l <= n)
        {
            
            if(cnt_num < k)
            {
                cnt[arr[r]]++;

                if(cnt[arr[r]] == 1 && arr[r] <= k)
                {
                    cnt_num++;
                }

                r++;
            }

            if(cnt_num == k)
            {
                ans = min(ans, r-l);
            }

            if(cnt_num >= k  && l <= r)
            {
                cnt[arr[l]]--;

                if(cnt[arr[l]] == 0 && arr[l] <= k)
                {
                    cnt_num--;
                }

                l++;
            }
        }
        if(ans == 1e9)
            printf("sequence nai\n");
        else
            printf("%d\n", ans);
    }

	return 0;
}