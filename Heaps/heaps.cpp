#include <iostream>
#include <vector>

class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if (minHeap)
        {
            return a < b;
        }
        else
            return a > b;
    }

    void heapify(int idx)
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

            heapify(min_idx);
        }
    }

public:
    Heap(int deafult_size = 10, bool type = true)
    {
        v.reserve(deafult_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int d)
    {
        v.push_back(d);         // S1 : insert element to the last position
        int idx = v.size() - 1; //find index  of the parent
        int parent = idx / 2;
            while(idx > 1 and compare(v[idx],v[parent])){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
            }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }
};

using namespace std;
int main()
{
    cout << "Hello World!";

    return 0;
}
