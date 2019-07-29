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
#define maxn 10000

//structure
struct Item
{
    char alb;
    int num;

    Item(){
        num = 0;
    }

    bool operator< (const Item& rs)
    {
        if(num == rs.num)
            return alb < rs.alb;
        return num > rs.num;
    }
};
//declaration
int n;

string in;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> n;
    getline(cin, in);

    for(int j = 0; j < n; j++)
    {
       Item items[150];
        for(int i = (int)'a'; i <= (int)'z'; i++)
        {
            items[i].alb = char(i);
        }
        
        getline(cin, in);

        //in = "Computers account for only 5% of the country's commercial electricity consumption.";
        for(int i = 0; i < in.size(); i++)
        {
            if(isupper(in[i]))  in[i] = tolower(in[i]);
            if(islower(in[i]))
            {
                items[(int)in[i]].num++;
            }
        }

        sort(items, items+150);

        int maxa = items[0].num;

        for(int i = 0; i < 150; i++)
        {
            if(items[i].num != maxa)
                break;
            cout << items[i].alb;
        }
        cout << '\n';
        
    }

	return 0;
}