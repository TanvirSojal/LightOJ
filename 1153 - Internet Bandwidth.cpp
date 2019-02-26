#include<bits/stdc++.h>
using namespace std;
 
#define MX 105
 
vector < int > G[MX];
bool vis[MX];
int parent[MX];
int cap[MX][MX];
 
void reset(){
    for (int i = 1; i < MX; i++){
        G[i].clear();
        for (int j = 1; j < MX; j++){
            cap[i][j] = 0;
        }
    }
}
 
bool bfs(int s, int t){
    // reset vis and parent tables
    for (int i = 1; i < MX; i++){
        vis[i] = 0;
        parent[i] = i;
    }
 
    queue < int > Q;
    vis[s] = 1;
    parent[s] = s;
    Q.push(s);
 
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        if (now == t)
            return true;
        for (int i = 0; i < G[now].size(); i++){
            int next = G[now][i];
            if (!vis[next] && cap[now][next] > 0){
                vis[next] = 1;
                parent[next] = now;
                Q.push(next);
            }
        }
    }
    return false;
}
 
int flow(int s, int t){
    int total = 0;
 
    while(bfs(s, t)){
        int mn = INT_MAX;
        for (int next = t; next != s; next = parent[next]){
            int now = parent[next];
            mn = min(mn, cap[now][next]);
        }
        for (int next = t; next != s; next = parent[next]){
            int now = parent[next];
            cap[now][next] -= mn;
            cap[next][now] += mn;
        }
        total += mn; // adding to total flow
    }
    return total;
}
 
int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();
 
        int n; scanf("%d", &n);
        int s, t, c; scanf("%d%d%d", &s, &t, &c);
        for (int i = 1; i <= c; i++){
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            cap[u][v] += w;
            cap[v][u] += w;
        }
        int res = flow(s, t);
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
