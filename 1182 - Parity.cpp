#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int i=1; i<=T; i++){
        int n, count=0;
        scanf("%d", &n);
 
        while(n!=0){
            bool rem = n%2;
            if (rem) count++;
            n/=2;
        }
 
        if (count%2) printf("Case %d: odd\n", i);
        else printf("Case %d: even\n", i);
    }
 
    return 0;
}
