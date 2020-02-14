#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MX 18

const int MX_MASK = 1 << 16;
int n, A[MX][MX];
int vis[MX][MX_MASK + 10];
int color;
ll dp[MX][MX_MASK + 10];

bool isSet(int &N, int pos){
    return (N >> pos) & 1;
}

ll go(int pos, int mask){
    if (pos >= n)
        return 0;
    if (vis[pos][mask] == color)
        return dp[pos][mask];

    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (isSet(mask, i)) // if bride is already taken, skip 
            continue;
        ans = max(ans, A[pos][i] + go(pos+1, (mask | (1 << i))));
    }

    vis[pos][mask] = color;
    return dp[pos][mask] = ans;
}


int main()
{
//    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        color++;

        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                scanf("%d", &A[i][j]);
            }
        }
        ll ans = go(0, 0);
        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}
