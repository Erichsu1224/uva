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
#define maxn

//structure

//declaration
int n;
int T;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    T = 1;

    while(cin >> n && n)
    {
        vector<int> v;
        int total = 0;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;

            v.PB(tmp);

            total += tmp;
        }

        total /= n;
        for(int i = 0; i < n; i++)
        {
            count += abs(total - v[i]);
        }

        cout << "Set #" << T++ << '\n';
        cout << "The minimum number of moves is " << count/2 << ".\n\n";
    }

	return 0;
}