#include<bits/stdc++.h>
using namespace std;

#define MX 50003
#define WHITE 0
#define GRAY 1
#define BLACK 2

vector < int > G[MX];
int cnt[MX];
int par[MX]; // to keep the lowest node of cycle
int vis[MX];
int color;
bool cycle;

int res, mx;

void reset(){
    for (int i = 0; i < MX; i++){
        G[i].clear();
        cnt[i] = 0;
        vis[i] = 0;
        par[i] = i;
    }
    mx = 0;
    res = 0;
}

void cycleUpdate(int n, int c){
    cnt[n] = c;
    vis[n] = 3;
    for (int i = 0; i < G[n].size(); i++){
        int v = G[n][i];
        if (vis[v] != 3)
            cycleUpdate(v, c);
    }

}

void dfs(int n){
    vis[n] = GRAY;
    cnt[n] = 1;
    for (int i = 0; i < G[n].size(); i++){
        int v = G[n][i];
        if (vis[v] == GRAY)
            cycle = true;

        if (vis[v] >= BLACK) // if the next node is done, get it's value instead of re-traversing the same path
            cnt[n] += cnt[v];

        if (vis[v] == WHITE){
            dfs(v);
            cnt[n] += cnt[v];
        }
    }
    vis[n] = BLACK;
    mx = max(mx, cnt[n]);
}

int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        for (int i = 1; i <= n; i++){
            if (vis[i] == WHITE){
                cycle = false;
                dfs(i);
                if (cycle)
                    cycleUpdate(i, cnt[i]); // if there is a cycle, update all node with same count, since starting from any one of them will result in same count
            }

        }
        for (int i = 1; i <= n; i++){
            if (cnt[i] == mx){
                res = i;
                break;
            }
        }
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
