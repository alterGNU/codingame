#include <iostream>
#include <string>
using namespace std;
int main()
{
    int w; cin >> w; cin.ignore();
    int h; cin >> h; cin.ignore();
    string t; getline(cin, t);
    string row[h];for (int i=0; i<h; i++){getline(cin, row[i]);}
    for (int l=0;l<h;l++)
    {
        for (int i=0;i<t.length();i++)
            cout << row[l].substr(((isalpha(t[i]))?int(toupper(t[i])) - int('A'):26) * w, w);
        cout << endl;
    }
}
