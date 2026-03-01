#include <stdlib.h>
#include <stdio.h>
int main()
{
    char dir[3];
    int i,x,y,tx,ty;
    scanf("%d%d%d%d", &x, &y, &tx, &ty);
    while (1)
    {
        int remaining_turns;
        scanf("%d", &remaining_turns);
        i = 0;
        if (y < ty) { dir[i++]='N'; ty--; }
        else if (y > ty) { dir[i++] = 'S'; ty++; }
        if (x < tx) { dir[i++]='W'; tx--; }
        else if (x > tx) { dir[i++] = 'E'; tx++; }
        dir[i++]='\n';
        dir[i]=0;
        printf("%s", dir);
    }
    return 0;
}
