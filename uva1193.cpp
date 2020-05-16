#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define PDD pair<double, double> 

//structure

//declaration
int n;
vector<PDD> v;
double d, x, y;
//functions
double getdis(PDD a, PDD b)
{
    return sqrt((a.S-b.S)*(a.S-b.S)+(a.F-b.F)*(a.F-b.F));
}

bool check(PDD a, PDD b)
{
    if(getdis(a, b) <= d)
        return true;
    return false;
}

bool cmp(PDD a, PDD b)
{
    double tmp1 = a.F+sqrt(d*d-a.S*a.S), tmp2 = b.F+sqrt(d*d-b.S*b.S);
    if(tmp1 == tmp2)
        return a.S < b.S;
    return tmp1 < tmp2;
}


int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;
    int cases = 1;

    while(cin >> n >> d)
    {
        if(!n && !d)
            break;
        v.clear();
        bool flag = true;

        REP(i, 1, n)
        {
            cin >> x >> y;
            v.EB(MP(x, y));

            if(y > d)
                flag = false;
        }

        if(!flag)
        {
            cout << "Case " << cases++ << ": " << -1 << '\n';
            continue;
        }

        sort(all(v), cmp);

        double now = -1e9;
        int total = 0;

        for(int i = 0; i < v.size(); i++)
        {
            if(!check(v[i], MP(now, 0)))
            {
                total++;
                now = v[i].F+sqrt((d*d-v[i].S*v[i].S));
            }
        }

        cout << "Case " << cases++ << ": " << total << '\n';
    }

	return 0;
}