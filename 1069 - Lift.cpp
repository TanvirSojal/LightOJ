#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int cs=1; cs<=T; cs++){
        int a, b;
        scanf("%d%d", &a, &b);
 
        int res = abs(a-b)*4 + a*4 + 19;
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
