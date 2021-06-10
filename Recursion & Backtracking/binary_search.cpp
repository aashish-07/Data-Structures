#include <iostream>
using namespace std;

int binarySearch(int a[],int n,int key)
{
    mid = 
    // Base Case
    if (mid == key)
    {
        return true;
    }
    // Recursive Case
    if(a[n]==key and binarySearch(a,n/2,key))
    {
        return true;
    }  ;
}

int main()
{
    int n,key;
    int arr[] = {12,11,34,52,67};
    key = 34;
    n=sizeof(arr)/sizeof(int);
    cout << binarySearch(arr,n,key);

    return 0;
}