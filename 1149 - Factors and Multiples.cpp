#include<bits/stdc++.h>
using namespace std;
 
#define MX 205
#define INF 2147483647
 
#define WHITE 1
#define BLACK 2
 
vector < int > G[MX];
bool vis[MX];
int parent[MX];
int cap[MX][MX];
 
int A[MX];
int B[MX];
 
int cnt;
 
void reset(){
    cnt = 0;
    for (int i = 0; i < MX; i++){
        G[i].clear();
        vis[i] = 0;
        for (int j = 0; j < MX; j++){
            cap[i][j] = 0;
        }
    }
}
 
bool bfs(int s, int t){
    for (int i = 0; i < MX; i++){
        vis[i] = 0;
        parent[i] = i;
    }
    vis[s] = 1;
    parent[s] = s;
    queue < int > Q;
    Q.push(s);
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        if (now == t)
            return true;
        for (int i = 0; i < G[now].size(); i++){
            int nxt = G[now][i];
            if (!vis[nxt] && cap[now][nxt] > 0){
                vis[nxt] = 1;
                parent[nxt] = now;
                Q.push(nxt);
            }
        }
    }
    return false;
}
 
int flow(int s, int t){
    int total = 0;
    while(bfs(s, t) == true){
        int mn = INF;
        for (int next = t; next != s; next = parent[next]){
            int now = parent[next];
            cap[now][next]--;
            cap[next][now]++;
        }
        ++total;
    }
    return total;
}
 
int main()
{
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();
 
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
            G[0].push_back(i);
            G[i].push_back(0);
            cap[0][i] = 1;
        }
 
        int m; scanf("%d", &m);
        for (int i = 1; i <= m; i++){
            scanf("%d", &B[i]);
            G[n+i].push_back(n+m+1);
            G[n+m+1].push_back(n+i);
            cap[n+i][n+m+1] = 1;
 
            for (int j = 1; j <= n; j++){
                if (A[j] == 0){
                    if (B[i] == A[j]){
                        G[j].push_back(n+i);
                        G[n+i].push_back(j);
                        cap[j][n+i] = 1;
                    }
                    continue;
                }
                if (B[i] % A[j] == 0){
                    G[j].push_back(n+i);
                    G[n+i].push_back(j);
                    cap[j][n+i] = 1;
                }
            }
        }
 
        int res = flow(0, n+m+1);
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
