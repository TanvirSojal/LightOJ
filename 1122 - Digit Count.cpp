#include<bits/stdc++.h>
using namespace  std;

#define MX 12
#define ll long long
int digits[MX];
int dp[MX][MX];
int m, n;

int F(int last, int cnt){
    if (cnt >= n) return 1;
    if (dp[last][cnt] != -1) return dp[last][cnt];
    int tot = 0;
    for (int i = 1; i <= m; i++){
        if (abs(digits[i] - last) <= 2){
            tot += F(digits[i], cnt+1);
        }
    }
    return dp[last][cnt] = tot;
}

int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= m; i++){
            scanf("%d", &digits[i]);
        }
        int ans = 0;
        for (int i = 1; i <= m; i++){
            ans += F(digits[i], 1);
        }
        printf("Case %d: %d\n", cs, ans);
    }
}

