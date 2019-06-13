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
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define maxn 100000+5

//structure
struct rub
{
    double left, right;

    bool operator<(const rub& rs)const{
        if(left == rs.left)
            return right < rs.right;
        return left < rs.left;
    }
};

//declaration
int n;
rub r[maxn];
//functions
bool solve(double d)
{
    double now = r[0].left+d;

    if(now > r[0].right)
        return false;

    for(int i = 1; i < n; i++)
    {
        now = max(now, r[i].left)+d;

        if(now > r[i].right)
            return false;
    }

    return true;
}


int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
            //cin >> r[i].left >> r[i].right;
            scanf("%lf %lf", &r[i].left, &r[i].right);


        //for(int i = 0; i < n; i++)
        //    cout << r[i].left << ' ' << r[i].right << '\n';
        
        sort(r, r+n);

        double left = 0, right = 1000000;
        double ans = 0.0;

        while((right-left) > 1e-9)
        {
            //cout << (right+left)/2.0 << endl;
            if(solve((right+left)/2.0))
            {              
                ans = (double)(right+left)/2.0;
                left = (right+left)/2.0;
            }

            else
                right = (right+left)/2.0;
        }

        int rp = 0, rq = 1;

        for(int p, q = 1; q <= n; ++q){
            p = round(ans * q);
            if(fabs((double)p/q - ans) < fabs((double)rp/rq - ans)){
                rp = p;  rq = q; 
            }
        }
 
        printf("%d/%d\n", rp, rq);
        
    }

	return 0;
}