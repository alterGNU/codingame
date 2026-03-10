#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string  to7BitBin(char c)
{
    string  res;
    for (int i=6;i>=0;i--)
        res += ((c >> i) & 1)?'1':'0';
    return (res);
}
int main()
{
    string m;getline(cin, m);
    string b;for (char c:m){b+=to7BitBin(c);}
    size_t len=b.size();
    size_t i=0;
    size_t j=0;
    while (j<len)
    {
        if (b[i]!=b[j])
        {
            cout << ((b[i]=='0')?"00 ":"0 ") << string((j-i),'0') << " ";
            i=j;
        }
        j++;
    }
    if (i<j)
        cout << ((b[i]=='0')?"00 ":"0 ") << string((j-i),'0');
    cout << endl;
}
