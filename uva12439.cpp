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

//structure

//declaration

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T;
    scanf("%d\n", &T);

    while(T--){
        string month;
        int day, year;
        int start, end;

        cin >> month;
        scanf("%d, %d\n", &day, &start);

        start

        cin >> month;
        scanf("%d, %d\n", &day, &year);

        cout << month << ' ' << day << ' ' << year << '\n';
    }
	

	return 0;
}