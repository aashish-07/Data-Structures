#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v){
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

void buldHeap(vector<int> &v){
    for(int i = 2; i < v.size(); i++){
        int idx = i;
        int parent  = i/2;
         while(idx > 1 and v[idx]>v[parent]){
             swap(v[idx],v[parent]);
             idx = parent;
             parent = parent/2;
         }
    }
}

// Optimized approach O(N)

bool compare(int a, int b)
{
    bool minHeap = false;

    if (minHeap)
    {
        return a < b;
    }
    else
        return a > b;
}

void heapify(vector<int> &v, int idx)
{
    int left = 2 * idx;
    int right = left + 1;

    int min_idx = idx;
    int last = v.size() - 1;

    if (left <= last and compare(v[left], v[idx]))
    {
        min_idx = left;
    }
    if (right <= last and compare(v[right], v[idx]))
    {
        min_idx = right;
    }
    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);

        heapify(v, min_idx);
    }
}

void buldHeapOptimised(vector<int> &v)
{
    for (int i = v.size() / 2; i >= 1; i--)
    {
        heapify(v, i);
    }
}

int main() {
     vector<int> v{-1,10,20,5,6,1,8,9,4};
     print(v);
     buldHeapOptimised(v);
     print(v);

     return 0 ;
}
