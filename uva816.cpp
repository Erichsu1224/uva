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
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure
struct Node
{
	int r, c, dir;
	Node() {}
	Node(int r, int c, int dir) : r(r), c(c), dir(dir){}
};

//declaration
string title;
int r1, c1, r2, c2, r0, c0;
char* turns = "FLR";
char* dirs = "NESW";
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int has_edge[15][15][15][15];
int d[15][15][15];
Node p[15][15][15];
int dir;

//functions

//方向和行為的轉換
int turn_id(char a)
{
	return strchr(turns, a) - turns;
}

int dir_id(char a)
{
	return strchr(dirs, a) - dirs;
}

Node walk(const Node& u, int turn)
{
	int dir = u.dir;
	if(turn == 1)
		dir = (dir+3) % 4;
	if(turn == 2)
		dir = (dir+1) % 4;

	return Node(u.r+dr[dir], u.c+dc[dir], dir);
}


void print_ans(Node u)
{
	//從終點回朔到起點
	vector<Node> nodes;
	for(;;)
	{
		nodes.push_back(u);
		if(d[u.r][u.c][u.dir] == 0)
			break;
		u = p[u.r][u.c][u.dir];
	}

	nodes.push_back(Node(r0, c0, dir));

	int cnt = 0;

	for(int i = nodes.size()-1; i >= 0; i--)
	{
		if(cnt % 10 == 0)
			printf(" ");
		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
		if(++cnt%10 == 0)
			printf("\n");
	}

	if(nodes.size() % 10 != 0)
		printf("\n");
}

void solve(void)
{
	queue<Node> q;
	memset(d, -1, sizeof(d));
	Node u(r1, c1, dir);
	d[u.r][u.c][u.dir] = 0;
	q.push(u);
	while(!q.empty())
	{
		Node u = q.front();
		q.pop();
		if(u.r == r2 && u.c == c2)
		{
			print_ans(u);
			return;
		}
		for(int i = 0; i < 3; i++)
		{
			Node v = walk(u, i);
			if(has_edge[u.r][u.c][u.dir][i] && d[v.r][v.c][v.dir] < 0)
			{
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir]+1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf("No solution Possible\n");
}

string name;
int node [][][ip]
int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

<<<<<<< HEAD
	while(cin >> title && title[0] != 'E')
	{
		char dir_s;
		cin >> r1 >> c1 >> dir_s >> r2 >> c2;
		dir = dir_id(dir_s);
		solve();
	}
=======
	
>>>>>>> 1f8161f2bbca603a7959c8ddc34ba9007e894f18

	

	return 0;
}