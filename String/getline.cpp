/*program to read a sentence*/
#include<iostream>
using namespace std;
void readline(char s[],int len)
{
    int i = 0;
    char ch = cin.get();
    while(ch!='\n')
    {
        s[i] = ch;
        i++;
        if(i == (len-1))
        {
            break;
        }
        ch = cin.get();
    }
    s[i] = '\0';
    return;
}
 int main()
 {
     char s[100];
     readline(s,100);
     cout<<s;

     return 0;
 }