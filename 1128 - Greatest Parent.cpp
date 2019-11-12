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
#define all(v)              v.begin(), v.end()

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

#define MX 100003
vector<int> G[MX];
int A[MX];
int up[MX][18];

void reset(){
    FOR(i, MX){
        G[i].clear();
    }
}

void dfs(int n, int p){
    up[n][0] = p;

    for (int i = 1; i < 18; i++){
        up[n][i] = up[up[n][i-1]][i-1];
    }

    for (auto v : G[n]){
        if (v == p) continue;
        dfs(v, n);
    }
}

int solve(int u, int v){

    for (int i = 17; i >= 0; i--){
        int parent = up[u][i];
        if (A[parent] >= v){
            u = parent;
        }
    }
    return u;
}

int main()
{
    //READ("input.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        reset();
        int n, q; scanf("%d%d", &n, &q);

        A[0] = 1;
        for (int i = 1; i < n; i++){
            int p, v; scanf("%d%d", &p, &v);
            A[i] = v;
            G[p].pb(i);
            G[i].pb(p);
        }

        dfs(0, 0);

        printf("Case %d:\n", cs);
        while(q--){
            int u, v; scanf("%d%d", &u, &v);
            int ans = solve(u, v);
            printf("%d\n", ans);
        }
    }

    return 0;
}


