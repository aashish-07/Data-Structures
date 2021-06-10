/* 
Problem : 
PMO gives two random numbers a & b to the Prime Minister. 
PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country , 
So PM Modi decides to visit only those countries,for which country number has two divisors. 
So your task is to find number of countries Mr. Modi will visit.
Input Format
The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

Constraints
a<=1000000 & b<=1000000.
N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

Sample Input
2
1 10
11 20
Sample Output
4
4
*/
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
    int csum[1000000] = {0};
    for (int i = 1; i < 1000000; i++)
    {
        csum[i] = csum[i - 1] + p[i];
    }
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << csum[b] - csum[a - 1] << endl;
    }
    return 0;
}
