#include<bits/stdc++.h>
using namespace std;
 
#define MX 105
#define INF 20000000
vector < int > G[MX];
int distSource[MX];
int distDest[MX];
int vis[MX];
int color;
 
void reset(){
    for (int i = 0; i < MX; i++){
        G[i].clear();
        distSource[i] = INF;
        distDest[i] = INF;
    }
    color = 0;
}
 
void bfs(int n){
    vis[n] = color;
    queue < int > q;
    q.push(n);
    distSource[n] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 0; i < G[cur].size(); i++){
            int nxt = G[cur][i];
            if (vis[nxt] != color){
                vis[nxt] = color;
                distSource[nxt] = distSource[cur] + 1;
                q.push(nxt);
            }
        }
    }
}
 
void bfs2(int n){
    vis[n] = color;
    queue < int > q;
    q.push(n);
    distDest[n] = 0;
 
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 0; i < G[cur].size(); i++){
            int nxt = G[cur][i];
            if (vis[nxt] != color){
                vis[nxt] = color;
                distDest[nxt] = distDest[cur] + 1;
                q.push(nxt);
            }
        }
    }
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();
        ++color;
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++){
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int s, d; scanf("%d%d", &s, &d);
        bfs(s); // bfs from source (min time to go to each building)
        ++color;
        bfs2(d); // bfs from destination (min time to reach destination)
        int res = 0;
        for (int i = 0; i < n; i++){
            res = max(res, distSource[i] + distDest[i]); // (time to reach from source + time to reach destination)
        }
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
