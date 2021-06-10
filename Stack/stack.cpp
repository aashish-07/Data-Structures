#include <iostream>
#include <vector>
using namespace std;
// Stack Implementation using vector
template<typename T>
class Stack{
    private:
        vector<T> v;
    public:
        bool empty(){
            return v.size() == 0;
        }
        void push(T data){
            v.push_back(data);
        }
        void pop(){
            if(!empty()){
                v.pop_back();
            }
        }
        int top(){
            return v[v.size()-1];
        }
};

int main() {
    Stack<int> s;
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}
