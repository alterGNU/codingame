#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#define DEBUG_MODE 0 // 0:desable, 1:enable
void    *ft_free(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
    return (NULL);
}
// NOTE: dynam. alloc. use for training purpose ^^'
typedef struct s_matrix
{
    int x;      // Number of line
    int y;      // Line's Length
    int **mat;  // Matrix
} t_matrix;
void    t_matrix_free(t_matrix *m)
{
    if (m)
    {
        if (m->mat)
        {
            for (int i = 0; i < m->x; i++)
                ft_free((void **)&m->mat[i]);
            ft_free((void **)&m->mat);
        }
        ft_free((void **)&m);
    }
}
t_matrix   *t_matrix_init(int x, int y)
{
    if (x < 1 || y < 1)
        return(errno=EINVAL, perror("t_matrix_init()<-NULL arguments"), NULL);
    t_matrix *res = malloc(sizeof(t_matrix));
    if (!res)
        return(perror("t_matrix_init()<-malloc() failed"), NULL);
    res->x = x;
    res->y = y;
    res->mat = calloc(x, sizeof(int *));
    if (!res->mat)
        return(perror("t_matrix_init()<-calloc() failed"), t_matrix_free(res), NULL);
    for (int i=0;i<x;i++)
    {
        res->mat[i] = calloc(y, sizeof(int));
        if (!res->mat[i])
            return(perror("t_matrix_init()<-calloc() at line failed"), t_matrix_free(res), NULL);
    }
    return (res);
}
void    t_matrix_print_raw(t_matrix *m)
{
    fprintf(stderr, "Matrix:\n");
    for (int i=0;i<m->x;i++)
    {
        for (int j=0;j<m->y;j++)
            fprintf(stderr, "%2d", m->mat[i][j]);
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n");
}
void    t_matrix_print(t_matrix *m)
{
    int v;
    for (int i=0;i<m->x;i++)
    {
        for (int j=0;j<m->y;j++)
            printf("%c", (m->mat[i][j]>0?m->mat[i][j]+'0':'.'));
        printf("\n");
    }
}
int    get_tot_bomb_around(t_matrix *m, int px, int py)
{
    int value = 0;
    if (px > 0)
    {
        value += (int)(m->mat[px - 1][py] < 0);         // NORTH
        if (py > 0)
            value += (int)(m->mat[px - 1][py - 1] < 0); // NORTH-WEST
        if (py + 1 < m->y)
            value += (int)(m->mat[px - 1][py + 1] < 0); // NORTH-EAST
    }
    if (py + 1 < m->y)
        value += (int)(m->mat[px][py + 1] < 0);         // EAST
    if (px + 1 < m->x)
    {
        if (py + 1 < m->y)
            value += (int)(m->mat[px + 1][py + 1] < 0); // SOUTH-EAST
        value += (int)(m->mat[px + 1][py] < 0);         // SOUTH
        if (py > 0)
            value += (int)(m->mat[px + 1][py - 1] < 0); // SOUTH-WEST
    }
    if (py > 0)
        value += (int)(m->mat[px][py - 1] < 0);         // WEST
    return (value);
}
void    t_matrix_run_counting(t_matrix *m)
{
    for (int i=0;i<m->x;i++)
    {
        for (int j=0;j<m->y;j++)
        {
            if (m->mat[i][j] >= 0)
                m->mat[i][j] = get_tot_bomb_around(m, i, j);
        }
    }
}
int main()
{
    int w;
    scanf("%d", &w);
    int h;
    scanf("%d", &h); fgetc(stdin);
    t_matrix *m = t_matrix_init(h,w);
    if (DEBUG_MODE)
        t_matrix_print_raw(m);
    for (int i = 0; i < h; i++)
    {
        char line[101] = "";
        scanf("%[^\n]", line);
        fgetc(stdin);
        for (int j=0;j<w;j++)
            m->mat[i][j] = (line[j] == '.')?0:-1;
    }
    if (DEBUG_MODE)
        t_matrix_print_raw(m);
    t_matrix_run_counting(m);
    t_matrix_print(m);
    t_matrix_free(m);
    return (0);
}
