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
#define maxn 1000+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n, m, l, r;
bool check[maxn];
vector<int> prime;
//functions

void getprime(int n)
{
    MSET(check, true);
    prime.clear();
    
    prime.EB(1);

    for(int i = 2; i <= n; i++)
    {
        if(check[i])
        {
            prime.EB(i);

            for(int j = i*i; j <= n; j += i)
            {
                check[j] = false;
            }
        }
    }
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

    while(cin >> n >> m)
    {
        getprime(n);

        cout << n << ' ' << m << ':';
        if(prime.size() % 2)
        {
            l = (prime.size()-1)/2-m+1;
            r = (prime.size()-1)/2+m-1;
            if(l < 0)
                l = 0;
            if(r >= prime.size())
                r = prime.size()-1;
            
            for(int i = l; i <= r; i++)
            {
                cout << ' ' << prime[i];
            }
        }
        else
        {
            l = prime.size()/2-m;
            r = (prime.size()/2-1)+m;
            if(l < 0)
                l = 0;
            if(r >= prime.size())
                r = prime.size()-1;

            for(int i = l; i <= r; i++)
            {
                cout << ' ' << prime[i];
            }
        }
        
        cout << "\n\n";
    }

	return 0;
}