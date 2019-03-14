//UVA 686
//prime number
//binary search

#include <iostream>
#include <cmath>
using namespace std;

int prime[10000];

int main(void)
{
    //建質數表
    //Complexity O(nlogn)
    prime[0] = 2;
    int k = 1;

    for(int i = 2; i <= 32708; i++)
    {
        bool found = true;
        for(int n = 2; n <= sqrt(i); n++)
        {
            if(i % n == 0)
            {
                found = false;
                break;
            }
        }

        if(found)
            prime[k++] = i;
    }   
    //end

    //binary search
    //complexity O(logn)
    int input;

    while(scanf("%d", &input))
    {
        if(input == 0)
        {
            break;
        }
        int middle = (k-1)/2, left = 0, right = k-1;

        while(left < right)
        {
           if(input == prime[middle])
               break;

            if(input > prime[middle])
           {
                left = middle+1;
                middle = (left + right)/2;
            }

            if(input < prime[middle])
            {
                right = middle-1;
                middle = (left + right)/2;
            }
        }

        //complete
            int cases = 0;
        left = 0;
        right = middle;

        while(right >= left)
        {
            if(prime[left]+prime[right] == input)
            {
                cases++;
                left++;
                right--;
            }

            if(input-prime[right] > prime[left])
            {
                left++;
            }

            if(input-prime[right] < prime[left])
            {
                right--;
            }
        }

        printf("%d\n", cases);
    }
    return 0;
}

