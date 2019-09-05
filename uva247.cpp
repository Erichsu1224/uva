#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn 25+5

//structure

//declaration
int n, m;
map<string, int> M;
set<string> S;
string a, b;
//functions

int arr[maxn];

void init(int n) // give a initial length
{
	for(int i=0; i<n; i++)
		arr[i] = -1;
}

int find(int x)
{ // find the father point
	return arr[x] < 0 ? x : (arr[x] = find(arr[x])); // update every child to the other father
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if(x == y)
		return;

	if(arr[x] <= arr[y])
	{
		arr[x] += arr[y];
		arr[y] = x;
	}
	else
	{
		arr[y] += arr[x];
		arr[x] = y;
	}
}

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> n >> m && n && m)
    {
        init(n);

        int counter = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            if(!S.count(a))
            {
                S.insert(a);
                M[a] = counter++;;
            }

            if(!S.count(b))
            {
                S.insert(b);
                M[b] = counter++;
            }

            Union(M[a], M[b]); 
        }

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;

        for(int i = 0; i < )
    }

	return 0;
}