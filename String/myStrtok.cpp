/*string tokenizer*/
#include <iostream>
#include <cstring>
using namespace std;
char *mystrtok(char *s, char delim)
{
    /*initializing static pointer*/
    static char *input = NULL;
    if (s != NULL)
    {
        input = s;
    }

    //base case
    if (input == NULL)
    {
        return NULL;
    }
    //extracting characters
    char *output = new char[strlen(input) + 1];
    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != delim)
        {
            output[i] = input[i];
        }
        else
        {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }

    //corner case
    output[i] = '\0';
    input = NULL;
    return output;
}
int main()
{
    char s[100] = "Today is a rainy day";
    char *ptr = mystrtok(s, ' ');
    cout << ptr << endl;
    ;
    while (ptr != NULL)
    {
        ptr = mystrtok(NULL, ' ');
        cout << ptr << endl;
    }
    return 0;
}
