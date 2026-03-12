#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 400

// STD : LC
typedef struct aircraft
{
    int x;
    int y;
    struct AC *n;
}AC;

typedef struct
{
    AC* h;
} LAC;

AC *createAC(int x, int y){
    AC *res = malloc(sizeof(AC));
    if(!res){fprintf(stderr,"Error: Out of memory\n"); return NULL; }
    res->x = x;
    res->y = y;
    res->n = NULL;
    return res;
}

void freeAC(AC *ac){
    if(ac){
        if(ac->n){
            free(ac->n);
        }
        free(ac);
    }
}

LAC *initLAC(){
    LAC *res = malloc(sizeof(AC));
    if(!res){fprintf(stderr,"Error: Out of memory\n"); return NULL; }
    res->h = NULL;
    return res;
}

void freeLAC(LAC *L){
    AC *c = L->h;
    if(c){
        freeAC(c);
        c = c->n;
    }
    free(L);
}

void addAC(LAC *L,int x, int y){
    AC *ac = createAC(x, y);
    ac->n = L->h;
    L->h = ac;
}

int main(){
    LAC *L=initLAC();
    int tab[MAX]={0};
    int X,Y,O;
    scanf("%d",&X);
    for (int i=1;i<=X;i++){
        char l[41];
        scanf("%s",l);
        int Y=strlen(l);
        for (int j=1;j<=Y;j++){
            if (i<X && l[j-1]!='.'){ addAC(L,i,j);}
            if (l[j-1]=='^'){O=j;}
        }
    }
    int max=0;
    AC *c = L->h;
    while(c){
        int l=(c->y < O)?(O - c->y):(c->y - O);
        int h=X-c->x ;
        int index=(l<=h)?h-l:l-h;
        tab[index]=1;
        if(max<index){max=index;}
        c = c->n;
    }
    for (int i=1;i<=max;i++){printf((tab[i])?"SHOOT\n":"WAIT\n"); }
    freeLAC(L);
    return 0;
}
