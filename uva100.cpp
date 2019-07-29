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
#define maxn 1000000+5

//structure

//declaration
int n, m;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> n >> m)
    {
        int a = n, b = m;

        if(a > b)
            swap(a, b);
        int tmp = 0;
        for(int i = a; i <= b; i++)
        {
            int hold = i;
            int counter = 1;
            while(hold != 1)
            {
                if(hold % 2)
                    hold = hold*3+1;
                else
                    hold /= 2;
                counter++;
            }

            tmp = max(tmp, counter);
        }

        cout << n << ' ' << m << ' ' << tmp << '\n';
    }

	return 0;
}