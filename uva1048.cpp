//2016 World Final
//dijkstra
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 10+5 //2 to 10 cities

struct Edge
{
	int from, to, dist;

	Edge(int from, int to, int dist) : from(from), to(to), dist(dist) {}
};

struct Item
{
	int num, node, cost;
	vector<int> trip;

	Item(int num, int node, int cost) : num(num), node(node), cost(cost) {}
	Item(int num, int node, int cost, int trip) : num(num), node(node), cost(cost) 
	{
		addtrip(trip);
	}

	void addtrip(int a)
	{
		trip.PB(a);
	}

	//operator overloading
	bool operator < (const Item& rs) const
	{
		if(num == rs.num)
			return cost < rs.cost;
		return num < rs.num;
	}
};

struct Ticket
{
	int cost;
	int station;
	vector<int> stations;

	void addsta(int a)
	{
		stations.PB(a);
	}
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	clock_t time;
	time = clock();

	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;
	int C = 1;

	while(~scanf("%d", &n) && n!=0)
	{
		vector<Edge> edges;
		vector<int> adj;
		vector<Ticket> tickets;
	
	//input Tickets
		for(int i = 0; i < n; i++)	
		{
			Ticket tmp;
			scanf("%d %d", &tmp.cost, &tmp.station);

			//test
			//cout << tmp.cost << ' ' << tmp.station << endl;

			for(int l = 0; l < tmp.station; l++)
			{
				int hold;
				scanf("%d", &hold);
				tmp.addsta(hold);
			}

			tickets.PB(tmp);
		}
	//end input

	//start get trip and doing dijkstra algorithm
		int trip;

		scanf("%d", &trip);

		for(int j = 1; j <= trip; j++)
		{
			int cite_n;
			scanf("%d", &cite_n);

			vector<int> cites;

			for(int i = 0; i < cite_n; i++)
			{
				int tmp;
				scanf("%d" ,&tmp);

				cites.PB(tmp);
			}

		//start going through the priority queue

			priority_queue<Item> q;

			q.push(Item(1,cites[0],0));
			int ans = 0;

			while(!q.empty())
			{
				Item tmp = q.top();

			//test
				//printf("pop:(%d %d %d)\n", tmp.num, tmp.node, tmp.cost);
			//end test
				q.pop();

				if(tmp.num == cite_n && tmp.node == cites.back())
				{
					ans = tmp.cost;
					printf("Case %d, Trip %d: Cost = %d\n", C, j, ans);
					printf("  Tickets used:");
					for(int i = 0; i < tmp.trip.size(); i++)
					{
						printf(" %d", tmp.trip[i]);
					}
					printf("\n");
					break;
				}

				for(int i = 0; i < tickets.size(); i++)
				{
					if(tmp.node == tickets[i].stations[0])
					{
						for(int k = 1; k < tickets[i].stations.size(); k++)
						{
							int same = 0;
							int hold = tmp.num;

							for(int j = 0; j <= k; j++)
							{
								if(hold >= cite_n)	break;
								if(cites[hold] == tickets[i].stations[j])
								{
									hold++;
									same++;
								}
							}

						//test
							//printf("push:(%d %d %d)\n", same, tickets[i].stations[k], tmp.cost+tickets[i].cost);
						//end test
							Item item = Item(tmp.num+same, tickets[i].stations[k], tmp.cost+tickets[i].cost);
							for(int o = 0; o < tmp.trip.size(); o++)
							{
								item.addtrip(tmp.trip[o]);
							}
							item.addtrip(i+1);
							q.push(item);
						}
						
					}

					else
					{
						q.push(Item(0, tickets[i].stations[0], 0));

					//test
						//printf("push:(%d %d %d)\n", 0, tickets[i].stations[0], 0);
					//end test
						continue;
					}
				}
			}
		//end running
		}

		C++;
		

		

	//end 

	//test
		/*
		for(int i = 0; i < tickets.size(); i++)
		{
			printf("%d %d ", tickets[i].cost, tickets[i].station);
			
			printf("Station: ");
			for(int l = 0; l < tickets[i].station; l++)
			{
				printf("%d:%d ", l, tickets[i].stations[l]);
			}
 
			printf("\n");
		}
		*/
	}

	time = clock() - time;
	cout << "time: " << (double)time/CLOCKS_PER_SEC << endl;

	return 0;
}