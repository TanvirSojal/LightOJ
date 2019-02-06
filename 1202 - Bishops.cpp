#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T, cs=1;
    long r1, c1, r2, c2;
 
    scanf("%d", &T);
 
    while(T--){
        scanf("%ld%ld%ld%ld", &r1, &c1, &r2, &c2);
 
        if (!(abs(r1-r2)%2==1  && abs(c1-c2)%2==1) && !(abs(r1-r2)%2==0 && abs(c1-c2)%2==0)){
            printf("Case %d: impossible\n", cs++);
        }
        else{
            if (abs(r1-r2)==abs(c1-c2)) printf("Case %d: 1\n", cs++);
            else printf("Case %d: 2\n", cs++);
        }
    }
 
    return 0;
}
