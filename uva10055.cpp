#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void)
{
    long long a, b;

    while(cin >> a >> b)
    {
        cout << abs(a-b) << '\n';
    }
    return 0;
}