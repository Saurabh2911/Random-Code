#include <iostream>
#include <cstring>
using namespace std;
int main()
{
char databits[1000];
cout << "Enter Data Bits: ";
cin >> databits;
cout << "Data Bits Before Bit Stuffing: " << databits<<endl;
cout << "Data Bits After Bit Stuffing: ";
int count=0;
for (int i=0; i< strlen(databits); ++i)
{
if (databits[i]=='1')
{
count++;
}
else
{
count=0;
}
cout << databits[i];
if (count==5)
{
cout<<"0";
count=0;

}
}
return 0;
char ch;
cin>>ch;
}