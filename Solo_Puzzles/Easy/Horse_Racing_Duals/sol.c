#include <stdio.h>
#include <stdlib.h>

int main() {
    // BUILD LIST
    int N;
    scanf("%d", &N);
    int *tab = (int *)malloc(N*sizeof(int));
    for (int i=0; i<N; i++){ scanf("%d", &tab[i]); }
    // SORT LIST
    int comparer_entiers(const void *a, const void *b) { return (*(int *)a - *(int*)b); }
    qsort(tab,N,sizeof(int),comparer_entiers);
    // FOUND MIN ABS
    int min = tab[1]-tab[0];
    for (int i=1;i<N-1;i++){
        int diff = tab[i+1] - tab[i];
        if(diff<min){min=diff;}
    }
    printf("%d",min);
    // FREEDOM
    free(tab);
    return 0;
}
