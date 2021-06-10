#include <iostream>
#include<algorithm>
using namespace std;
bool compare(int a,int b)
{
    return a>b; 
}
int main() {
	// your code goes here
	int N;
	cin>>N;
	int a[N];
	for (int i = 0; i < N; i++) {
	    /* code */
	    cin>>a[i];
	}
	
	sort(a,a+N,compare);/*passing function as a parameter to sort function*/
		for (int i = 0; i < N; i++) {
	    /* code */
	    cout<<a[i]<<" ";
		}
	return 0;
}
