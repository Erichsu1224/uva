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


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	string in;

	while(getline(cin, in))
	{
		queue<char> std;
		vector<char> pre[100000+5];

		int pointer = 0;
		int counter = -1;
		for(int i = 0; i < in.size(); i++)
		{
			if(in[i] == '[')
			{
				counter++;
				pointer = 1;
				continue;
			}
			if(in[i] == ']')
			{
				pointer = 0;
				continue;
			}

			if(pointer == 0)
				std.push(in[i]);
			if(pointer == 1)
				pre[counter].PB(in[i]);
		}

		for(int i = counter; i >= 0; i--)
		{
			for(int j = 0; j < pre[i].size(); j++)
			{
				printf("%c", pre[i][j]);
			}
		}
		while(!std.empty())
		{
			printf("%c", std.front());
			std.pop();
		}
		printf("\n");
	}

	return 0;
}