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
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> n && n)
    {
        int total = 0;
        priority_queue< int,vector<int>,greater<int> > Q;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            Q.push(tmp);
        }

        while(!Q.empty())
        {
            int a = Q.top(); Q.pop();
            if(Q.empty()) break;
            int b = Q.top(); Q.pop();

            total += (a+b);
            Q.push(a+b);
        }

        cout << total << '\n';
    }

	return 0;
}