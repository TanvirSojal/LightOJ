#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);
        int res = 0;
        for (int i = 1; i <= n; i++){
            int x, y; scanf("%d %d", &x, &y);
            res ^= (y - x - 1); // distance between the pieces is the pile of NIM
        }
        printf("Case %d: ", cs);
        (res) ? printf("Alice\n") : printf("Bob\n");
    }
    return 0;
}
