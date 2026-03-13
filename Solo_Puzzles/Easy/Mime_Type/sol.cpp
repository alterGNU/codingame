// No linked list, use unordered_map and l9-l10 astuce
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, string> D;
    int N;cin>>N;cin.ignore(); // Number N of elements in map (dict)
    int M;cin>>M;cin.ignore(); // Number M of file names to be analyzed.
    string key;
    string val;
    for (int i=0;i<N;i++)
    {
        cin>>key>>val;cin.ignore();
        for (char &c:key)
            c = tolower((unsigned char)c);
        D[key]=val;
    }
    int a, b;
    string fname, ext;
    for (int i=0;i<M;i++)
    {
        getline(cin, fname); // One file name per line.
        a = fname.rfind(".");
        b = fname.size();
        if (a >= 0 && b && a + 1 < b)
        {
            ext = fname.substr(a + 1);
            for (char &c:ext)
                c = tolower((unsigned char)c);
            auto it = D.find(ext);
            if (it != D.end())
                cout << it->second << endl;
            else
                cout << "UNKNOWN" << endl;
        }
        else
            cout << "UNKNOWN" << endl;
    }
}
