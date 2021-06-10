/*
    Given a number N replace it's bits by position from i to j
    by number m
    Example : N = 100000000
              M = 1010  i = 2  j = 6
              O/P = 100101000
*/
#include <iostream>
using namespace std;

int clearRangeItoJ(int n, int i, int j)
{
    /*
        ->Create a mask - (-1<<i)
        ->Perform AND operation with the number
    */
    int ones = (~0);
    int a = ones << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    int ans = n & mask;
    return ans;
}

int replaceBits(int n, int m, int i, int j)
{
    int n_ = clearRangeItoJ(n, i, j);
    int ans = n_ | (m << i);
    return ans;
}
int main()
{
    int i, j, n, m;
    n = 15;
    m = 2;
    i = 1;
    j = 3;
    cout << replaceBits(n, m, i, j);

    return 0;
}
