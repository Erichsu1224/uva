#include <iostream>
#include <cstdlib>
using namespace std;

#define maxn 100010

int number[maxn];

int main(void)
{
	int N, D;

	while(cin >> N >> D)
	{
		if(N == 0 && D == 0)
			break;
		string in;
		cin >> in;
		for(int i = 0; i < N; i++)
		{
			char tmp[2];
			tmp[0] = in[i];
			tmp[1] = '\0';
			number[i] = atoi(&tmp[0]);
		}

		int counter = 0;
		int hold = 0;
		for(int i = D; counter < N-D; i++)
		{
			int max = hold;
			for(int n = hold; n <= i; n++)
				if(number[n] > number[max])	max = n;
			cout << number[max];

			counter++;
			hold = max+1;
		}
		cout << endl;
	}
	return 0;
}

