#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <vector>
using namespace std;

typedef set<int> Set;

map<Set, int> IDcache;
vector<Set > Setcache; //維護

int ID(set<int> x)
{
    if(IDcache.count(x))
        return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size()-1;
} 

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

int main(void)
{
    stack<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string op;
        cin >> op;

        if(op[0] =='P')
            s.push(ID(Set()));
    }
}