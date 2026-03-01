#include <iostream>
using namespace std;
int main()
{
    int min,t,n,a,b;
    cin >> n; cin.ignore();
    if (n > 0)
    {
        min = 5526;
        for (int i = 0; i < n; i++)
        {
            cin >> t; cin.ignore();
            a = abs(t);
            b = abs(min);
            min = (a == b && t > 0)?t:min;
            min = (a < b)?t:min;
        }
    }
    cout << min << endl;
}
