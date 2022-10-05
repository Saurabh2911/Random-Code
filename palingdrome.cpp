#include <iostream>
#include <string>
using namespace std;
bool isPal(string str,int s,int e){
    if (s==e)
    {
        return true;
    }
    if (s>>e)
    {
        return true;
    }
    if (str[s]!=str[e])
    {
        return false;
    }
    return isPal(str,s+1,e-1);
    
}
int main()
{
    string str;
    int s=0;
    bool res;
    cout << "enter main string" << endl;
    cin >> str;
    int n =str.length();
    int e=n-1;
    res =isPal(str,s,e);
    if (res == true)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}
