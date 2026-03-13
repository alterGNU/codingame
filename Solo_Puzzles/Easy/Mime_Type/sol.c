// Use hashtable with collision rule:insert next free in hashtab...
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define DEBUG_MODE 0
#define MAXLINE 256
#define HASHLEN 20011
int getHashNum(char *str)
{
    unsigned long h = 5381;
    int c;

    while ((c = *str++))
        h = ((h << 5) + h) + c; // h * 33 + c
    return h % HASHLEN;
}
typedef struct s_hash
{
    char    *key;
    char    *val;
} t_hash;
// Put all char to lower in str
void    toLower(char str[MAXLINE])
{
    for(size_t i=0;str[i];i++)
    {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}
int main()
{
    t_hash hashtab[HASHLEN] = {0};  // HashTable
    int N;scanf("%d", &N);          // Number of elements which make up the association table.
    int id = 0;                     // Counter id setted
    int indexArray[N];              // Store indexes, to free later...
    int Q;scanf("%d", &Q);          // Number Q of file names to be analyzed.
    char tp1[MAXLINE];
    char tp2[MAXLINE];
    int  ind1;
    if (DEBUG_MODE)
        fprintf(stderr, "STEP1: FILL HASHTAB\n");
    for (int i=0;i<N;i++)
    {
        scanf("%s%s", tp1, tp2);fgetc(stdin);toLower(tp1);
        ind1 = getHashNum(tp1);
        while (hashtab[ind1 % HASHLEN].key)
            ind1 = (ind1 + 1) % HASHLEN;
        indexArray[id++]=ind1;
        hashtab[ind1].key = strdup(tp1);
        hashtab[ind1].val = strdup(tp2);
        if (DEBUG_MODE)
            fprintf(stderr, "%d: hashtab[%d]:{'%s', '%s'}\n",i , ind1, hashtab[ind1].key, hashtab[ind1].val);
    }
    if (DEBUG_MODE)
    {
        fprintf(stderr, "\nSTEP2: PRINT HASH ARRAY\n");
        for (int i=0;i<N;i++)
            fprintf(stderr, "arr[%d]=%d\n", i , indexArray[i]);
        fprintf(stderr, "\nSTEP3: COMPUTE ALL\n");
    }
    char tp3[MAXLINE];
    char *ptr;
    int  ind2;
    for (int i=0;i<Q;i++)
    {
        scanf("%[^\n]", tp3);fgetc(stdin);
        ptr = strrchr(tp3, '.');
        if (ptr && strlen(ptr)>1)
        {
            toLower(tp3);
            ind2 = getHashNum(ptr + 1);
            if (DEBUG_MODE)
                fprintf(stderr, "'%s'-->'%s'-->hashtab[%d]={%s, %s}\n", tp3, ptr, ind2, hashtab[ind2].key, hashtab[ind2].val);
            while (hashtab[ind2].key && strcmp(hashtab[ind2].key, ptr + 1))
                ind2 = (ind2 + 1) % HASHLEN;
            if (hashtab[ind2].key)
                printf("%s\n", ((strcmp(hashtab[ind2].key, ptr + 1))?"UNKNOWN":hashtab[ind2].val));
            else
                printf("UNKNOWN\n");
        }
        else
            printf("UNKNOWN\n");
    }
    // Free all strdup...
    for (int i=0;i<N;i++)
    {
        free(hashtab[i].key);
        hashtab[i].key = NULL;
        free(hashtab[i].val);
        hashtab[i].val = NULL;
    }
    return (0);
}
