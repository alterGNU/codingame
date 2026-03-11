#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string, char> d={{"sp", ' '},{"bS", '\\'},{"sQ", '\''}};
    bool isSpace;
    int nb,i;
    string str,sub,cmd;
    getline(cin, str);
    stringstream ss(str);
    while (getline(ss, sub, ' '))
    {
        nb = 0;
        i = -1;
        while(++i<sub.size() - 1 && isdigit(sub[i]))
            nb = nb * 10 + sub[i] - '0';
        cmd = sub.substr(sub.size() - 2, 3);
        isSpace = (cmd == "nl");
        nb += isSpace?1:0;
        for (int e=0;e<nb;e++)
        {
            if (isSpace)
                cout << endl;
            else
                cout << ((d.count(cmd))?d[cmd]:sub[sub.size()-1]);
        }
    }
}
