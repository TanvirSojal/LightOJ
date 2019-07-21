#include<bits/stdc++.h>
using namespace std;

#define MX 102

int A[3][MX];

int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);
        int res = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[1][i]);

        for (int i = 1; i <= n; i++){
            scanf("%d", &A[2][i]);
            res ^= (A[2][i] - A[1][i] - 1); // distance between the chess pieces can be thought of a pile of stones in NIM
        }
        printf("Case %d: ", cs);
        (res) ? printf("white wins\n") : printf("black wins\n");
    }
    return 0;
}
