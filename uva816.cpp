#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn 15

//structure
struct Node
{
	int x, y, d, c;

	Node(int x, int y, int d, int c):x(x),y(y),d(d),c(c){}
	Node(){}
};
//declaration
string name;
string tmp;
pair<int, int> start, ed;
map<char, int> dir;
map<char, int> dirr;
char dir_s;
bool maze[maxn][maxn][maxn][maxn];
Node father[maxn][maxn][maxn];
Node now;
bool flag;
int x, y;
int rr[] = {-1, 0, 1, 0};
int cc[] = {0, 1, 0, -1};

//functions
void bfs(int r, int c, int d)
{
	queue<Node> q;

	q.push(Node(r, c, d, 1));

	while(!q.empty())
	{
		now = q.front(); q.pop();
		// printf("%d %d %d %d\n", now.x, now.y, now.d, now.c);
		if(now.x == ed.F && now.y == ed.S)
		{
			flag = true;
			break;
		}
			
		for(int i = 0; i < 3; i++)
		{
			if(maze[now.x][now.y][now.d][i])
			{
				int hold = (now.d+i+3)%4;

				if(father[now.x+rr[hold]][now.y+cc[hold]][hold].x < 0)
				{
					father[now.x+rr[hold]][now.y+cc[hold]][hold] = now;
					q.push(Node(now.x+rr[hold], now.y+cc[hold], hold, now.c+1));
				}
			}
		}
	}
}

void print_ans(void)
{
	vector<Node> v;
	while(true)
	{
		v.emplace_back(now);
		if(now.x == start.F && now.y == start.S && now.c == 0)
			break;
		now = father[now.x][now.y][now.d];
	}
	int cnt = 0;
	for(int i = v.size()-1; i >= 0; i--)
	{
		cnt++;
		if(cnt%10 == 1)
			printf(" ");
		printf(" (%d,%d)", v[i].x, v[i].y);
		if(cnt%10 == 0)
			puts("");
	}

	if(cnt % 10 != 0)
		puts("");
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	dir['N'] = 0; dir['E'] = 1; dir['S'] = 2; dir['W'] = 3;
	dirr['L'] = 0; dirr['F'] = 1; dirr['R'] = 2;

	while(cin >> name)
	{
		if(name == "END")
			break;

		MSET(maze, false);
		MSET(father, -1);
		flag = false;

		cin >> start.F >> start.S >> dir_s >> ed.F >> ed.S;

		while(cin >> x && x)
		{
			cin >> y;
			int a, b;

			while(cin >> tmp)
			{
				if(tmp == "*")
					break;
				for(int i = 0; i < tmp.size(); i++)
				{
					if(!i)
						a = dir[tmp[i]];
					else
					{
						b = dirr[tmp[i]];
						maze[x][y][a][b] = true;
					}
				}
			}
		}

		cout << name << '\n';

		father[start.F+rr[dir[dir_s]]][start.S+cc[dir[dir_s]]][dir[dir_s]] = Node(start.F, start.S, dir[dir_s], 0);
		bfs(start.F+rr[dir[dir_s]], start.S+cc[dir[dir_s]], dir[dir_s]);
		
		if(flag)
			print_ans();
		if(!flag)
			printf("  No Solution Possible\n");
	}
	return 0;
}