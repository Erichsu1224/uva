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
#define maxn

//structure

//declaration
int T;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;
    
    for(int cases = 1; cases <= T; cases++)
    {
        ll st[3];

        cin >> st[0] >> st[1] >> st[2];

        sort(st, st+3);

        printf("Case %d: ", cases);

        if(st[0] + st[1] <= st[2] || st[0] <= 0)   cout << "Invalid\n";

        else if (st[0] == st[1] &&  st[1] == st[2])
            cout << "Equilateral\n";
        else if(st[0] == st[1] || st[1] == st[2])
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";

    }

	return 0;
}