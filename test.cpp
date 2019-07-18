#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure

//declaration
vector<int> v[8];
vector<int> deck;
int tmp;
//functions
bool case_A(int i)
{
    int tmp = v[i][0]+v[i][1]+v[i].back();

    if(tmp == 10 || tmp == 20 || tmp == 30)
    {
        v[i].erase(v[i].begin(), v[i].begin()+2);
        v[i].erase(v[i].end());
        return true;
    }
        
    return false;
}

bool case_B(int i)
{
    int tmp = v[i][0]+v[i][v.size()-2]+v[i].back();

    if(tmp == 10 || tmp == 20 || tmp == 30)
    {
        v[i].erase(v[i].begin());
        v[i].erase((v[i].begin()+v.size()-2), v[i].end());
        return true;
    }
        
    return false;
}

bool case_C(int i)
{
    int tmp = v[i][v.size()-3]+v[i][v.size()-2]+v[i].back();

    if(tmp == 10 || tmp == 20 || tmp == 30)
    {
        v[i].erase(v[i].begin()+(v.size()-3), v[i].end());
        return true;
    }   
    return false;
}

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> tmp && tmp)
    {
        deck.PB(tmp);

        for(int i = 0; i < 51; i++)
        {
            cin >> tmp;
            deck.PB(tmp);
        }

        while(true)
        {
            for(int i = 0; i < 7; i++)
            {
                if(!deck.size())
                {
                    
                }
                v[i].PB(deck.front());
                deck.erase(deck.begin());
                if(case_A(i))
            }

        }
    }

	return 0;
}