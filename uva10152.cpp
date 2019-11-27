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
vector<string> ori;
vector<string> tar;
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
        ori.clear();
        tar.clear();
        scanf("%d\n", &n);

        string str;
        REP(i, 1, n)
        {
            getline(cin, str);
            ori.PB(str);
        }

        REP(i, 1, n)
        {
            getline(cin, str);
            tar.PB(str);
        }

        int start = n-1;
        int target = n-1;

        while(true)
        {
            if(ori[start] == tar[target])
            {
                start--;
                target--;
            }

            else
            {
                start--;
            }
            if(start == -1)
                break;
        }

        REPP(i, target, 0)
        {
            cout << tar[i] << '\n';
        }
        puts("");
    }

	return 0;
}