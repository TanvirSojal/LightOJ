#include<bits/stdc++.h>
using namespace std;

#define MX 100002

struct edge{
    int u;
    int v;
    int w;
};

bool cmp(edge a, edge b){
    return a.w <  b.w;
}

struct node{
    int u;
    int w;
};

vector<edge> edges;
vector<node> G[MX];
int parent[MX];
int tin[MX];
int tout[MX];
int up[MX][18];
int MAX[MX][18];
int timer;
int ansMin, ansMax;

void reset(){
    edges.clear();
    for (int i = 0; i < MX; i++){
        G[i].clear();
        parent[i] = i;

        for (int j = 0; j < 18; j++){
            MAX[i][j] = 0;
        }
    }
    timer = 0;
}

int Find(int u){
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

void preprocess(int m){
   sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < m; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int p = Find(u);
        int q = Find(v);

        if (p != q){
            parent[q] = p;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }
}


void dfs(int n, int p, int w){
    tin[n] = ++timer;

    up[n][0] = p;
    MAX[n][0] = w;

    for (int i = 1; i < 18; i++){
        up[n][i] = up[up[n][i-1]][i-1];
        MAX[n][i] = max(MAX[n][i-1], MAX[up[n][i-1]][i-1]);
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
            ansMax = max(ansMax, MAX[u][i]);
            u = up[u][i];
        }
    }
    ansMax = max(ansMax, MAX[u][0]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();

        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++){
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            edges.push_back({u, v, w});
        }


        preprocess(m);

        dfs(1, 1, 0);
        int q; scanf("%d", &q);

        printf("Case %d:\n", cs);

        while(q--){
            int u, v; scanf("%d%d", &u, &v);
            ansMax = 0;

            int lca = findLCA(u, v);
            if (u != lca) solve(u, lca);
            if (v != lca) solve(v, lca);

            printf("%d\n", ansMax);
        }

    }
    return 0;
}

