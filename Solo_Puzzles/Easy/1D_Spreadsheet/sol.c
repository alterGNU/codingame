#include <stdlib.h>
#include <stdio.h>
#define VMAX 10001
typedef struct s_cell
{
    char    o[6];
    char    a[7];
    char    b[7];
    int     v;
} t_cell;
void    set_cell(t_cell *A, int i) {scanf("%s%s%s", A[i].o, A[i].a, A[i].b);A[i].v=VMAX;}
int     compute(int a, char op, int b){return ((op == 'A')?a + b:((op == 'S')?a - b:a*b));}
int     eval(t_cell *A, int i);
int     solve(char arg[7], t_cell *arr){return ((arg[0] == '$')?eval(arr, atoi(++arg)):atoi(arg));}
int     eval(t_cell *A, int i)
{
    int     res;

    if (A[i].v < VMAX)
        return (A[i].v);
    res = ((A[i].o[0] == 'V')?solve(A[i].a, A):compute(solve(A[i].a, A), A[i].o[0], solve(A[i].b, A)));
    return (A[i].v = res, res);
}
int main()
{
    int N;
    scanf("%d", &N);
    t_cell A[N + 1];
    for (int i = 0; i < N; i++){set_cell(A, i);}
    for (int i = 0; i < N; i++){eval(A, i);printf("%d\n", A[i].v);}
    return (0);
}
