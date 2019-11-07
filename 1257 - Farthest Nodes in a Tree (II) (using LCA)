#include<bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0;  i < n; i++)
#define FOR1(i, n) for (int i = 1;  i <= n; i++)

#define MX 50002
#define ll long long
struct Node{
    int u;
    int w;
};
vector<Node> G[MX];
int dist[MX];
int dist2[MX];
vector<int> euler;
vector<int> tree;
int height[MX];
int first[MX];
int vis[MX];
int F1, F2;
int mx;
int color;

void reset(){
    FOR(i, MX){
        G[i].clear();
        vis[i] = 0;
    }
    euler.clear();
    tree.clear();
    color = 0;
}

void dfs(int n){
    vis[n] = color;
    euler.push_back(n);
    first[n] = euler.size() - 1;

    for (auto node : G[n]){
        int nxt = node.u;
        if(vis[nxt] != color){
            height[nxt] = height[n] + node.w;
            dist[nxt] = dist[n] + node.w;
            if (dist[nxt] > mx){
                mx = dist[nxt];
                F1 = nxt;
            }
            dfs(nxt);
            euler.push_back(n);
        }
    }
}

void dfs2(int n){
    vis[n] = color;

    for (auto node : G[n]){
        int nxt = node.u;
        if (vis[nxt] != color){
            dist2[nxt] = dist2[n] + node.w;
            if (dist2[nxt] > mx){
                mx = dist2[nxt];
                F2 = nxt;
            }
            dfs2(nxt);
        }
    }
}

void build(int node, int L, int R){
    if (L == R){
        tree[node] = euler[L];
        return;
    }
    int mid = (L+R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, L, mid);
    build(right, mid+1, R);
    tree[node] = (height[tree[left]] < height[tree[right]]) ? tree[left] : tree[right];
}

int query(int node, int L, int R, int l, int r){
    if (L > r || R < l) return -1;
    if (L >= l && R <= r) return tree[node];
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    int x = query(left, L, mid, l, r);
    int y = query(right, mid+1, R, l, r);
    if (x == -1) return y;
    if (y == -1) return x;
    return (height[x] < height[y]) ? x : y;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    FOR1(cs, T){
        reset();
        int n; scanf("%d", &n);
        for (int i = 1; i < n; i++){
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }

        ++color;
        mx = 0;
        height[0] = 1;
        dist[0] = 0;
        dfs(0);

        ++color;
        mx = 0;
        dist2[F1] = 0;
        dfs2(F1);


        int N = euler.size();
        tree.resize(4*N);
        build(1, 0, N-1);

        printf("Case %d:\n", cs);
        for (int i = 0; i < n; i++){
            int l = min(first[i], first[F1]);
            int r = max(first[i], first[F1]);
            int lca1 = query(1, 0, N-1, l, r);
            int ans1 = dist[i] + dist[F1] - 2 * dist[lca1];

            l = min(first[i], first[F2]);
            r = max(first[i], first[F2]);
            int lca2 = query(1, 0, N-1, l, r);
            int ans2 = dist[i] + dist[F2] - 2 * dist[lca2];

            printf("%d\n", max(ans1, ans2));

        }
    }
    return 0;
}
