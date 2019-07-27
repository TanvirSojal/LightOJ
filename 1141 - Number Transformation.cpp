#include<bits/stdc++.h>
using namespace std;

#define MX 1002

vector < int > G[MX];
bool vis[MX];
int dist[MX];

void reset(){
    for (int i = 0; i < MX; i++){
        vis[i] = 0;
        dist[i] = 0;
    }
}

// Constructing graph with all prime factors of a number connected to it. this graph is constant for all test cases. We do not reset it
void gen_graph(){
    for (int i = 1; i < MX; i++){
        int temp = i;
        for (int j = 2; j < i; j++){
            if (temp % j == 0 && j != i){
                while(temp % j == 0){
                    temp /= j;
                }
                G[i].push_back(j);
            }
        }
    }
}

int bfs(int s, int t){
    vis[s] = 1;
    dist[s] = 0;
    queue < int > q;
    q.push(s);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        if (n == t){
            return dist[t];
        }
        for (int i = 0; i < G[n].size(); i++){
            int v = n + G[n][i];
            if (!vis[v] && v <= t){
                dist[v] = dist[n] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    gen_graph();
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();
        int s, t; scanf("%d%d", &s, &t);
        int res = bfs(s, t);
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
