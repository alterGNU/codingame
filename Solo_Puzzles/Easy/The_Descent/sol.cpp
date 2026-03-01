#include <iostream>
#include <string>
using namespace std;
int main()
{
    while (1)
    {
        int max = 0;
        int index = 0;
        for (int i = 0; i < 8; i++)
        {
            int mountain_h;
            cin >> mountain_h;
            cin.ignore();
            if (mountain_h > max)
            {
                max = mountain_h;
                index = i;
            }
        }
        cout << index << endl;
    }
}
