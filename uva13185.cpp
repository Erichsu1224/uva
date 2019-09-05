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

//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int T;
    cin >> T;

    while(T--)
    {
        int in;
        int total = 1;

        cin >> in;

        for(int i = 2; i <= sqrt(in); i++)
        {
            if(in%i == 0)
            {
                total += i;
                if(in/i == i)
                    continue;
                total += in/i;
            }
        }

        if(in < total)
            cout << "abundant\n";
        else if(in == total)
            cout << "perfect\n";
        else
            cout << "deficient\n";
    }   

	return 0;
}