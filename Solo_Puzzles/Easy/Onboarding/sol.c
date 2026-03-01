#include <stdio.h>
#define LEN 257
int main()
{
    while (1)
    {
        char e1[LEN];scanf("%s", e1);
        int d1; scanf("%d", &d1);
        char e2[LEN];scanf("%s", e2);
        int d2; scanf("%d", &d2);
        printf("%s\n",(d1 < d2)?e1:e2);
    }
    return 0;
}
