#include<bits/stdc++.h>
using namespace std;

#define ll long long
int A[52];
int C[52];
ll dp[52][1002];
int n, k;

const int MOD = 100000007;

void reset(){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = -1;
        }
    }
}

ll F(int pos, int sum){
    if (sum == k) return 1;
    if (sum > k || pos > n) return 0;
    if (dp[pos][sum] != -1) return dp[pos][sum];
    ll tot = 0;
    for (int i = 0; i <= C[pos]; i++){
        tot += F(pos+1, sum + i * A[pos]);
        tot %= MOD;
    }
    return dp[pos][sum] = tot;
}

int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        scanf("%d%d", &n, &k);
        reset();
        for (int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= n; i++){
            scanf("%d", &C[i]);
        }
        ll ans = F(1, 0);
        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}
