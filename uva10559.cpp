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
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define all(x) x.begin(), x.end()
#define maxn 200+5

//structure

//declaration
vector<int> color;
vector<int> num;
int dp[maxn][maxn][maxn];
//functions

int DP(int l, int r, int k)
{
    if(l > r)
        return 0;

    if(dp[l][r][k] != -1)
        return dp[l][r][k];

    int ret = DP(l, r-1, 0)+ (num[r]+k)*(num[r]+k);

    for(int i = r-1; i >= l; i--)
    {
        if(color[i] == color[r])
            ret = max(ret, DP(l, i, num[r]+k)+DP(i+1, r-1, 0));
    }

    dp[l][r][k] = ret;

    return ret;
}

int main(void)
{
	IOS;
	
	#ifdef DEBUG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T;  cin >> T;
    int cases = 1;

    while(T--)
    {
        int n;  cin >> n;
        color.clear();
        num.clear();

        memset(dp, -1, sizeof(dp));

        int tmp;    cin >> tmp;
        color.PB(tmp);
        num.PB(1);

        for(int i = 1; i < n; i++)
        {
            cin >> tmp;

            if(tmp == color.back())
            {
                num.back()++;
                continue;
            }
            
            num.PB(1);
            color.PB(tmp);
        }

        cout << "Case " << cases++ << ": " << DP(0, num.size()-1, 0) << '\n';
    }

	return 0;
}