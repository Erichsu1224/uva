#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int a, b;

	while(cin >> a >> b && a != -1 && b != -1)
	{
		cout << min(abs(a-b), 100-abs(a-b)) << '\n';
	}
	return 0;
}