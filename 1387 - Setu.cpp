#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int i=1; i<=T; i++){
        int n;
        long sum = 0;
        string s;
 
        scanf("%d", &n);
 
        printf("Case %d:\n", i);
 
        while(n--)
        {
            cin >>s;
            if (s=="donate"){
                int x;
                scanf("%d", &x);
                sum += x;
            }
            else{
                printf("%ld\n", sum);
            }
        }
    }
    return 0;
}
