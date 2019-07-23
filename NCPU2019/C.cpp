#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn 100000+5

//structure

//declaration
int* addr[maxn];
list<int> L;
int n, m;
int type;

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
        L.clear();

        for(int i = 1; i <= n; i++)
        {
            L.PB(i);
            addr[i] = i;
        }

        for(int i = 0; i < m; i++)
        {
            cin >> type;
            switch(type)
            {
                case 1:
                {

                    break;
                }

                case 2:
                {
                    break;
                }

                case 3:
                {
                    break;
                }

                case 4:
                {
                    break;
                }
            }
        }
    }
    

	return 0;
}