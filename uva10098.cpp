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
#define maxn 10+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif


	cin >> n;

    while(n--)
    {
        char str[maxn];

        scanf("%s", str);

        sort(str, str+strlen(str));

        do{
            printf("%s\n", str);
        }   while(next_permutation(str, str+strlen(str)));
        puts("");
    }

	return 0;
}