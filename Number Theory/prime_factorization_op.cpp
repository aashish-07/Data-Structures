#include <iostream>
#include <vector>
using namespace std;
void primeFactors(int n)
{
    // pair of vector fo factor and it's power
    vector<pair<int, int>> factors;
    int cnt;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % 1 == 0)
        {
            // divide till it's divisible by i
            cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            factors.push_back(make_pair(i, cnt));
        }
    }
    if (n != 1)
    {
        // whatever is left is a prime factor itself
        factors.push_back(make_pair(n, 1));
    }
    for (auto p : factors)
    { 
        // print factors
        cout << p.first << "^" << p.second << endl;
    }
    return;
}
using namespace std;
int main()
{
    int n;
    cin >> n;
    primeFactors(n);
    return 0;
}
