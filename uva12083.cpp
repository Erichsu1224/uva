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
#define maxn 500+5

int n;
vector <int> v[maxn];

struct Item
{
	int height;
	char sex;
	string music;
	string exercise;

}	stu[maxn];

void input(void)
{
	for(int i = 0; i < n; i++)
	{
		v[i].clear();
		scanf("%d\n%c\n", &stu[i].height, &stu[i].sex);
		cin >> stu[i].music >> stu[i].exercise;
	}
}

bool check(int a, int b)
{
	if(abs(stu[a].height - stu[b].height) > 40)
		return true;
	if(stu[a].music != stu[b].music)
		return true;
	if(stu[a].exercise == stu[b].exercise)
		return true;
	return false;
}

void match(void)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j) continue;

			if(stu[j].sex == 'F')	continue;

			if(check(i, j))
				v[j].PB(i);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int cases;

	scanf("%d", &cases);

	while(cases--)
	{
		scanf("%d", &n);		

		input();

		//test
		for(int i = 0; i < n; i++)
		{
			printf("%d: ", i);
			for(int j = 0; j < v[i].size(); j++)
			{
				cout << v[i][j] << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}