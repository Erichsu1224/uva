#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure
struct Item
{
    int num, count, id;
};

//declaration
int n;
int counter;
set<int> S;
map<int, Item> M;
vector<int> v;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    counter = 1;

    while(cin >> n)
    {
        if(!S.count(n))
        {
            S.insert(n);
            M[n] = (Item){n, 1, counter++};
            v.PB(n);
        }

        else
        {
            M[n].count++;
        }  
    }

    for(int i = 0; i < v.size(); i++)
    {
        int idx = v[i];
        cout << idx << ' ' << M[idx].count << '\n';
    }
}