#include<bits/stdc++.h>
using namespace std;
 
#define MAX 110
 
long long dp[MAX][10010];
int item[MAX];
int weight[MAX];
long long profit;
bool possible;
 
void reset(){
    profit = 0;
    possible = true;
}
 
long long knapsack(int n, int w){
 
    for (int i=1; i<=n; i++){
        for (int j=1; j<=w; j++){
            if (j < weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i]] + item[i]);
        }
    }
 
    return dp[n][w];
}
 
int main()
{
    int T; scanf("%d", &T);
    for (int cs=1; cs<=T; cs++){
        reset();
 
        int n, w, c;
        scanf("%d%d", &n, &w);
        for (int i=1; i<=n; i++){
            scanf("%d%d%d", &item[i], &c, &weight[i]);
            w -= weight[i] * c;
            //profit += item[i] * c;
            if (w < 0) possible = false;
        }
 
        if (!possible){
            printf("Case %d: Impossible\n", cs);
            continue;
        }
 
        profit = knapsack(n, w);
        printf("Case %d: %lld\n", cs, profit);
    }
    return 0;
}
 
