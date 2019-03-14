//窮舉 x+1 <= i <= 2x

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		vector <int> a, b;
		for(int i = x+1; i <= 2*x; i++)
		{
			if((x*i) % (i-x) == 0)
			{
				a.push_back(i);
				b.push_back(x*i/(i-x));
			}
		}

		cout << a.size() << endl;
		for(int i = 0; i < a.size(); i++)
		{
			printf("1/%d = 1/%d + 1/%d\n", x, b[i], a[i]);
		}
	}
	return 0;
}