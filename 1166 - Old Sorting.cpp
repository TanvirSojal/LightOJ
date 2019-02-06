#include<bits/stdc++.h>
using namespace std;
 
int a[110];
int pos[110];
 
int main()
{
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++){
        int n, cnt = 0;
        scanf("%d", &n);
        for (int i=1; i<=n; i++){
            scanf("%d", &a[i]);
            pos[a[i]] = i;
        }
        for (int i=1; i<=n; i++){
            if (a[i]!=i){
                ++cnt;
                int index = pos[i];
                a[index] = a[i];
                pos[a[i]] = index;
                a[i] = i;
            }
 
        }
        printf("Case %d: %d\n", cs, cnt);
    }
    return 0;
}
 
