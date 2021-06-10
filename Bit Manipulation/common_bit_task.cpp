#include <iostream>
using namespace std;

bool isOdd(int n)
{
    return (n & 1);
}

int getBit(int n, int i)
{
    /*
        ->Create a mask - (1<<i)
        ->Perform AND operation with the number
    */
    int mask = (1 << i);
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;
}

int setBit(int n, int i)
{
    /*
        ->Create a mask - (1<<i)
        ->Perform AND operation with the number
    */
    int mask = (1 << i);
    int ans = (n | mask);
    return ans;
}

void clearBit(int &n, int i)
{
    /*
        ->Create a mask and negate it - ~(1<<i)
        ->Perform AND operation with the number
    */
    int mask = ~(1 << i);
    n = (n & mask);
}

void updateBit(int &n, int i, int v){
     /*
        ->Create a mask and negate it - ~(1<<i) [for clearing the bit]
        ->Perform OR operation with the value
    */ 
    int mask = ~(1<<i);
    int cleared_num = (n&mask);
    n = cleared_num | (v<<i);
}

int clearLastIBits(int n, int i)
{
    /*
        ->Create a mask - (-1<<i)
        ->Perform AND operation with the number
    */
    int mask = (-1 << i);
    return n & mask;
}

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
}

int main()
{
    int i;
    cin >> i;
    int n = 15;

    cout<<clearLastIBits(n,i);
    // updateBit(n, 2, 0);
    // updateBit(n, 3, 1);
    // cout << n;
    // clearBit(n,i);
    // cout<<n;
    // cout << getBit(n, i) << endl;
    // cout << setBit(n, i) << endl;
    // cout<<isOdd(n);
return 0;
}

