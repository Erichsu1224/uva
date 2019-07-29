#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure

//declaration
string in;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(getline(cin, in))
    {
        bool flag = 0;
        int counter = 0;

        for(int i = 0; i < in.size(); i++)
        {
            if(isalpha(in[i]) && !flag)
            {
                counter++;
                flag = true;
            }

            else if(!isalpha(in[i]) && flag)
            {
                flag = false;
            }
        }

        cout << counter << '\n';
    }

	return 0;
}