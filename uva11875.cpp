#include <iostream>
using namespace std;

int arr[105];

int main(void)
{
    int T; cin >> T;

    for(int j = 1; j <= T; j++)
    {
        int n;
        cin >> n;


        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Case " << j << ": " << arr[n/2] << '\n';
    }
    return 0;
}