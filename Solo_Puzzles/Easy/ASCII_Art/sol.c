#include <stdlib.h>
#include <stdio.h>
#include <string.h> // string
#include <ctype.h>  // isalpha(), isupper(), toupper()
#define MAX_CHAR_WIDTH 32
#define MAX_STR 224
int    print_substr(char *str, int start, int len)
{
    int i = 0;
    if (!str || start < 0 || len < 0)
        return (i);
    while (i < len && str[start + i])
    {
        printf("%c", str[start + i]);
        i++;
    }
    return (i);
}
int main()
{
    int index;
    int w; scanf("%d", &w);
    int h; scanf("%d", &h); fgetc(stdin);
    char txt[MAX_STR] = ""; scanf("%[^\n]", txt); fgetc(stdin);
    fprintf(stderr, "[debug] Text to print:'%s'\n", txt);
    char row[h][MAX_CHAR_WIDTH * MAX_STR];
    for (int l=0;l<h;l++){scanf("%[^\n]", row[l]); fgetc(stdin); }
    for (int l=0;l<h;l++)
    {
        for (int e=0;e<strlen(txt);e++)
            print_substr(row[l], (isalpha(txt[e])?(isupper(txt[e])?(int)txt[e]:(int)(toupper(txt[e])))-(int)'A':26) * w, w);
        printf("\n");
    }
    return 0;
}
