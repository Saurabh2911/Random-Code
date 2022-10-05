#include <iostream>
#include <string>
using namespace std;
int lexo(string str)
{
    int n = str.length();
    int res = 1;
    int factn = 1;
    for (int i = 1; i <= n; i++)
    {
        factn = factn * i;
    }
    
}
int main()
{
    string str;
    cin >> str;
    int x = lexo(str);
    cout << x;
    return 0;
}
