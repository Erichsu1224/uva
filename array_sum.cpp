#include <iostream>
using namespace std;

int main(void)
{
    int n, total = 0, tmp;

    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            total += tmp;
        }

        cout << total << '\n';
    }
    return 0;
}