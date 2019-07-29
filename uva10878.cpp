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
string in;
int A, B;
//functions
int getbit(char a)
{
    if(a == ' ')
        return 0;
    return 1;
}

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    getline(cin, in);

    while(getline(cin, in))
    {
        if(in[0] == '_')
            break;
        A = getbit(in[1])*128+getbit(in[2])*64+getbit(in[3])*32+getbit(in[4])*16+getbit(in[5])*8;
        B = getbit(in[7])*4+getbit(in[8])*2+getbit(in[9])*1;
        //cout << A << ' ' << B << endl;
        cout << (char)(A+B);
    }
	return 0;
}