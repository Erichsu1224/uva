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
int a, f;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> n;

    while(n--)
    {
        cin >> a >> f;

        for(int i = 0; i < f; i++)
        {
            for(int j = 1; j <= a; j++)
            {
                for(int k = 1; k <= j; k++)
                {
                    cout << j;
                }
                cout << endl;
            }
            for(int j = a-1; j >= 1; j--)
            {
                for(int k = 1; k <= j; k++)
                {
                    cout << j;
                }
                cout << endl;
            }

            if(!n && i == f-1)
                break;
            cout << endl;
        }
    }

	return 0;
}