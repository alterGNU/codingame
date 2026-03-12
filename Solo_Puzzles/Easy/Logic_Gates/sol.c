#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXNAME 8
#define MAXLINE 512
// -[ t_ousig structur]-----------------------------------------------------------------------------------------------------------------------
typedef struct s_outsig
{
    char    name[MAXNAME];
    char    type[6];
    char    inName1[MAXNAME];
    char    inName2[MAXNAME];
} t_outsig;
void    t_outsig_set(t_outsig *o){scanf("%s%s%s%s", o->name, o->type, o->inName1, o->inName2);}
void    t_outsig_print(t_outsig o){fprintf(stderr, "{name:%s, type:%5s, inName1:%s, inName2:%s}", o.name, o.type, o.inName1, o.inName2);}
// -[ utils functions ]------------------------------------------------------------------------------------------------------------------------
int     getIndex(char name[MAXNAME], char lst[4][MAXNAME], int size)
{
    for (int i=0;i<size;i++)
    {
        if (!strcmp(name, lst[i]))
            return (i);
    }
    return (-1);
}
char    logic(char type[6], char x, char y)
{
    int a = (x=='-');
    int b = (y=='-');
    if (!strcmp(type, "AND"))
        return ((a && b)?'-':'_');
    if (!strcmp(type, "OR"))
        return ((a || b)?'-':'_');
    if (!strcmp(type, "XOR"))
        return ((!!a != !!b)?'-':'_');
    if (!strcmp(type, "NAND"))
        return (!(a && b)?'-':'_');
    if (!strcmp(type, "NOR"))
        return (!(a || b)?'-':'_');
    if (!strcmp(type, "NXOR"))
        return ((!!a == !!b)?'-':'_');
    return ('0');
}
int main()
{
    int n;scanf("%d", &n);                                      // Number of input signals
    int m;scanf("%d", &m);                                      // Number of output signals
    char inName[4][MAXNAME]={0};                                // String array to store input names
    char inSign[4][MAXLINE]={0};                                // String array to store input signal (index share with inName string array)
    for (int i=0;i<n;i++){scanf("%s%s", inName[i], inSign[i]);} // Fill Inputs signals string arrays
    t_outsig    outLst[m];
    for (int i=0;i<m;i++){t_outsig_set(&outLst[i]);}            // Fill Outputs signals string array
    int lenSign, ind1, ind2;
    for (int i=0;i<m;i++)
    {
        printf("%s ", outLst[i].name);
        lenSign = strlen(inSign[0]);
        for(size_t j=0;j<lenSign;j++)
        {
            ind1 = getIndex(outLst[i].inName1, inName, 4);
            ind2 = getIndex(outLst[i].inName2, inName, 4);
            printf("%c", logic(outLst[i].type, inSign[ind1][j],  inSign[ind2][j]));
        }
        printf("\n");
    }
    return 0;
}
