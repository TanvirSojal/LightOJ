#include<bits/stdc++.h>
using namespace std;

/**
    Since the graph is actually a ring, we will sum all the clockwise and counter-clockwise edges and the minimum of them is the answer. 
**/

#define MX 105
#define CLOCKWISE 0
#define COUNTER_CLOCKWISE 1

// to make sure only one outDegree for root
#define GRAY 1
#define BLACK 2

struct node{
    int u;
    bool dir; // clockwise or counter-clockwise
    int cost; // cost of reverting
};

vector < node > G[MX];
int vis[MX];
int clockwiseSum, counterClockwiseSum;

void reset(){
    for (int i = 0; i < MX; i++){
        G[i].clear();
        vis[i] = 0;
    }
    clockwiseSum = 0, counterClockwiseSum = 0;
}

void dfs(int n, int p){
    vis[n] = GRAY;
    for (int i = 0; i < G[n].size(); i++){
        int nxt = G[n][i].u;
        int dir = G[n][i].dir;
        int cost = G[n][i].cost;

        if (vis[nxt] != BLACK && nxt != p){ // for parent we do not add cost, since that path cost is already checked
            //cout << n << "  ->  " << nxt << "  dir: " << dir << endl;
            if (dir == CLOCKWISE) clockwiseSum += cost;
            else counterClockwiseSum += cost;
        }

        if (!vis[nxt])
            dfs(nxt, n);
    }
    vis[n] = BLACK;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++){
        reset();
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, CLOCKWISE, w}); // we put a clockwise edge
            G[v].push_back({u, COUNTER_CLOCKWISE, w}); // also a counter-clockwise edge so DFS does not interrupt
        }
        dfs(1, -1);
        int res = min(clockwiseSum, counterClockwiseSum);
        printf("Case %d: %d\n", cs, res);
    }
    return 0;
}
