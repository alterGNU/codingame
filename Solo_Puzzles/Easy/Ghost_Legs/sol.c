#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LINE 1024
char getFinalLabels(char line[][MAX_LINE], int width, int height, int x)
{
    if (!line || !line[0] || width < 0 || height < 0 || x < 0)
        return (fprintf(stderr, "ERROR: getFinalLabels()->Null arguments\n"), 0);
    int y = 0;
    while (++y < height - 1)
    {
        if (x > 0 && line[y][x-1] != ' ')
            x-=3;
        else if (x + 1 < width && line[y][x+1] != ' ')
            x+=3;
    }
    return (line[height - 1][x]);
}
int main()
{
    int x,y,W,H; 
    scanf("%d%d", &W, &H); fgetc(stdin);
    char line[H][MAX_LINE];
    for (int i=0;i<H;i++){scanf("%[^\n]", line[i]); fgetc(stdin); }
    for (int c=0;c<W;c+=3){printf("%c%c\n", line[0][c], getFinalLabels(line, W, H, c));}
    return 0;
}
