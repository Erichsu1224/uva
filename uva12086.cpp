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
#define maxn 200000+5

//structure

//declaration
int n;
int arr[maxn];
int seg[1000000];

//functions

int build(int now, int l, int r)
{
    if(l == r)
    {
        seg[now] = arr[l];
    }
    
    else
        seg[now] = build(now*2, l, (l+r)/2)+build(now*2+1, (l+r)/2+1, r);

    return seg[now];
}

int query(int now, int l, int r, int st, int ed)
{
    // cout << l << ' ' << r <<endl;

    if(st <= l && r <= ed || l == r)
        return seg[now];

    int ans = 0;
    if(st <= (l+r)/2)
        ans += query(now*2, l, (l+r)/2, st, ed);
    if(ed > (l+r)/2)
        ans += query(now*2+1, (l+r)/2+1, r, st, ed);
    return ans;

    // return query(now*2, l, (l+r)/2, st, ed)+query(now*2+1, (l+r)/2+1, r, st, ed);
}

int update(int now, int l, int r, int tar, int data)
{
    // cout << l << ' ' << r << endl;

    if(l == r)
        seg[now] = data;
    
    else if(tar <= (l+r)/2)
        seg[now] = update(now*2, l, (l+r)/2, tar, data)+seg[now*2+1];
    else if(tar > (l+r)/2)
        seg[now] = update(now*2+1, (l+r)/2+1, r, tar, data)+seg[now*2];
    
    return seg[now];
}
int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int k = 0;

    while(~scanf("%d", &n) && n)
    {
        if(k++)
            puts("");
        printf("Case %d:\n", k);

        REP(i, 1, n)
            scanf("%d", &arr[i]);
        
        build(1, 1, n);
        string type;

        while(cin >> type)
        {
            // cout << type << endl;
            // REP(i, 1, n*4)
            //     printf("%d ", seg[i]);
            // printf("\n");

            if(type[0] == 'E')
                break;
            
            int x, y;
            scanf("%d %d", &x, &y);

            // cout << type << ' ' << x << ' ' << y << endl;

            if(type[0] == 'M')
            {
                printf("%d\n", query(1, 1, n, x, y));
            }

            if(type[0] == 'S')
                update(1, 1, n, x, y);
        }
    }

	return 0;
}