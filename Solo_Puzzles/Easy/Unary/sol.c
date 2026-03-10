#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG_MODE 1
#define BUFF 256

void    toBinStr(char c, char binStr[8])
{
    int     v = (int) c;
    for (int i=6;i>=0;i--)
    {
        binStr[i] = (v % 2) + '0';
        v/=2;
    }
}

void    print_unary(char *bin)
{
    int     len = strlen(bin);
    int     i = 0;
    int     j = 0;
    while (j < len)
    {
        if (bin[i]==bin[j])
            j++;
        else
        {
            if (DEBUG_MODE)
                fprintf(stderr, "bin[%d]=%c, j-i=%d\n", i, bin[i], j-i);
            printf("%s ", (bin[i]=='0')?"00":"0");
            for (int e=0;e<j-i;e++)
                printf("0");
            printf(" ");
            i = j;
        }
    }
    if (j > i)
    {
        if (DEBUG_MODE)
            fprintf(stderr, "bin[%d]=%c, j-i=%d\n", i, bin[i], j-i);
        printf("%s ", (bin[i]=='0')?"00":"0");
        for (int e=0;e<j-i;e++)
            printf("0");
    }

}

int main()
{
    char    bigStr[2080] = {0};
    char    binRaw[8] = {0};
    char    m[BUFF];
    scanf("%[^\n]", m);
    int     len = strlen(m);
    for (int i=0;i<len;i++)
    {
        toBinStr(m[i], binRaw);
        if (DEBUG_MODE)
            fprintf(stderr, "c:'%c' = \"%s\"\n", m[i], binRaw);
        strcat(bigStr, binRaw);
    }
    print_unary(bigStr);
    return (0);
}
