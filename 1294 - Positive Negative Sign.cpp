#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T, cs=1;
    scanf("%d", &T);
 
    while(T--){
        long long n, m;
 
        scanf("%lld%lld", &n, &m);
 
        printf("Case %d: %lld\n", cs++, (n*m)/2);
    }
    return 0;
}
