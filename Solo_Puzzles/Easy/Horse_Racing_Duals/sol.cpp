#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;cin>>n;cin.ignore();
    int L[n],S[n-1];
    for (int i=0;i<n;i++){cin>>L[i];cin.ignore();}
    sort(L, L+n);
    for (int i=0;i<n-1;i++){S[i]=L[i+1]-L[i];}
    sort(S, S+(n-1));
    printf("%d",S[0]);
}
