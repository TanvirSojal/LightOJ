#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main(){
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n, m; scanf("%d%d", &n, &m);
        ll res = 0;
        for (int i = 1; i <= n; i++){
            ll row = 0;
            for (int j = 1; j <= m; j++){
                ll temp; scanf("%lld", &temp);
                row += temp;
            }
            res ^= row; // all the numbers in a row works as a single NIM pile
        }
        printf("Case %d: ", cs);
        (res) ? printf("Alice\n") : printf("Bob\n");
    }
}
