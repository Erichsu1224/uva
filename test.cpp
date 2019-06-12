#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn 500+5

//structure
struct Student
{
    int height;
    char sex;
    string music;
    string sport;
};

struct Item 
{
    int a, b;
};

//declaration
int T, n;
Student s[maxn];
set<int> boy;
set<int> girl;
//test
vector<Item> v;

//functions
bool check(int i, int j)
{
    if(abs(s[i].height-s[j].height) > 40)
        return true;
    if(s[i].sex == s[j].sex)
        return true;
    if(s[i].music != s[j].music)
        return true;
    if(s[i].sport == s[j].sport)
        return true;
    
    return false;
}

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;

    while(T--)
    {
        boy.clear();
        girl.clear();
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> s[i].height >> s[i].sex >> s[i].music >> s[i].sport;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                if(check(i,j) && s[i].sex == 'F' && s[j].sex == 'M')
                {
                    if(boy.count(i) || girl.count(j))
                        continue;
                    v.PB((Item){i, j});

                    boy.insert(i);
                    girl.insert(j);
                }
            }
        }
        cout << "vector" << endl;
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i].a << ' ' << v[i].b << endl;
        }

        set<int>::iterator it;

        cout << "boy:" << endl;
        for(it = boy.begin(); it != boy.end(); it++)
        {
            cout << *it << ' ';
        }
        cout << endl;

        cout << "girl:" << endl;
        for(it = girl.begin(); it != girl.end(); it++)
        {
            cout << *it << ' ';
        }
        cout << endl;

        //cout << n-se.size() << '\n';
/*
        for(int i = 0; i < n; i++)
        {
            cout << s[i].height << ' ' << s[i].sex << ' ' << s[i].music << ' ' << s[i].sport << '\n';
        }
*/
    }

	return 0;
}