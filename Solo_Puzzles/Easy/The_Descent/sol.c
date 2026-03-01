#include <stdlib.h>
#include <stdio.h>
int main() {
    while (1) {
        int max ;
        scanf("%d", &max);
        int index= 0;
        for (int i = 1; i < 8; i++) {
            int mountain_h;
            scanf("%d", &mountain_h);
            if(mountain_h>max){max=mountain_h;index=i;}
        }
        printf("%d\n",index);
    }
    return 0;
}
