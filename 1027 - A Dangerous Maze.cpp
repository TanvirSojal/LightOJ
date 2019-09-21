#include<bits/stdc++.h>
using namespace std;

#define MX 102
int A[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);

    for (int cs = 1; cs <= T; cs++){
        int n; scanf("%d", &n);

        bool possible = false;

        int ans = 0; // numerator
        int neg = 0;

        for (int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
            ans += abs(A[i]);
            if (A[i] > 0) possible = true;
            else neg++;
        }
        printf("Case %d: ", cs);
        if (!possible){
            printf("inf\n");
            continue;
        }

        neg = (n - neg); // denominator is (N - negatives)
        int g = __gcd(ans, neg);

        printf("%d/%d\n", (ans/g) , (neg/g));
    }
    return 0;
}
