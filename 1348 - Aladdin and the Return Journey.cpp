#include<bits/stdc++.h>
#define CLR(a)              memset(a, 0, sizeof(a))
#define SET(a, x)           memset(a, x, sizeof(a))
#define SORT(v)             sort(v.begin(), v.end())
#define REV(v)              reverse(v.begin(), v.end())
#define FOR(i, n)           for (int i=0; i<n; i++)
#define FOR1(i, n)          for (int i=1; i<=n; i++)
#define ROF(i, n)           for (int i=n-1; i>=0; i--)
#define ROF1(i, n)          for (int i=n; i>=1; i--)
#define LOOP(i, x, n)       for (int i=x; i<=n; i++)
#define READ(x)             freopen(x, "r", stdin);
#define WRITE(x)            freopen(x, "w", stdout);
#define fastIO()            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI                  acos(-1.0)
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second

using namespace std;

typedef long long              ll;
typedef unsigned long long     ull;
typedef vector<int>            vi;
typedef pair<int, int>         pii;
typedef pair<string, int>      psi;
typedef pair<char, int>        pci;

const double eps = 1e-9;

int fx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int fy[] = {0, 0, -1, 1, -1, 1, -1, 1};

int kx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky[] = {2, -2, 1, -1, 2, -2, 1, -1};

#define MX 30002
int A[MX];
vector<int> G[MX];
int height[MX];
int first[MX];
vector<int>euler;
vector<int>tree;

int Plus[MX];
int Minus[MX];
vector<int>seq;
vector<int>sumtree;

void reset(){
    euler.clear();
    tree.clear();
    seq.clear();
    sumtree.clear();
    FOR(i, MX) G[i].clear();
}

void dfs(int n, int p){
    euler.pb(n);
    first[n] = euler.size() - 1;

    seq.pb(A[n]);
    Plus[n] = seq.size() - 1;

    for (auto nxt : G[n]){
        if (nxt == p) continue;
        height[nxt] = height[n] + 1;
        dfs(nxt, n);
        euler.pb(n);
    }

    seq.pb(-A[n]);
    Minus[n] = seq.size() - 1;
}

void build(int node, int L, int R){
    if (L == R){
        tree[node] = euler[L];
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, L, mid);
    build(right, mid+1, R);
    tree[node] = (height[tree[left]] < height[tree[right]]) ? tree[left] : tree[right];
}

int queryLCA(int node, int L, int R, int l, int r){
    if (L > r || R < l) return -1;
    if (L >= l && R <= r) return tree[node];
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    int x = queryLCA(left, L, mid, l, r);
    int y = queryLCA(right, mid+1, R, l, r);
    if (x == -1) return y;
    if (y == -1) return x;
    return (height[x] < height[y]) ? x : y;
}

void buildSum(int node, int L, int R){
    if (L == R){
        sumtree[node] = seq[L];
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    buildSum(left, L, mid);
    buildSum(right, mid+1, R);
    sumtree[node] = sumtree[left] + sumtree[right];
}

int querySum(int node, int L, int R, int l, int r){
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return sumtree[node];
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    int x = querySum(left, L, mid, l, r);
    int y = querySum(right, mid+1, R, l, r);
    return x + y;
}

void updateSum(int node, int L, int R, int in, int v){
    if (L > in || R < in) return;
    if (L == R && L == in){
        sumtree[node] = v;
        return;
    }
    int mid = (L + R) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    updateSum(left, L, mid, in, v);
    updateSum(right, mid+1, R, in, v);
    sumtree[node] = sumtree[left] + sumtree[right];
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        reset();
        printf("Case %d:\n", cs);

        int n; scanf("%d", &n);
        FOR(i, n) scanf("%d", &A[i]);

        for (int i = 1; i < n; i++){
            int u, v; scanf("%d%d", &u, &v);
            G[u].pb(v);
            G[v].pb(u);
        }

        height[0] = 1;
        dfs(0, 0);

        int N = euler.size();
        int M = seq.size();

        tree.resize(4*N);
        sumtree.resize(4*M);

        build(1, 0, N-1);
        buildSum(1, 0, M-1);

        int q; scanf("%d", &q);
        while(q--){
            int d; scanf("%d", &d);
            if (d == 0){
                int u, v; scanf("%d%d", &u, &v);
                int l = min(first[u], first[v]);
                int r = max(first[u], first[v]);

                int lca = queryLCA(1, 0, N-1, l, r);

                int sum1 = querySum(1, 0, M-1, Plus[lca], Plus[u]);
                int sum2 = querySum(1, 0, M-1, Plus[lca], Plus[v]);

                int ans = sum1 + sum2 - A[lca];
                printf("%d\n", ans);
            }
            else{
                int node, val; scanf("%d%d", &node, &val);
                A[node] = val;
                updateSum(1, 0, M-1, Plus[node], val);
                updateSum(1, 0, M-1, Minus[node], -val);
            }
        }
    }
    return 0;
}


