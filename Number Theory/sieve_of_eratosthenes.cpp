#include <iostream>
using namespace std;
#define ll long long
void primeSieve(int *p)
{
    // mark all odd no as prime
    for (int i = 3; i < 1000000; i += 2)
    {
        p[i] = 1;
    }
    //  Sieve of Eratosthenes
    for (ll i = 3; i < 1000000; i += 2)
    {
        //  if current no. is marked as prime
        if (p[i] == 1)
        {
            for (ll j = i * i; j < 1000000; j = j + i)
            {
                //  mark all multiples of i as not prime
                p[j] = 0;
            }
        }
    }
    //Special Case
    p[1] = p[0] = 0;
    p[2] = 1;
}
int main()
{
    int n;
    cin >> n;
    int p[1000000] = {0};
    primeSieve(p);
    for (int i = 3; i < n; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}
