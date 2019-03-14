#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long
#define C cases
#define pb push_back

bool can(int a)
{
	return a == 10 || a == 20 || a == 30;
}


int main(void)
{

	#ifndef compile
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif


	deque<int> deck;
	vector<int> q[7];

	int tmp;

	while(scanf("%d", &tmp) && tmp != 0)
	{
		int counter = 0;
		bool status[7];
		int sta_counter = 0;

		memset(status, true, sizeof(status));
		deck.clear();
		deck.pb(tmp);

		for(int i = 0; i < 51; i++)
		{
			scanf("%d", &tmp);
			deck.pb(tmp);
		}
		while(1)
		{
			for(int i = 0; i < 7; i++)
			{
				if(status[i] == false)
				{
					continue;
				}
				q[i].pb(deck.front());
				deck.pop_front();
				counter++;

				cout << q[i].size() << '|';
				//test
				for(int k = 0; k < q[i].size(); k++)
				{
					cout << q[i][k] << ' ';
				}
				cout << endl;

				if(q[i].size() >= 3)
				{				
					if(can(q[i][0]+q[i][1]+q[i][q[i].size()-1]) == true)
					{
						printf("\rY\n");
						deck.pb(q[i][0]);
						deck.pb(q[i][1]);
						deck.pb(q[i][q[i].size()-1]);
						
						q[i].erase(q[i].begin());
						q[i].erase(q[i].begin());
						q[i].erase(q[i].end()-1);
						
					}
					
					else if(can(q[i][0]+q[i][q[i].size()-2]+q[i][q[i].size()-1]) == true)
					{
						deck.pb(q[i][0]);
						q[i].erase(q[i].begin());
						deck.pb(q[i][q[i].size()-1]);
						q[i].erase(q[i].end()-1);
						deck.pb(q[i][q[i].size()-1]);
						q[i].erase(q[i].end()-1);
					}

					else if(can(q[i][q[i].size()-3]+q[i][q[i].size()-2]+q[i][q[i].size()-1]) == true)
					{
						deck.pb(q[i][q[i].size()-1]);
						q[i].erase(q[i].end()-1);
						deck.pb(q[i][q[i].size()-1]);
						q[i].erase(q[i].end()-1);
						deck.pb(q[i][q[i].size()-1]);
						q[i].erase(q[i].end()-1);
					}
					
					if(q[i].size() == 0)
					{
						status[i] = false;
						sta_counter++;
					}
				}
				

				if(deck.size() == 0)
				{
					break;
				}
			}

			cout << endl;

			if(sta_counter == 7)
			{
				printf("Win : %d\n", counter);
				break;
			}

			if(deck.size() == 0)
			{
				printf("Loss: %d\n", counter);
				break;
			}
		}

		cout << endl;
		
	}
	

	return 0;
}