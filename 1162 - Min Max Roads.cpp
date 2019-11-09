#include<bits/stdc++.h>
using namespace std;

#define MX 100002

struct node{
    int u;
    int w;
};

vector<node> G[MX];
int tin[MX];
int tout[MX];
int up[MX][18];
int MIN[MX][18];
int MAX[MX][18];
int timer;
int ansMin, ansMax;

void reset(){
    for (int i = 0; i < MX; i++){
        G[i].clear();

        for (int j = 0; j < 18; j++){
            MIN[i][j] = INT_MAX;
            MAX[i][j] = 0;
        }
    }
    timer = 0;
}

void dfs(int n, int p, int w){
    tin[n] = ++timer;

    up[n][0] = p;
    MIN[n][0] = w;
    MAX[n][0] = w;

    for (int i = 1; i < 18; i++){
        up[n][i] = up[up[n][i-1]][i-1];
        MAX[n][i] = max(MAX[n][i-1], MAX[up[n][i-1]][i-1]);
        MIN[n][i] = min(MIN[n][i-1], MIN[up[n][i-1]][i-1]);
    }

    for (auto nxt : G[n]){
        int v = nxt.u;
        int cost = nxt.w;
        if (v == p) continue;
        dfs(v, n, cost);
    }

    tout[n] = ++timer;
}

bool isAncestor(int u, int v){
    return tin[v] >= tin[u] && tout[v] <= tout[u];
}

int findLCA(int u, int v){
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;

    for (int i = 17; i >= 0; i--){
        if (!isAncestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

void solve(int u, int v){

    for (int i = 17; i >= 0; i--){
        if (!isAncestor(up[u][i], v)){
            ansMin = min(ansMin, MIN[u][i]);
            ansMax = max(ansMax, MAX[u][i]);
            u = up[u][i];
        }
    }
    ansMin = min(ansMin, MIN[u][0]);
    ansMax = max(ansMax, MAX[u][0]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();

        int n; scanf("%d", &n);
        for (int i = 1; i < n; i++){
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }

        dfs(1, 1, 0);
        int q; scanf("%d", &q);

        printf("Case %d:\n", cs);

        while(q--){
            int u, v; scanf("%d%d", &u, &v);

            ansMin = INT_MAX;
            ansMax = 0;

            int lca = findLCA(u, v);
            if (u != lca) solve(u, lca);
            if (v != lca) solve(v, lca);

            printf("%d %d\n", ansMin, ansMax);
        }

    }
    return 0;
}
