/*program to find a palindromic string*/
#include <iostream>
#include <cstring>
using namespace std;
bool isPalindrome(char s[])
{
    int i = 0;
    int j = strlen(s)-1;
    char ch = cin.get();
    while ( i < j )
    {
        if(s[i] == s[j])
        {i++;j--;}
        else
        {
            return false;
        }
    }

    return true;
}
int main()
{
    char s[100];
    cin.getline(s, 100);
    if(isPalindrome(s))
    {
        cout<<"Palindrome";
    }
    else
    {
        cout<<"Not Palindrome";
    }
    

    return 0;
}