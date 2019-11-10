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
int T, n;
vector<int> v;
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
        v.clear();

        REP(i, 1, n)
        {
            int tmp;
            scanf("%d", &tmp);

            v.PB(tmp);
        }

        int order = 0;

        REP(i, 0, n-1)
        {
            REP(j, i+1, n-1)
            if(v[i] > v[j])
            {
                order++;
            }
        }

        if(n%2 && order%2)
            printf("impossible\n");
        else
            printf("possible\n");
    }

	return 0;
}