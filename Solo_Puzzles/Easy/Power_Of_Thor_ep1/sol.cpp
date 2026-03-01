#include <iostream>
#include <string>
using namespace std;
int main()
{
    int x;  // the X position of the light of power
    int y;  // the Y position of the light of power
    int tx; // Thor's starting X position
    int ty; // Thor's starting Y position
    cin >> x >> y >> tx >> ty;
    string dir;
    // game loop
    while (1) {
        int remaining_turns;
        cin >> remaining_turns;
        if (y < ty)
            {dir.append("N");y++;}
        else if (y > ty)
            {dir.append("S");y--;}
        if (x < tx)
            {dir.append("W");x--;}
        else if (x > tx)
            {dir.append("E");x++;}
        cout << dir << endl;
        dir.clear();
    }
}
