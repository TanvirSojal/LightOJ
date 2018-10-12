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
 
int TLx[] = {0, -1, -1, 0};    int TLy[] = {-1, -1, 0, 0};
int TRx[] = {-1, -1, 0, 0};    int TRy[] = {0, 1, 1, 0};
int BLx[] = {0, 1, 1, 0};      int BLy[] = {-1, -1, 0, 0};
int BRx[] = {0, 1, 1, 0};      int BRy[] = {1, 1, 0, 0};
 
#define MAX 10010
 
struct edge{
    int u, v, w;
};
 
bool cmp(edge a, edge b){
    return a.w < b.w;
}
 
vector < edge > G;
vector < int > graph[MAX];
map < pii , bool > M;
map < pii , int > C;
 
int parent[MAX];
bool vis[MAX];
int n, m, airport, cnt;
ll cost, res;
 
int Find(int u){
    if (u==parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
 
void reset(){
    FOR(i, MAX){
        graph[i].clear();
        vis[i] = 0;
        parent[i] = i;
    }
    G.clear();
    cnt = 0;
    res = 0;
    M.clear();
    C.clear();
}
 
void MST(){
    cost = 0;
    sort(G.begin(), G.end(), cmp);
    FOR(i, m){
        int u = G[i].u;
        int v = G[i].v;
        int w = G[i].w;
        int p = Find(u);
        int q = Find(v);
        if (p!=q){
            pii x = mp(u, v);
            pii y = mp(v, u);
            M[x] = 1; M[y] = 1;
 
            parent[q] = p;
        }
    }
}
 
void dfs(int n){
    vis[n] = 1;
    int sz = graph[n].size();
    FOR(i, sz){
        int v = graph[n][i];
        pii x = mp(n, v);
        if (!vis[v]){
            int cst = C[x];
            if (M[x]){
                if (cst >= airport){
                    ++cnt;
                    res += airport;
                }
                else res += cst;
                dfs(v);
            }
        }
    }
}
 
 
 
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        reset();
        scanf("%d%d%d", &n, &m, &airport);
        FOR(i, m){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            pii x = mp(u, v);
            pii y = mp(v, u);
            if (!C[x]) C[x] = w;
            if (!C[y]) C[y] = w;
            C[x] = min(C[x], w);
            C[y] = min(C[y], w);
            G.pb({u, v, w});
            graph[u].pb(v);
            graph[v].pb(u);
        }
        MST();
 
        for (int i=1; i<=n; i++){
            if (!vis[i]){
                ++cnt;
                res += airport;
                dfs(i);
            }
        }
 
        printf("Case %d: %lld %d\n", cs, res, cnt);
    }
    return 0;
}
