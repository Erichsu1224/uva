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
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define maxn 15+5

//structure

//declaration
int T, n, cnt;
int arr[maxn];
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &n);

        REP(i, 1, n)
        {
            scanf("%d", &arr[i]);
        }
        bool flag = false;

        REP(i, 1, 1000)
        {
            cnt = 0;
            int tmp = arr[1];
            REP(j, 1, n-1)
            {
                arr[j] = abs(arr[j+1]-arr[j]);
                if(!arr[j])
                    cnt++;
            }

            arr[n] = abs(tmp-arr[n]);
            if(!arr[n])
                cnt++;

            if(cnt == n)
            {
                flag = true;
                break;
            }
        }

        if(flag)
            printf("ZERO\n");
        if(!flag)
            printf("LOOP\n");


    }

	return 0;
}