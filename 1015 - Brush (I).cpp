#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    scanf("%d", &t);
 
    for (int i=1; i<=t; i++){
        int n, sum=0;
        scanf("%d", &n);
 
        while(n--){
            int x;
            scanf("%d", &x);
            if (x>=0) sum+=x;
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}
