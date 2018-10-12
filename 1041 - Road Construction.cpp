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
 
bool cmp( edge A, edge B ){
    return A.w < B.w;
}
 
vector < edge > G;
vector < int > graph[MAX];
map < string, int > M;
 
int parent[MAX];
int roads, cnt, counter;
bool vis[MAX];
 
void reset(){
    FOR(i, MAX){
        graph[i].clear();
        vis[i] = 0;
        parent[i] = i;
    }
    G.clear();
    cnt = 0;
    counter = 0;
    M.clear();
}
 
int Find(int x){
    if (x==parent[x]) return x;
    return parent[x] = Find(parent[x]);
}
 
void dfs(int n){
    vis[n] = 1;
    cnt++;
    int x = graph[n].size();
    FOR(i, x){
        int v = graph[n][i];
        if (!vis[v]) dfs(v);
    }
}
 
bool check(){
    dfs(1);
    return cnt == counter - 1;
}
 
ll MST(){
    ll cost = 0;
    sort(G.begin(), G.end(), cmp);
 
    FOR(i, roads){
        int u = G[i].u;
        int v = G[i].v;
        int w = G[i].w;
 
        int p = Find(u);
        int q = Find(v);
        if (p!=q){
            parent[q] = p;
            cost += w;
        }
    }
    return cost;
}
 
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int T; scanf("%d", &T);
    FOR1(cs, T){
        reset();
        scanf("%d", &roads);
        counter = 1;
        FOR(i, roads){
            string a, b;
            int w;
            cin >> a >> b;
            scanf("%d", &w);
            if (!M[a]) M[a] = counter++;
            if (!M[b]) M[b] = counter++;
 
            int u = M[a];
            int v = M[b];
 
            G.pb({u, v, w});
            graph[u].pb(v);
            graph[v].pb(u);
        }
 
        if (!check()){
            printf("Case %d: Impossible\n", cs);
            continue;
        }
 
        ll res = MST();
        printf("Case %d: %lld\n", cs, res);
    }
    return 0;
}
