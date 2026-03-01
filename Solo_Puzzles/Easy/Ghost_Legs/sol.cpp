#include <iostream>
#include <string>
using namespace std;
char getEndPath(string line[], int width, int height, int x)
{
    if (line[0].empty() || width <= 0 || height <= 0 || x < 0)
        return (0);
    int y = 0;
    while (++y < height - 1)
    {
        if (x > 0 && line[y][x - 1]!=' ')
            x-=3;
        else if (x + 1 < width && line[y][x + 1]!=' ')
            x+=3;
    }
    return (line[height - 1][x]);
}
int main()
{
    int w,h;
    cin >> w >> h; cin.ignore();
    string line[h];
    for (int i=0;i<h;i++){getline(cin, line[i]);}
    for (int x=0;x<w;x+=3)
        cout << line[0][x] << getEndPath(line, w, h, x) << endl;
}
