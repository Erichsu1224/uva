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
#define maxn 500+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

template <typename T>
struct KM
{
    int n;
    int Left[maxn];
    T w[maxn][maxn], Lx[maxn], Ly[maxn];
    bitset<maxn> vx, vy;
    
    void init(int _n)
    {
        n = _n;
    }

    bool match(int i)
    {
        vx[i] = true;
        for (int j = 1; j <= n; j++)
        {
            if ((fabs(Lx[i] + Ly[j] - w[i][j]) < 1e-9) && !vy[j])
            {
                vy[j] = 1;
                if (!Left[j] || match(Left[j]))
                {
                    Left[j] = i;
                    return true;
                }
            }
        }
        return false;
    }

    void update()
    {
        T a = 1e9;
        for (int i = 1; i <= n; i++)
        {
            if (vx[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!vy[j])
                    {
                        a = min(a, Lx[i] + Ly[j] - w[i][j]);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vx[i])
            {
                Lx[i] -= a;
            }
            if (vy[i])
            {
                Ly[i] += a;
            }
        }
    }

    void hungarian()
    {
        for (int i = 1; i <= n; i++)
        {
            Left[i] = Lx[i] = Ly[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                Lx[i] = max(Lx[i], w[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            while (1)
            {
                vx.reset();
                vy.reset();
                if (match(i))
                {
                    break;
                }
                update();
            }
        }
    }
};


//declaration
int n;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

    KM<int> km;
    while(cin >> n)
    {
        km.init(n);

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> km.w[i][j];
            }
        }

        km.hungarian();

        int ans = 0;

        for(int i = 1; i <= n; i++){
            cout << km.Lx[i];
            if(i != n)
                cout << ' ';
            else
                cout << '\n';
            ans += km.Lx[i];
        }
        for(int i = 1; i <= n; i++){
            cout << km.Ly[i];
            if(i != n)
                cout << ' ';
            else
                cout << '\n';
            ans += km.Ly[i];
        }

        cout << ans << '\n';
    }
    return 0;

	return 0;
}