#include <stdlib.h>
#include <stdio.h>
#include <string.h> // strsep()
#include <math.h>
#include <float.h>
#define DEBUG_MODE 0 // 0:desable debug print, 1:enable
#define SIZE 51 
#define LEN 257
void    replace_char_in_str(char *str, char match, char replace)
{
    int i;
    if (str && match) 
    {
        i = -1;
        while (str[++i])
        {
            if (str[i]==match)
                str[i] = replace;
        }
    }
}
typedef struct s_point
{
    double  x; // Longitude
    double  y; // Latitude
} t_point ;
t_point t_point_init(double x, double y)
{
    t_point res;
    res.x = x;
    res.y = y;
    if (DEBUG_MODE)
        fprintf(stderr, "[init t_point]->(%lf, %lf)\n", x, y);
    return (res);
}
void t_point_print(t_point src)
{ 
    if (DEBUG_MODE)
        fprintf(stderr, "(%lf, %lf)",src.x, src.y);
}
double distBetween(t_point a, t_point b)
{
    double x = (b.x - a.x) * cos((b.y+a.y)/2);
    double y = (b.y - a.y);
    return (6371 * sqrt(x*x + y*y));
}
typedef struct s_defib
{
    int     id;
    char    name[62];
    char    add[62];
    char    phone[15];
    t_point cood;
    float   dist;
} t_defib;
t_defib t_defib_init(char *str)
{
    t_defib res = {0};
    double  tmp1;
    double  tmp2;
    char *token;
    if (!(token = strsep(&str, ";")))
        return (fprintf(stderr, "ERROR: t_defib_init()->strtok() return null token [ON ID]\n"), res);
    res.id = -1;
    if (token)
      res.id = atoi(token);
    if (!(token = strsep(&str, ";")))
        return (fprintf(stderr, "ERROR: t_defib_init()->strtok() return null token [ON NAME]\n"), res);
    strncpy(res.name, token, strlen(token));
    if (!(token = strsep(&str, ";")))
        return (fprintf(stderr, "ERROR: t_defib_init()->strtok() return null token [ON ADD]\n"), res);
    strncpy(res.add, token, strlen(token));
    if (!(token = strsep(&str, ";")))
        return (fprintf(stderr, "ERROR: t_defib_init()->strtok() return null token [ON PHONE]\n"), res);
    strncpy(res.phone, token, strlen(token));
    if (!(token = strsep(&str, ";")))
        return (fprintf(stderr, "ERROR: t_defib_init()->strtok() return null token [ON LONG]\n"), res);
    tmp1 = atof(token);
    if (!(token = strsep(&str, ";")))
        return (fprintf(stderr, "ERROR: t_defib_init()->strtok() return null token [ON LAT]\n"), res);
    tmp2 = atof(token);
    res.cood = t_point_init(tmp1, tmp2);
    res.dist = FLT_MAX;
    return (res);
}
void t_defib_print(t_defib src)
{
    if (DEBUG_MODE)
    {
        fprintf(stderr, "{id[%d], name:'%s', add:'%s', phone:'%s', ",src.id , src.name, src.add, src.phone);
        t_point_print(src.cood);
        fprintf(stderr, ", dist=%lf}\n", src.dist);
    }
}
int main()
{
    t_point user = {0};
    t_defib *closest_def = NULL;
    char LON[SIZE] = ""; scanf("%s", LON);
    replace_char_in_str(LON, ',', '.');
    user.x = atof(LON);
    char LAT[SIZE] = ""; scanf("%s", LAT);
    replace_char_in_str(LAT, ',', '.');
    user.y = atof(LAT);
    int N; scanf("%d", &N); fgetc(stdin);
    if (DEBUG_MODE)
        fprintf(stderr, "INIT:\n - N=%d\n - long:%s\n - lat :%s\n", N, LON, LAT);
    t_defib ARRAY[N];
    char DEFIB[N][LEN];
    for (int i=0;i<N;i++)
    {
        scanf("%[^\n]", DEFIB[i]);
        replace_char_in_str(DEFIB[i], ',', '.');
        if (DEBUG_MODE)
            fprintf(stderr, "INSIDE[%d]->%s\n", i, DEFIB[i]);
        fgetc(stdin);
        ARRAY[i]=t_defib_init(DEFIB[i]);
        ARRAY[i].dist = distBetween(user, ARRAY[i].cood);
    }
    if (DEBUG_MODE)
    {
        fprintf(stderr, "PRINT_START:\nUser=");
        t_point_print(user);
        fprintf(stderr, "\n");
    }
    closest_def = &ARRAY[0];
    for (int i=0;i<N;i++)
    {
        t_defib_print(ARRAY[i]);
        if (ARRAY[i].dist < closest_def->dist)
            closest_def = &ARRAY[i];
    }
    printf("%s\n", closest_def->name);
    return (0);
}
