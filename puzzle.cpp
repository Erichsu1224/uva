#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define ARCC array<array<char, 5>, 5>

bool check(ARCC a, ARCC b)
{
    bool flag = true;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if((a[i][j]=='*' && b[i][j] =='*') || (a[i][j]=='.' && b[i][j] =='.'))
            {
                flag = false;
                break;
            }
    return flag;
}

bool check_Border(ARCC a, bool dir, bool x)
{
    bool flag = true;
    int idx;
    if(x) idx = 0;
    else idx = 2;
    if(dir)
    {
        for(int i = 0; i < 3; i++)
        {
            if(a[idx][i] == '*')
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            if(a[i][idx] == '*')
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

ARCC move(ARCC a, bool dir, bool section)
{
    if(dir)
    {
        if(section)
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                {
                    if(i == 2)  a[i][j] = '.';
                    else    a[i][j] = a[i+1][j];
                }
        else
            for(int i = 2; i >= 0; i--)
                for(int j = 0; j < 3; j++)
                {
                    if(i == 0)  a[i][j] = '.';
                    else    a[i][j] = a[i-1][j];
                }
    }
    else
    {
        if(section)
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                {
                    if(i == 2)  a[j][i] = '.';
                    else    a[j][i] = a[j][i+1];
                }
        else
            for(int i = 2; i >= 0; i--)
                for(int j = 0; j < 3; j++)
                {
                    if(i == 0)  a[j][i] = '.';
                    else    a[j][i] = a[j][i-1];
                }
    }
    return a;
}

ARCC turn(ARCC a)
{
    ARCC tmp;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if(i == 0)
                tmp[j][2] = a[i][j];
            else if(i == 1)
                tmp[j][1] = a[i][j];
            else
                tmp[j][0] = a[i][j];
        }
    return tmp;
}

int main(void)
{
    ARCC puz_a, puz_b, tmp;
    bool flag = false;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> puz_a[i][j];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> puz_b[i][j];

    queue<pair<ARCC, ARCC>> q;
    map<pair<ARCC, ARCC>, int> mp;

    q.push(make_pair(puz_a, puz_b));

    while(!q.empty())
    {
        pair<ARCC, ARCC> now = q.front(); q.pop();

        if(check(now.first, now.second))
        {
            flag = true;
            break;
        }

        mp[now]++;

        for(int i = 1; i >= 0; i--)
        {
            for(int j = 1; j >= 0; j--)
            {
                if(check_Border(now.first, i, j))
                {
                    tmp = move(now.first, i, j);
                    for(int k = 0; k < 4; k++)
                    {
                        tmp = turn(tmp);
                        if(!mp[make_pair(tmp, now.second)])
                            q.push(make_pair(tmp, now.second));
                    }
                }
                if(check_Border(now.second, i, j))
                {
                    tmp = move(now.second, i, j);
                    for(int k = 0; k < 4; k++)
                    {
                        tmp = turn(tmp);
                        if(!mp[make_pair(now.first, tmp)])
                            q.push(make_pair(now.first, tmp));
                    }
                }
            }
        }
    }
    
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}