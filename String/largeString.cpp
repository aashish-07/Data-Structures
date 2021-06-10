/*largest string out of N strings*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,len = 0,maxlen = 0;
    char s[100];
    char largest[100];
    cin>>n;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        cin.getline(s,100);
        len = strlen(s);
        if(len > maxlen)
        {
            maxlen = len;
            strcpy(largest,s);
        }
    }
    cout<<largest<<","<<maxlen;
    return 0;
}