//2016 World Final
//dijkstra
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
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 10+5 //2 to 10 cities

struct Edge
{
	int from, to, dist;

	Edge(int from, int to, int dist) : from(from), to(to), dist(dist) {}
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

	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d", &n) && n!=0)
	{
		vector<Edge> edges;
		vector<int> adj;
		vector<Ticket> tickets;
		int visited[maxn];
		
		for(int i = 0; i < n; i++)
		{
			Ticket tmp;
			scanf("%d %d", &tmp.cost, &tmp.station);

			cout << tmp.cost << ' ' << tmp.station << endl;

			for(int l = 0; l < tmp.station; l++)
			{
				int hold;
				scanf("%d", &hold);
				cout << hold << ' ';
				tmp.addsta(hold);
				cout << tmp.stations[l] << endl;
			}

			tickets.PB(tmp);
		}

		//test
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
	}




	return 0;
}