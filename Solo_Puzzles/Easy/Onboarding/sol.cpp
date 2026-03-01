#include <iostream>
#include <string>
using namespace std;
int main()
{
    while (1)
    {
        string e1; cin >> e1; cin.ignore();
        int d1; cin >> d1; cin.ignore();
        string e2; cin >> e2; cin.ignore();
        int d2; cin >> d2; cin.ignore();
        cout << ((d1<d2)?e1:e2) << endl;
    }
}
