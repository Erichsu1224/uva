#include <iostream>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>

struct status
{
	int st[65];

	status()
	{
		memset(st, 0, sizeof(st));
	}

	bool operator< (const status& rs) const
	{
		return (memcmp(st, rs.st, sizeof(status)) < 0);
	}
};


deque <int> hand;
vector<int> st[7];
int counter = 0;
bool check[7];
int step = 0;
set <status> mem;

status setmem(void)
{
	status tmp;
	int k = 0;
	for(int i = 0; i < hand.size(); i++)
	{
		tmp.st[k++] = hand[i];
	}

	for(int i = 0; i < 7; i++)
	{
		tmp.st[k++] = 0;
		for(int l = 0; l < st[i].size(); l++)
		{
			tmp.st[k++] = st[i][l];
		}
	}

	return tmp;
}

bool check_st(int i)
{
	if((st[i][0]+st[i][1]+st[i].back())%10 == 0)
    {
        hand.PB(st[i][0]);
        hand.PB(st[i][1]);
        hand.PB(st[i].back());
        st[i].erase(st[i].begin(), st[i].begin()+2);
        st[i].pop_back();
        return true;
    }

    else if((st[i][0]+st[i][st[i].size()-2]+st[i].back())%10 == 0)
    {
        hand.PB(st[i][0]);
        hand.PB(st[i][st[i].size()-2]);
        hand.PB(st[i].back());
        st[i].erase(st[i].begin());
        st[i].pop_back();
        st[i].pop_back();
        return true;
    }

    else if((st[i][st[i].size()-3]+st[i][st[i].size()-2]+st[i].back())%10 == 0)
    {
        hand.PB(st[i][st[i].size()-3]);
        hand.PB(st[i][st[i].size()-2]);
        hand.PB(st[i].back());
        st[i].pop_back();
        st[i].pop_back();
        st[i].pop_back();
        return true;
    }
    return false;
}

int main(void)
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int n;

    while(~scanf("%d", &n) && n != 0)
    {

        hand.clear();
        for(int i = 0; i < 7; i++)
        {
        	st[i].clear();
        }
        counter = 0;
        step = 0;
        bool draw = false;

        memset(check, true, sizeof(check));
        hand.PB(n);

        for(int i = 0; i < 51; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            hand.PB(tmp);
        }

        while(!hand.empty() && !draw)
        {
        	
            if(counter == 7)
                break;
            if(step >= 1000)
                break;

            for(int i = 0; i < 7; i++)
            {
            	/*
            	cout << hand.size() << ' ' << counter << ' ';
        		cout << step << endl;
				*/
                if(hand.size() == 0)
                    break;

                if(!check[i])
                    continue;

                step++;

                int tmp = hand.front();
                hand.pop_front();

                st[i].PB(tmp);

                bool chk = true;
                while(st[i].size() >= 3 && chk)
                {
                    chk = check_st(i);
                }


                status s = setmem();
                if(mem.count(s) > 0)
                {
                	draw = true;
                	break;
                }
                else
                	mem.insert(s);

           
                if(st[i].size() == 0)
                {
                    counter++;
                    check[i] = false;
                }
            }  
        }

        if(hand.size() == 0)
        {
            printf("Loss: %d\n", step);
        }
        if(counter == 7)
        {
            printf("Win : %d\n", step);
        }
        if(draw)
        {
            printf("Draw: %d\n", step);
        }
    }
}