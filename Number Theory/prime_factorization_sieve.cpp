#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<int> primeSieve(int *p, int n)
{ //Special Case
    p[1] = p[0] = 0;
    p[2] = 1;
    // mark all odd no as prime(initialize)
    for (int i = 3; i < n; i += 2)
    {
        p[i] = 1;
    }
    //  Sieve login to amrk non prime as zero
    // 1.Optimisation : Iterarte only over odd numbers
    for (ll i = 3; i <= n; i += 2)
    {
        //  if current no. is marked as prime
        if (p[i] == 1)
        // mark all multiples of that number as ot prime
        // 2.Optimisation : Take a jump of 2i starting from 2*i
        {
            for (ll j = i * i; j <= n; j = j + i)
            {
                p[j] = 0;
            }
        }
    }

    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> factorize(int m, vector<int> &primes)
{
    vector<int> factors;
    int i = 0;
    int p = primes[0];
    while (p * p <= m)
    {
        if (m % p == 0)
        {
            factors.push_back(p);
            while (m % p == 0)
            {
                m = m / p;
            }
        }
        // goto next position
        i++;
        p = primes[i];
    }

    if (m != 1)
    {
        factors.push_back(m);
    }
    return factors;
}

int main()
{
    int N = 1000000;
    int p[N] = {0};
    vector<int> primes = primeSieve(p, 100);

    int t;
    cin >> t;
    while (t--)
    {
        int no;
        cin >> no;
        vector<int> factors = factorize(no, primes);

        for (auto f : factors)
        {
            cout << f << " ";
        }
        cout << endl;
    }

    return 0;
}