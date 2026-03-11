#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int     toInt(char *ori)
{
    char    str[6] = {0};
    strncpy(str,ori,strlen(ori)-1);
    int     tot = 0;
    int     x,e;
    size_t  len = strspn(str, "0123456789");
    size_t  i = 0;
    while (i < len)
    {
        x = str[i] - '0';
        e = -1;
        while (++e + 1 < len - i)
            x*=10;
        tot+=x;
        i++;
    }
    return (tot);
}
bool    isAbb(char *str)
{
    int     nb      = toInt(str);
    char    *k[4]   = {"sp", "bS", "sQ", "nl"};
    char    *v[4]   = {" ", "\\", "'", "\n"};
    for (int i=0;i<4;i++)
    {
        if (strstr(str, k[i]))
        {
            for (int j=0;j<nb+(i==3);j++)
                printf("%s", v[i]);
            return (true);
        }
    }
    return (false);
}
void printArt(char *T,int *i, int *j)
{
    char    S[4]    = {0};
    int     s       = *j-*i;
    strncpy(S, T+*i, s);
    S[s] = 0;
    if (!isAbb(S))
      for (int n=toInt(S);n>0;n--)
        printf("%c", S[s - 1]);
    *i = *j + 1;
    memset(S, 0, 4);
}
int main()
{
    char T[1001] = "";
    scanf("%[^\n]", T);
    int i = 0;
    int j = -1;
    while (T[++j])
        if (T[j]==' ')
            printArt(T,&i,&j);
    if (j>i)
        printArt(T,&i,&j);
    return (0);
}
