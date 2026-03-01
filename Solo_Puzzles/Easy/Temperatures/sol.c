#include <stdlib.h>
#include <stdio.h>
int main()
{
    int min_temp = 5526;    // temperature vales in [-271, 5526]
    int t, n, abs_a, abs_b;
    scanf("%d", &n);
    if (n <= 0)
        return (printf("0"),0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        abs_a = abs(t);
        abs_b = abs(min_temp);
        if (abs_a<abs_b){min_temp=t;}
        else if (abs_a == abs_b && t > 0){min_temp=t;}
    }
    return (printf("%d\n", min_temp), 0);
}
