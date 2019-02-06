#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
    for (int i=1; i<=T; i++){
        int n, P, Q, count=0, x=0;
        scanf("%d%d%d", &n, &P, &Q);
        int a[n];
        for (int j=0; j<n; j++){
            scanf("%d", &a[j]);
            x+=a[j];
            if (count<P && x<=Q) count++;
        }
        printf("Case %d: %d\n", i, count);
    }
    return 0;
}
 
