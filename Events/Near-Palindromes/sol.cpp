#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(string const &str) { return equal(str.begin(), str.begin() + str.size()/2, str.rbegin()); }
bool nearPalByDelOrAdd(string const &str)
{
    for (int i=0;i<str.size();i++)
    {
        if (isPalindrome(str.substr(0, i) + str.substr(i + 1)))
            return (true);
    }
    return (false);
}
bool nearPalByReplace(string const &str)
{
    size_t  left = -1;
    size_t  right = str.size();
    size_t  diff = 0;

    while (++left < --right && diff < 2)
        diff += str[left] != str[right];
    return (diff == 1);
}
int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string word;
        getline(cin, word);
        cout << ((nearPalByDelOrAdd(word)||nearPalByReplace(word))?"1":"0");
    }
}
