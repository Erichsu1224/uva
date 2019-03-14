#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis[100000];
int sg[100000];

void segment_build(int L, int R, int vertex);

int main(void)
{
	int n, q;

	cin >> n >> q;

	for(int i = 0; i < n; i++)
	{
		cin >> lis[i];
	}

	
	segment_build(0, n-1, 1);

	return 0;
}

void segment_build(int L, int R, int vertex)
{
	if(L == R)	sg[vertex] = lis[L];

	segment_build(L, (L+R)/2, vertex*2);
	segment_build((L+R)/2+1, R, vertex*2+1);

	sg[vertex] = (sg[(vertex+1)*2] >= sg[(vertex)*2+1]) ? sg[(vertex)*2] : sg[(vertex+1)*2+1];

}