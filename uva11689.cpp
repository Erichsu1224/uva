#include <iostream>
using namespace std;

int finded, empty, n;
int total;

void func(int a)
{
    if(a < n)
        return;
    total += a/n;
    a = a%n+a/n;
    func(a);
}

int main(void)
{
    int T;  cin >> T;

    while(T--)
    {
        cin >> finded >> empty >> n;
        total = 0;
        func(finded+empty);
        cout << total << '\n';
    }
    return 0;
}