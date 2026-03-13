// Use Hashtab with linkedlist to handle collisions.
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#define HASHLEN 20011 // size of hashtab, should be a primenumber greater than 10000 to avoid collision
using namespace std;
size_t hashFun(const string &str)
{
    size_t h = 0;
    for (unsigned char c : str)
        h = h * 33 + c;
    return h % HASHLEN;
}
typedef struct  s_node
{
    string          key;
    string          val;
}               t_node;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;cin>>N;cin.ignore(); // Number N of elements in map (dict)
    t_node hashtab[HASHLEN];
    int M;cin>>M;cin.ignore(); // Number M of file names to be analyzed.
    string key;
    string val;
    size_t id1;
    for (int i=0;i<N;i++)
    {
        cin>>key>>val;cin.ignore();
        for (char &c:key){c=tolower((unsigned char)c);}
        id1 = hashFun(key);
        while (!hashtab[id1].key.empty())
            id1 = (id1 + 1) % HASHLEN;
        hashtab[id1].key = key;
        hashtab[id1].val = val;
    }
    size_t a;
    string fname, ext;
    size_t id2;
    for (int i=0;i<M;i++)
    {
        getline(cin, fname); // One file name per line.
        a = fname.rfind(".");
        if (a != string::npos && a + 1 < fname.size())
        {
            ext = fname.substr(a + 1);
            for(char &c:ext){c=tolower((unsigned char)c);}
            id2 = hashFun(ext);
            while (!hashtab[id2].key.empty() && hashtab[id2].key!=ext)
                id2 = (id2 + 1) % HASHLEN;
            cout<<((hashtab[id2].key.empty())?"UNKNOWN":hashtab[id2].val)<<"\n";
        }
        else
            cout << "UNKNOWN\n";
    }
}
