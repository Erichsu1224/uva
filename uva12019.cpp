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
#define EB emplace_back
#define maxn

//structure

//declaration
int T, n, m;
string day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
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
        scanf("%d %d", &n, &m);

        if(n == 1 || n == 10)
        {
            cout << day[(6+m-1)%7] << '\n';
        }

        else if(n == 2 || n == 3 || n == 11)
        {
            cout << day[(2+m-1)%7] << '\n';
        }

        else if(n == 4 || n == 7)
        {
            cout << day[(5+m-1)%7] << '\n';
        }

        else if(n == 5)
        {
            cout << day[(m-1)%7] << '\n';
        }

        else if(n == 6)
        {
            cout << day[(3+m-1)%7] << '\n';
        }

        else if(n == 8)
        {
            cout << day[(1+m-1)%7] << '\n';
        }

        else if(n == 9 || n == 12)
        {
            cout << day[(4+m-1)%7] << '\n';
        }
    }

	return 0;
}