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
        string in;
        cin >> in;

        //cout << in << endl;

        if(in[in.size()-1]-'0' == 0 && in.size() == 1) 
        {
            cout << 1 << '\n';
            continue;
        }

        if(in[in.size()-1]-'0' == 1 && in.size() == 1) 
        {
            cout << 66 << '\n';
            continue;
        }

        switch ((in[in.size()-1]-'0') % 5)
        {
            case 2:
                cout << 56 << '\n';
                break;
            case 3:
                cout << 96 << '\n';
                break;
            case 4:
                cout << 36 << '\n';
                break;
            case 0:
                cout << 76 << '\n';
                break;
            case 1:
                cout << 16 << '\n';
                break;
            default:
                break;
        }
    }

	return 0;
}