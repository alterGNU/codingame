#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 10000
int is_a_palindrome(char *str)
{
    int left;
    int right;

    if (!str)
        return (fprintf(stderr, "ERROR:is_a_palindrome() null argument\n"), 0);
    right = (int) strlen(str);
    if (!right)
        return (1);
    left = -1;
    while(left < right)
    {
        if (str[++left] != str[--right])
            return (-1);
    }
    return (1);
}
int nearpal_by_del_or_add(char *str)
{
    size_t  len;
    char    new_str[MAX_LEN];
    int     is_pal;

    if (!str)
        return (fprintf(stderr, "ERROR:nearpal_by_del_or_add() null argument\n"), 0);
    len = (size_t)strlen(str);
    for (size_t i=0;i<len;i++)
    {
        memcpy(new_str, str, i);
        memcpy(new_str + i, str + i + 1, len - i - 1);
        new_str[len - 1] = '\0';
        is_pal = is_a_palindrome(new_str);
        if (is_pal >= 0)
            return (is_pal);
    }
    return (-1);
}
int nearpal_by_replacement(char *str)
{
    size_t  i;
    size_t  len;
    size_t  half_len;
    size_t  tot_diff;

    if (!str)
        return (fprintf(stderr, "ERROR:nearpal_by_replacement() null argument\n"), 0);
    len = (size_t) strlen(str);
    half_len = len / 2;
    tot_diff = 0;
    i = 0;
    while (i < half_len && tot_diff < 2)
    {
        tot_diff += (str[i] != str[len - i - 1]);
        i++;
    }
    return (tot_diff==1?1:-1);
}
int main()
{
    int N;
    scanf("%d", &N);
    fgetc(stdin);
    for (int i=0;i<N;i++)
    { 
        char word[MAX_LEN] = "";
        fgets(word, MAX_LEN, stdin);
        word[strcspn(word, "\n")] = '\0';
        int res_del_add = nearpal_by_del_or_add(word);
        if (!res_del_add)
            return (1);
        int res_replace = nearpal_by_replacement(word);
        if (!res_replace)
            return (1);
        printf("%d", (res_del_add>0 || res_replace>0));
    }
    return (0);
}
