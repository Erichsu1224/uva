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
//#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxe 10000+5

//structure

//declaration
int T;
int b, e;
int prefix[maxe];

//function
void solve(void)
{
    prefix[0] = 0;
    for(int i = 1; i <= 10000; i++)
    {
        int tmp = i, counter = 0;

        while(tmp >= 1)
        {
            if(tmp % 2 == 1)
                counter++;
            tmp /= 2;
        }

        prefix[i] = prefix[i-1]+counter;
        
    }
}


int main(void)
{
	//IOS;
	
	#ifndef DEBUG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    solve();

    cin >> T;

    while(T--)
    {
        cin >> b >> e;
        cout << prefix[e]-prefix[b-1] << '\n';
    }

	return 0;
}