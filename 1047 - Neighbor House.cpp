#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i, n) for (int i=0; i<n; i++)
#define FOR1(i, n) for (int i=1; i<=n; i++)
 
#define MAX 100
 
int n, color[MAX][5];
long long dp[MAX][5];
long long res;
 
void solve(int pos, int c, long long sum)  {
     if (pos > n){
        res = min(res, sum);
        return;
     }
 
     for (int i=1; i<=3; i++){
          if (i!=c){
                if (dp[pos][i]==-1 || dp[pos][i] > sum + color[pos][i]){
                    dp[pos][i] = sum + color[pos][i];
                    solve(pos+1, i, sum+color[pos][i]);
                }
          }
     }
}
 
void reset(){
    res = 20000000000;
    memset(dp, -1, sizeof(dp));
}
 
int main()
{
    int T; scanf("%d", &T);
 
    FOR1(cs, T){
 
        reset();
 
        scanf("%d", &n);
 
        FOR1(i, n){
            FOR1(j, 3){
                scanf("%d", &color[i][j]);
            }
        }
 
        solve(1, -1, 0);
        printf("Case %d: %lld\n", cs, res);
    }
    return 0;
}
