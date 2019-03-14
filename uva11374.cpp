#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Item
{
	int from, to, dist;

	Item(int from, int to, int dist) : from(from), to(to), dist(dist) {}

	bool operator< (const Item r) const
	{
		return r.dist > dist;
	}
};

int main(void)
{
	int N, S, E;
	int M, K;
	vector<Item> edges;
	vector<Item> edges_Co;

	while(cin >> N >> S >> E)
	{
		cin >> M;
		for(int i = 0; i < M; i++)
		{
			int X, Y, Z;
			cin >> X >> Y >> Z;
			edges.push_back(Item(X, Y, Z));
		}

		cin >> K;
		for(int i = 0; i < K; i++)
		{
			int X, Y, Z;
			cin >> X >> Y >> Z;
			edges_Co.push_back(Item(X, Y, Z));
		}

		// double side dijkstra
		priority_queue<Item> q;

		


	}
	return 0;
}