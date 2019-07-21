#include<bits/stdc++.h>
using namespace std;

#define MX 105
int A[MX];

int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);
        int res = 0;
        bool one = true;
        for (int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
            res ^= A[i];
            if (A[i] > 1) one = false;
        }

        printf("Case %d: ", cs);
        if (one){ // if all the piles are of height 1, parity decides who wins
            (n & 1) ? printf("Bob\n") : printf("Alice\n");
        }
        else
            (res) ? printf("Alice\n") : printf("Bob\n");
    }
    return 0;
}
