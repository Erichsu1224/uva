#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
<<<<<<< HEAD
#include <deque>
=======
>>>>>>> 1f8161f2bbca603a7959c8ddc34ba9007e894f18
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
<<<<<<< HEAD
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure

//declaration
vector<int> v[8];
vector<int> deck;
int tmp;
//functions
bool case_A(int i)
{
    int tmp = v[i][0]+v[i][1]+v[i].back();

    if(tmp == 10 || tmp == 20 || tmp == 30)
    {
        v[i].erase(v[i].begin(), v[i].begin()+2);
        v[i].erase(v[i].end());
        return true;
    }
        
    return false;
}

bool case_B(int i)
{
    int tmp = v[i][0]+v[i][v.size()-2]+v[i].back();

    if(tmp == 10 || tmp == 20 || tmp == 30)
    {
        v[i].erase(v[i].begin());
        v[i].erase((v[i].begin()+v.size()-2), v[i].end());
        return true;
    }
        
    return false;
}

bool case_C(int i)
{
    int tmp = v[i][v.size()-3]+v[i][v.size()-2]+v[i].back();

    if(tmp == 10 || tmp == 20 || tmp == 30)
    {
        v[i].erase(v[i].begin()+(v.size()-3), v[i].end());
        return true;
    }   
    return false;
}
=======
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

>>>>>>> 1f8161f2bbca603a7959c8ddc34ba9007e894f18

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

<<<<<<< HEAD
    while(cin >> tmp && tmp)
    {
        deck.PB(tmp);

        for(int i = 0; i < 51; i++)
        {
            cin >> tmp;
            deck.PB(tmp);
        }

        while(true)
        {
            for(int i = 0; i < 7; i++)
            {
                if(!deck.size())
                {
                    
                }
                v[i].PB(deck.front());
                deck.erase(deck.begin());
                if(case_A(i))
            }

        }
=======
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
        
>>>>>>> 1f8161f2bbca603a7959c8ddc34ba9007e894f18
    }

	return 0;
}